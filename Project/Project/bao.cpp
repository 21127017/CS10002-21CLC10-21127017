#include "project.h"

//--------EDIT SPACE----------------//
void student_edit(int num, int &no, profile *&pstudent, int &semester,
                  int &classroom, int &year) {
  // you can't add one more student because it's not the 1st semester of the
  // year
  if (num == 0) {
    // read file csv
    return;
  }
  // manual
  profile *current = pstudent;
  while (current->next != NULL) current = current->next;

  profile *newnode = new profile;
  char auxilary[200];

  current->no = ++no;
  cout << "\tStudent no: " << no << endl;

  cout << "\tStudent Id: ";
  cin >> current->id;

  cout << "\tFirst name: ";
  cin.ignore();
  cin.getline(auxilary, 200);
  newnode->first_name = new char[strlen(auxilary) + 1];
  strcpy(newnode->first_name, auxilary);

  cout << "\tLast name: ";
  cin.ignore();
  cin.getline(auxilary, 200);
  newnode->last_name = new char[strlen(auxilary) + 1];
  strcpy(newnode->last_name, auxilary);

  cout << "\tClass: ";
  cin.ignore();
  cin.getline(auxilary, 200);
  newnode->classroom = new char[strlen(auxilary) + 1];
  strcpy(newnode->classroom, auxilary);

  cout << "\tGender: ";
  cin.ignore();
  cin.getline(auxilary, 200);
  newnode->gender = new char[strlen(auxilary) + 1];
  strcpy(newnode->gender, auxilary);

  cout << "\tSocial Id: ";
  cin >> newnode->social_id;

  cout << "\tDate of birth:" << endl;
  cout << "\t\tYear: ";
  cin >> newnode->dob.year;
  cout << "\t\tMonth: ";
  cin >> newnode->dob.month;
  cout << "\t\tDay: ";
  cin >> newnode->dob.day;

  newnode->next = NULL;
  if (pstudent == NULL)
    pstudent = newnode;
  else
    current->next = newnode;
}

void subject_edit(int num, subjects *&psubject, int &semester, int &year) {
  system("cls");
  if (num == 0) {
    subjects *current = psubject;
    while (current->next != NULL) current = current->next;

    subjects *newnode = new subjects;
    newnode->year = year;
    newnode->semester = semester;
    char auxilary[200];

    cout << "Course name: ";
    cin.ignore();
    cin.getline(auxilary, 200);
    newnode->name = new char[strlen(auxilary) + 1];
    strcpy(newnode->name, auxilary);

    cout << "Id course:";
    cin.ignore();
    cin.getline(auxilary, 200);
    newnode->course_id = new char[(strlen(auxilary) + 1)];
    strcpy(newnode->course_id, auxilary);

    cout << "Teacher: ";
    cin.ignore();
    cin.getline(auxilary, 200);
    newnode->teacher_name = new char[strlen(auxilary) + 1];
    strcpy(newnode->teacher_name, auxilary);

    cout << "Num of creadits: ";
    cin >> newnode->num_of_credits;

    cout << "Input the session of this course: " << endl;
    for (int i = 0; i < 2; ++i) {
      cout << "\tSession " << i << ":" << endl;
      cout << "\t\tDay(MON / TUE / WED / THU / FRI / SAT): ";
      cin.ignore();
      cin.getline(auxilary, 200);
      newnode->session[i].day = new char[strlen(auxilary) + 1];
      strcpy(newnode->session[i].day, auxilary);
      cout << "\t\tHour start:";
      cin >> newnode->session[i].hour_start;
      cout << "\t\tMinute start:";
      cin >> newnode->session[i].minute_start;
    }

    newnode->next = NULL;
    if (psubject == NULL)
      psubject = newnode;
    else
      current->next = newnode;
  } else {
    // show list of subject;

    int pos;  // mon hoc can xoa (xac dinh bang vi tri)
    cin >> pos;
    subjects *current = psubject;
    int tmp = 0;
    while (pos != tmp - 1) {
      current = current->next;
      ++tmp;
    }
    subjects *auxilary = current->next;
    current->next = current->next->next;
    delete auxilary;
  }
  return;
}

void class_edit(int num, classrooms *&pclassid) {
  // you can't create new class because it's not the 1st semester of the year
  classrooms *current = pclassid;
  classrooms *newnode = new classrooms;
  while (current->next != NULL) current = current->next;
  char auxilary[200];
  cin.ignore();
  cin.getline(auxilary, 200);
  newnode->classroom = new char[strlen(auxilary) + 1];
  strcpy(newnode->classroom, auxilary);
  newnode->next = NULL;
  if (current == NULL)
    pclassid = newnode;
  else
    current->next = newnode;
  return;
}

void semester_edit(int num, subjects *&psubject, int &semester, int &year) {
  if (semester == 3) {
    cout << "You can't create the new one because there are only 3 semester in "
            "a year."
         << endl;
    cout << "Create new year if you want to go to next semester." << endl;
    return;
  }
  ++semester;
  subject_edit(0, psubject, semester, year);
}

void school_year_edit(subjects *&psubject, int &classroom, int &semester,
                      int &year) {
  ++year;
  classroom = -1;
  class_edit(0);
  semester = -1;
  semester_edit(1, psubject, semester, year);
}

//----------STAFF MEMBER FUNCTION SPACE-------------//
void undergraduate_function() {
  // 1. Import file csv.
  //	student_edit(0);
  // 2. Add student manual.
  //	student_edit(1);
  // 3. Remove student manual.
  //	student_edit(2);
  // 4. View list of student.
  //	view_student();
}
void subject_function(subjects *&psubject, int &semester, int &year) {
  // 1. Add subject.
  //	subject_edit(1);
  // 2. Remove subject.
  //	subject_edit(2);
  // 3. View list of subject.
  //	view_subject();
  int num;
  cin >> num;
  if (num != 3)
    subject_edit(num, psubject, semester, year);
  else
    view_subject();
}

void class_function() {
  // 1. Create new class (1 - 10).
  //	class_edit(0, NULL);
  // 2. Add student to class.
  //	class_edit(1);
  // 3. Remove student from class.
  //	class_edit(2);
  // 4. View list of class.
  //	view_class();

  int num;
  cin >> num;
  if (num == 4)
    view_class();
  else
    class_edit(num);
}

void semester_function(subjects *&psubject, int &semester, int &year) {
  // 1. Create new semester (1 - 3).
  //	semester_edit(0);
  // 2. View semester.
  //	view_semester();

  int num;
  cin >> num;
  if (num == 1) semester_edit(0, psubject, semester, year);
}

void year_function(subjects *&psubject, int &classroom, int &semester,
                   int &year) {
  // 1. Create new school year.
  //	school_year_edit();
  // 2. View school year.
  //	view_school_year();
  int num;
  cin >> num;
  if (num == 1)
    school_year_edit(psubject, classroom, semester, year);
  else
    view_school_year();
}

//--------STUDENT FUNCTION SPACE-------------//
void enroll_course() {
  // show list of course
}

void remove_course() {
  // show list of couse
}

//----------ACCOUNT------------//
void login(int &roll) {}

void logout() {}

//---------INPUT SPACE--------//
void print_option_1() {
  system("cls");
  cout << "Choose your action:" << endl;
  cout << "\t0. Log out." << endl;
  cout << "\t1. Year." << endl;
  cout << "\t2. Semester." << endl;
  cout << "\t3. Class." << endl;
  cout << "\t4. Subject." << endl;
  cout << "\t5. Undergraduate." << endl;
  return;
}

void make_choice_1(int &choice, profile *&pstudent, subjects *&psubject,
                   classrooms *&pclassid, int &no, int &classroom,
                   int &semester, int &year) {
  switch (choice) {
    case 0:
      logout();
      break;
    case 1:
      year_function(psubject, classroom, semester, year);
      break;
    case 2:
      semester_function(psubject, semester, year);
      break;
    case 3:
      class_function();
      break;
    case 4:
      subject_function(psubject, semester, year);
      break;
    case 5:
      undergraduate_function();
      break;
  }
  return;
}

void print_option_2() {
  system("cls");
  cout << "Choose your action: " << endl;
  cout << "\t0. Log out." << endl;
  cout << "\t1. Enroll Course." << endl;
  cout << "\t2. Remove Course." << endl;
  cout << "\t3. View list of course." << endl;
  cout << "\t4. View scoreboard." << endl;
  return;
}

void make_choice_2(int &choice) {
  switch (choice) {
    case 0:
      logout();
      break;
    case 1:
      enroll_course();
      break;
    case 2:
      remove_course();
      break;
    case 3:
      view_list_of_course();
      break;
    case 4:
      view_scoreboard();
      break;
  }
  return;
}