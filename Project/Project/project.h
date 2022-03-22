#ifndef _project_h_
#define _project_h_

#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <iomanip>	
#include "conio.h"

using namespace std;

struct login_information {
	int role; //role: 1_academic staff, 2_student, 3_unidentifined account
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
	int score;
	subject2 *next;
};

struct profile {
	char *classroom;
	int year;
	int enrolled_subject_no;
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

struct staff{
	char *name;
	date_of_birth dob;
	char *role;
	char *gender;
	long long social_id;
	staff *next;
};

//----------COLORS----------//
void set_color(int code);

//-----------STORE DATA-----------//

//-----------CONDITION BARRIER-----------//

//-----------VIEW DESIGN SPACE-----------//
int getkey();

void GoTo(SHORT posX, SHORT posY);

void designSquare(SHORT posX, SHORT posY, int height, int width, char *content, int color1, int color2);

void view_space();

void view_loginboard();

void view_student();

void view_subject();

void view_class();

void view_semester();

void view_school_year();

void view_list_of_course();

void view_scoreboard();

void announcement(char *content, bool title, int &num);

//-----------EDIT SPACE-----------//
void student_edit(int num, int &no, profile *&pstudent, int &semester, int &classroom, int &year);

void subject_edit(int num, profile *&pstudent, subjects *&psubject, int &semester, int &year);

void class_edit(int num, profile *&pstudent, classrooms *&pclassid, int &semester);

void semester_edit(int num, profile *&pstudent, subjects *&psubject, int &semester, int &year);

void school_year_edit(profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year);

//-----------STAFF MEMBER FUNCTION SPACE-----------//
void undergraduate_function(int &no, profile *&pstudent, subjects *&psubject, int &semester, int &classroom, int &year);

void print_undergraduate_function(/*int &no, profile *&pstudent, subjects *&psubject, int &semester, int &classroom, int &year*/);

void subject_function(profile *&pstudent, subjects *&psubject, int &semester, int &year);

void print_subject_function(/*profile *&pstudent, subjects *&psubject, int &semester, int &year*/);

void class_function(profile *&pstudent, classrooms *&pclassid, int &semester);

void print_class_function(/*profile *&pstudent, classrooms *&pclassid, int &semester*/);

void semester_function(profile *&pstudent, subjects *&psubject, int &semester, int &year);

void print_semester_function(/*profile *&pstudent, subjects *&psubject, int &semester, int &year*/);

void year_function(profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year);

void print_year_function(/*profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year*/);

//-----------STUDENT FUNCTION SPACE-----------//
//tuan + ham nhap file cvs + tao file csv
void enroll_course();

void remove_course();


//----------ACCOUNT------------//
void login(int &role, int &id_profile);

void logout();

void changePassword(const int &changed_id);

bool inputNewPass(char *&oldpassword);

//-----------INPUT SPACE-----------//
void print_option_1(int &num);

void make_choice_1(int &choice, profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &no, int &classroom, int &semester, int &year, int &id_profile);

//void print_option_2(choice);

void make_choice_2(int &choice, int &id_profile);

//-----------DELETE LINKED LIST-----------//
void delete_student(profile *&pstudent);
void delete_subject(subjects *&psubject);

#endif
