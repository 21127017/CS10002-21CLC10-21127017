#ifndef _project_h_
#define _project_h_

#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <iomanip>	

using namespace std;

struct login_information {
	int role; //role: 1_academic staff, 2_student, 3_undefined account
	char *username;
	char *password;
	int user_id;
};

struct date_of_birth {
	int year, month, day;
};

struct sessions {
	char *day;
	int hour_start;
	int minute_start;
};

struct list_student {
	int id;
	list_student *next;
};

struct classrooms {
	char *classroom;
	list_student *id_student = new list_student;
	classrooms *next;
};

struct subjects {
	int year;
	int semester;
	char *course_id;
	char *teacher_name;
	int num_of_credits;
	int maximum = 50;
	char *name;
	int start;
	int end;
	int day_of_week;
	sessions session[2];
	subjects *next;
};

struct subject2 {
	char *course_id;
	subject2 *next;
};

struct profile {
	char *classroom;
	int year;
	subject2 *psub2;
	int no;
	int id;
	char *first_name;
	char *last_name;
	char *gender;
	long long social_id;
	date_of_birth dob;
	profile *next;
};

//-----------VIEW DESIGN SPACE-------------//
void GoTo(SHORT posX, SHORT posY);

void view_space();

void view_loginboard();

void view_student();

void view_subject();

void view_class();

void view_semester();

void view_school_year();

void view_list_of_course();

void view_scoreboard();

//--------EDIT SPACE----------------//
void student_edit(int num, int &no, profile *&pstudent, int &semester, int &classroom, int &year);

void subject_edit(int num, subjects *&psubject, int &semester, int &year);

void class_edit(int num);

void semester_edit(int num, subjects *&psubject, int &semester, int &year);

void school_year_edit(subjects *&psubject, int &classroom, int &semester, int &year);

//----------STAFF MEMBER FUNCTION SPACE-------------//
void undergraduate_function();

void subject_function(subjects *&psubject, int &semester, int &year);

void class_function();

void semester_function(subjects *&psubject, int &semester, int &year);

void year_function(subjects *&psubject, int &classroom, int &semester, int &year);

//--------STUDENT FUNCTION SPACE-------------//
//tuan + ham nhap file cvs + tao file csv
void enroll_course();

void remove_course();


//----------ACCOUNT------------//
void login(int &role);

void logout();

//---------INPUT SPACE--------//
void print_option_1();

void make_choice_1(int &choice, profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &no, int &classroom, int &semester, int &year);

void print_option_2();

void make_choice_2(int &choice);

#endif