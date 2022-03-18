#include "project.h"
using namespace std;

void read_cvs(profile* &pstudent)
{
	// csv format: no -> id -> classroom -> year 
	// -> names -> gender -> dob -> socialid -> subjects
	profile* pCur = pstudent;
	ifstream input;
	input.open("studentinfo.cvs");
	while(input.good() and !input.eof())
	{
		if (pCur == NULL)
		{
			pstudent = new profile;
			pCur = pstudent;
		}
		char* tmp[200];
		char a; // just a fodder to skip the "," in the csv
		input >> pCur -> no;
		input.get(a);
		
		input >> pCur -> id;
		input.get(a);
		
		input.getline(tmp, 200, ',');
		pCur -> classroom = new char[strlen(tmp) + 1];
		memcpy(pCur -> classroom, tmp, strlen(tmp) +1);
		
		input >> pCur -> year;
		input.get(a);
		
		input.getline(tmp, 200, ',');
		pCur -> first_name = new char[strlen(tmp) + 1];
		memcpy(pCur -> first_name, tmp, strlen(tmp) + 1);
		
		input.getline(tmp, 200, ',');
		pCur -> last_name = new char[strlen(tmp) + 1];
		memcpy(pCur -> last_name, tmp, strlen(tmp) + 1);
		
		input.getline(tmp, 200, ',');
		pCur -> gender = new char[strlen(tmp) + 1];
		memcpy(pCur -> gender, tmp, strlen(tmp) + 1);
		
		input >> pCur -> social_id;
		input.get(a);
		pCur = pCur -> next;
		
		// dunno how to input subjects yet since different
		// students have different numbers of subjects 
	}
	input.close();
	return;
}

// ask the user to enter the id, then pass that id and that student's id to the function
// this will return true if it found a valid id and the user hasn't already enrolled in this course
// return false if: invalid course/student id, subject already found
bool enroll_course(char* enroll, int studentid, profile* &pstudent, subjects psubject) 
{	
	subjects* p_sub_cur = psubject;

	while(p_sub_cur != NULL)
	{
		if (strstr(enroll, p_sub_cur -> course_id) != NULL);
		p_sub_cur = p_sub_cur -> next;
	}
	
	if (p_sub_cur == NULL)
		return false;
	
	profile* p_pro_cur = pstudent;
	while(p_pro_cur != NULL)
	{
		if (studentid == p_pro_cur->id)
			break;
		p_pro_cur = p_pro_cur -> next;
	}
	
	if (p_pro_cur == NULL)
		return false;
	
	
	subject2* p_sub2_cur = p_pro_cur->psub2;
	while (p_sub2_cur != NULL)
	{
		if (strstr(enroll, p_sub2_cur->course_id) != NULL)
			return false;
		if (p_sub2_cur->next == NULL)
			break;
		p_sub2_cur = p_sub2_cur->next;
	}
	p_sub2_cur->next = new Node;
	p_sub2_cur->course_id = enroll;
	return true;
}

void remove_course()
{
	
}
