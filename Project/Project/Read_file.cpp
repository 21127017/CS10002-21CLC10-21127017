#include "project.h"

//Read csv student
subject2 *newSubject(char *course_id) {
    subject2 *temp = new subject2;
    temp->course_id = new char[strlen(course_id) + 1];
    memcpy(temp->course_id, course_id, strlen(course_id) + 1);
    temp->score = 0;
    temp->next = nullptr;
    return temp;
}

profile *newProfile(char *classroom, int year, int enrolled_subject_no, subject2 *psub2, int no, int id,
    char *first_name, char *last_name, char *gender, long long social_id, date_of_birth dob) {
    profile *temp = new profile;

    temp->classroom = new char[strlen(classroom) + 1];
    memcpy(temp->classroom, classroom, strlen(classroom) + 1);

    temp->year = year;
    temp->enrolled_subject_no = enrolled_subject_no;
    temp->no = no;
    temp->id = id;
    temp->social_id = social_id;
    temp->dob = dob;

    temp->first_name = new char[strlen(first_name) + 1];
    memcpy(temp->first_name, first_name, strlen(first_name) + 1);
    temp->last_name = new char[strlen(last_name) + 1];
    memcpy(temp->last_name, last_name, strlen(last_name) + 1);
    temp->gender = new char[strlen(gender) + 1];
    memcpy(temp->gender, gender, strlen(gender) + 1);

    temp->psub2 = nullptr;
    if (enrolled_subject_no != 0) {
        subject2 *cur = temp->psub2;
        for (int i = 0; i < enrolled_subject_no; i++) {
            if (temp->psub2 != nullptr) {
                cur->next = newSubject(psub2[i].course_id);
                cur = cur->next;
            } else {
                temp->psub2 = newSubject(psub2[i].course_id);
                cur = temp->psub2;
            }
        }
    }
    temp->next = nullptr;
    return temp;
}

void read_csv_student(profile *&pstudent) {
    ifstream inp;
    char tmp[200];
    char a;
    inp.open("student.csv");

    profile *current = pstudent;

    char *classroom = nullptr;
    int year = 0;
    int enrolled_subject_no = 0;
    subject2 *psub2 = nullptr;
    int no = 0;
    int id = 0;
    char *first_name = nullptr;
    char *last_name = nullptr;
    char *gender = nullptr;
    long long social_id = 0;
    date_of_birth dob = { 0, 0, 0 };

    if (inp.is_open()) {
        while (!inp.eof()) {
            inp >> no >> a >> id >> a;

            inp.getline(tmp, 200, ',');
            classroom = new char[strlen(tmp) + 1];
            memcpy(classroom, tmp, strlen(tmp) + 1);

            inp >> year >> a;

            inp.getline(tmp, 200, ',');
            first_name = new char[strlen(tmp) + 1];
            memcpy(first_name, tmp, strlen(tmp) + 1);

            inp.getline(tmp, 200, ',');
            last_name = new char[strlen(tmp) + 1];
            memcpy(last_name, tmp, strlen(tmp) + 1);

            inp.getline(tmp, 200, ',');
            gender = new char[strlen(tmp) + 1];
            memcpy(gender, tmp, strlen(tmp) + 1);

            inp >> dob.day >> a >> dob.month >> a >> dob.year >> a >> social_id >> a;
            inp >> enrolled_subject_no >> a;

            if (enrolled_subject_no == 0) {
                psub2 = nullptr;
            } else {
                psub2 = new subject2[enrolled_subject_no];
                for (int i = 0; i < (enrolled_subject_no); i++) {
                    inp.getline(tmp, 200, ',');
                    psub2[i].course_id = new char[strlen(tmp) + 1];
                    memcpy(psub2[i].course_id, tmp, strlen(tmp) + 1);
                    psub2->next = 0;
                }
            }

            if (pstudent != nullptr) {
                current->next = newProfile(classroom, year, enrolled_subject_no, psub2, no, id, first_name, last_name, gender, social_id, dob);
                current = current->next;
            } else {
                pstudent = newProfile(classroom, year, enrolled_subject_no, psub2, no, id, first_name, last_name, gender, social_id, dob);
                current = pstudent;
            }

            if (enrolled_subject_no) {
                for (int i = 0; i < (enrolled_subject_no); i++)
                    delete[] psub2[i].course_id;
                delete[] psub2;
            }
            delete[] classroom;
            delete[] first_name;
            delete[] last_name;
            delete[] gender;
            inp.ignore();
        }
    }
    inp.close();
}

void write_csv_student(profile *pstudent) {
    if (pstudent == nullptr) return;
    profile *current = pstudent;
    subject2 *psub2 = nullptr;
    ofstream out;
    out.open("student.csv");
    while (current != nullptr) {
        out << current->no << "," << current->id << "," << current->classroom << "," << current->year << ",";
        out << current->first_name << "," << current->last_name << "," << current->gender << "," << current->dob.day << "," << current->dob.month << "," << current->dob.year << ",";
        out << current->social_id << "," << current->enrolled_subject_no << ",";
        psub2 = current->psub2;
        if (current->enrolled_subject_no != 0) {
            while (psub2 != nullptr) {
                out << psub2->course_id << ",";
                psub2 = psub2->next;
            }
        }
        out << endl;
        current = current->next;
    }
    out.close();
}

//read csv subject
subjects *NewSub(int year, int semester, char *course_id, char *teacher_name, int num_of_credits, char *name, int start, int end, int day_of_week, sessions session[2]) {
    subjects *temp = new subjects;
    temp->year = year;
    temp->semester = semester;

    temp->course_id = new char[strlen(course_id) + 1];
    memcpy(temp->course_id, course_id, strlen(course_id) + 1);

    temp->teacher_name = new char[strlen(teacher_name) + 1];
    memcpy(temp->teacher_name, teacher_name, strlen(teacher_name) + 1);

    temp->name = new char[strlen(name) + 1];
    memcpy(temp->name, name, strlen(name) + 1);

    temp->num_of_credits = num_of_credits;
    temp->start = start;
    temp->end = end;
    temp->day_of_week = day_of_week;
    for (int i = 0; i < 2; i++) {
        temp->session[i].day = new char[strlen(session[i].day) + 1];
        memcpy(temp->session[i].day, session[i].day, strlen(session[i].day) + 1);

        temp->session[i].hour_start = session[i].hour_start;
        temp->session[i].minute_start = session[i].minute_start;
    }

    temp->next = nullptr;

    return temp;
}

void read_csv_subject(subjects *&psubject) {
    ifstream inp;
    char tmp[200] = "";
    char a = ' ';
    inp.open("subject.csv");

    subjects *current = psubject;

    int year = 0;
    int semester = 0;
    char *course_id = nullptr;
    char *teacher_name = nullptr;
    int num_of_credits = 0;
    char *name = nullptr;
    int start = 0;
    int end = 0;
    int day_of_week = 0;
    sessions session[2] = { {nullptr, 0, 0}, {nullptr, 0, 0} };

    if (inp.is_open()) {
        while (!inp.eof()) {
            inp >> year >> a >> semester >> a;

            inp.getline(tmp, 200, ',');
            course_id = new char[strlen(tmp) + 1];
            memcpy(course_id, tmp, strlen(tmp) + 1);

            inp.getline(tmp, 200, ',');
            name = new char[strlen(tmp) + 1];
            memcpy(name, tmp, strlen(tmp) + 1);

            inp.getline(tmp, 200, ',');
            teacher_name = new char[strlen(tmp) + 1];
            memcpy(teacher_name, tmp, strlen(tmp) + 1);

            inp >> num_of_credits >> a >> start >> a >> end >> a >> day_of_week >> a;
            for (int i = 0; i < 2; i++) {
                inp.getline(tmp, 200, ',');
                session[i].day = new char[strlen(tmp) + 1];
                memcpy(session[i].day, tmp, strlen(tmp) + 1);

                inp >> session[i].hour_start >> a >> session[i].minute_start >> a;
            }
            if (psubject != nullptr) {
                current->next = NewSub(year, semester, course_id, teacher_name, num_of_credits, name, start, end, day_of_week, session);
                current = current->next;
            } else {
                psubject = NewSub(year, semester, course_id, teacher_name, num_of_credits, name, start, end, day_of_week, session);
                current = psubject;
            }
            delete[] course_id;
            delete[] name;
            delete[] teacher_name;
            for (int i = 0; i < 2; i++) {
                delete[] session[i].day;
            }
            inp.ignore();
        }
    }
    inp.close();
}

void write_csv_subject(subjects *psubject) {
    if (psubject == nullptr) return;
    subjects *current = psubject;

    ofstream out;
    out.open("subject.csv");
    while (current != nullptr) {
        out << current->year << "," << current->semester << ",";
        out << current->course_id << "," << current->name << "," << current->teacher_name << ",";
        out << current->num_of_credits << "," << current->start << "," << current->end << "," << current->day_of_week << ",";
        for (int i = 0; i < 2; i++) {
            out << current->session[i].day << "," << current->session[i].hour_start << "," << current->session[i].minute_start << ",";
        }
        out << endl;
        current = current->next;
    }
    out.close();
}

//read csv classroom 
classrooms *NewClass(char *classroom, int year, list_student *pid) {
    classrooms *temp = new classrooms;
    temp->classroom = new char[strlen(classroom) + 1];
    memcpy(temp->classroom, classroom, strlen(classroom) + 1);
    temp->year = year;
    temp->id_student = pid;
    temp->next = nullptr;
    return temp;
}
void read_csv_classroom(classrooms *&pclass) {
    ifstream inp;
    char tmp[200];
    char a;
    inp.open("class.csv");

    classrooms *current = pclass;

    char *classroom = nullptr;
    int year = 0;
    int id = 0;
    list_student *pid = nullptr, *cur = nullptr;

    if (inp.is_open()) {
        while (!inp.eof()) {
            pid = nullptr;
            cur = pid;
            inp.getline(tmp, 200, ',');
            classroom = new char[strlen(tmp) + 1];
            memcpy(classroom, tmp, strlen(tmp) + 1);

            inp >> year >> a;

            while (a != '.') {
                inp >> id >> a;
                if (pid != nullptr) {
                    cur->next = new list_student;
                    cur->next->id = id;
                    cur->next->next = nullptr;
                    cur = cur->next;
                } else {
                    pid = new list_student;
                    pid->id = id;
                    pid->next = nullptr;
                    cur = pid;
                }
            }
            if (pclass != nullptr) {
                current->next = NewClass(classroom, year, pid);
                current = current->next;
            } else {
                pclass = NewClass(classroom, year, pid);
                current = pclass;
            }
            delete[]classroom;
            inp.ignore();
        }
    }
    inp.close();
}

void write_csv_classroom(classrooms *pclass) {
    if (pclass == nullptr) return;
    ofstream out;
    out.open("class.csv");
    classrooms *current = pclass;
    list_student *cur = nullptr;
    while (current != nullptr) {
        out << current->classroom << "," << current->year << ",";
        cur = current->id_student;
        while (cur != nullptr) {
            out << cur->id;
            if (cur->next != nullptr) out << ",";
            else out << ".";
            cur = cur->next;
        }
        out << endl;
        current = current->next;
    }
    out.close();
}
