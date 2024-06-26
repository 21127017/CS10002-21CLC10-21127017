#ifndef _project_h_
#define _project_h_

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>
#include <iomanip>	
#include "conio.h"

#define sc(a) static_cast<char>(a)

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
	int year;
	list_student *id_student;
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

//----------SHOW CUR----------//
void showcur(bool CursorVisibility);

//----------COLORS----------//
void set_color(int code);

//-----------STORE DATA-----------//
subject2 *newSubject(char *course_id, int score);

profile *newProfile(char *classroom, int year, int enrolled_subject_no, subject2 *psub2, int no, int id,
	char *first_name, char *last_name, char *gender, long long social_id, date_of_birth dob);

void read_csv_student(profile *&pstudent);

void write_csv_student(profile *pstudent);

subjects *NewSub(int year, int semester, char *course_id, char *teacher_name, int num_of_credits, char *name, int start, int end, int day_of_week, sessions session[2]);

void read_csv_subject(subjects *&psubject);

void write_csv_subject(subjects *psubject);

void read_csv_classroom(classrooms *&pclass);

void write_csv_classroom(classrooms *pclass);

void export_to_file(profile *pstudent, subjects *psubject);

//-----------CONDITION BARRIER-----------//

//-----------VIEW DESIGN SPACE-----------//
int getkey();

void GoTo(SHORT posX, SHORT posY);
#define gt GoTo

void designSquare(SHORT posX, SHORT posY, int height, int width, char *content, int color1, int color2);

void view_space();

char *int_to_char(long long x);

void draw_button(int value, int maxlist);

void print_information(char *x1, char *x2, int x, int y, int color);

void view_profile(int user_id, profile *p, int role);//

void view_student_scoreboard(int id_student, profile *pstudent, subjects *psubject);//

void view_student_enroll_course(int id_student, profile *pstudent, subjects *psubject);//

void view_scoreboard_of_course(char *id_course, profile *pstudent);

void view_list_of_course(subjects *psubject, profile *pstudent, int semester, int year);//

void view_student_in_class(char *classid, profile *pstudent);//

void view_student_in_course(char *id_course, profile *p);//

void view_list_of_class(classrooms *pclassid, profile *pstudent);//

void view_loginboard();

void view_student();

void view_subject();

void view_class();

void view_semester();

void view_school_year();

void view_list_of_course();

void view_scoreboard();

void announcement(char *content, bool yesno, int &num, int title);

void exitProgram();

void view_guide(/*int role*/);

void print_course_function(int &choice);

//-----------DELETE LINKED LIST-----------//
void delete_student(profile *&pstudent);
void delete_subject(subjects *&psubject);
void delete_class(classrooms *&pclassid);

//-----------EDIT SPACE-----------//
void student_edit(int num, int &no, profile *&pstudent, int &semester, int &classroom, int &year);

void subject_edit(int num, profile *&pstudent, subjects *&psubject, int &semester, int &year);

void class_edit(int num, profile *&pstudent, classrooms *&pclassid, int &semester, int &year);

void semester_edit(int num, profile *&pstudent, subjects *&psubject, int &semester, int &year);

void school_year_edit(profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year);

//-----------STAFF MEMBER FUNCTION SPACE-----------//
void print_undergraduate_function(int &choice/*int &no, profile *&pstudent, subjects *&psubject, int &semester, int &classroom, int &year*/);
void undergraduate_function(int &no, profile *&pstudent, subjects *&psubject, int &semester, int &classroom, int &year);

void print_subject_function(int &choice/*profile *&pstudent, subjects *&psubject, int &semester, int &year*/);
void subject_function(profile *&pstudent, subjects *&psubject, int &semester, int &year);

void print_class_function(int &choice/*profile *&pstudent, classrooms *&pclassid, int &semester*/);
void class_function(profile *&pstudent, classrooms *&pclassid, int &semester, int &year);

void print_semester_function(int &choice/*profile *&pstudent, subjects *&psubject, int &semester, int &year*/);
void semester_function(profile *&pstudent, subjects *&psubject, int &semester, int &year);

void print_year_function(int &choice/*profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year*/);
void year_function(profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year);
//-----------STUDENT FUNCTION SPACE-----------//
//tuan + ham nhap file cvs + tao file csv

void show_enroll_course(subjects *p, int semester, int year, char *&auxilary);
void enroll_course(int semester, int year, int studentid, profile* &pstudent, subjects *psubject, int &res);
void design_enroll_course(int semester, int year, int studentid, profile *&pstudent, subjects *&psubject);
bool remove_course(char* remove, int studentid, profile* &pstudent, subjects* psubject);
void design_remove(int studentid, profile *&pstudent, subjects *psubject);


//----------ACCOUNT------------//
void login(int &role, int &id_profile);

bool logout();

void changePassword(int changed_id, int role);

int inputNewPass(char oldpassword[200]);

//-----------INPUT SPACE-----------//
void print_option_1(int &choice);

void make_choice_1(int &choice, profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &no, int &classroom, int &semester, int &year, int &user_id);

void print_option_2(int &choice);

void make_choice_2(int &choice, profile *&pstudent, subjects *&psubject, int &semester, int &year, int &user_id);

#endif
