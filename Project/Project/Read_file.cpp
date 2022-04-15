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

//read csv subject
