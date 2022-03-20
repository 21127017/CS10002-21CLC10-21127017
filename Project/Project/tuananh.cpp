#include "project.h"

void ShowCur(bool CursorVisibility) // Show / Hide the cursor.
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void read_cvs(profile* &pstudent)
{
	// csv format: no -> id -> classroom -> year 
	// -> names -> gender -> dob -> socialid -> no. of subjects -> subjects
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
		
		input >> pCur-> enrolled_subject_no;
		input.get(a);
		
		for (int i = 1; i <= pCur->enrolled_subject_no)
		{
			
		}
		
		delete tmp;
	}
	input.close();
	return;
}

// arguments: course id + student id + the heads of the student and subject lists.
// return true if it successfully added the course.
// return false if: invalid course/student id, subject already found.
bool enroll_course(char* enroll, int studentid, profile* &pstudent, subjects psubject) 
{	
	subjects* p_sub_cur = psubject;

	while(p_sub_cur != NULL)
	{
		if (!strcmp(enroll, p_sub_cur -> course_id));
			break;
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
		if (!strcmp(enroll, p_sub2_cur->course_id))
			return false;
		if (p_sub2_cur->next == NULL)
			break;
		p_sub2_cur = p_sub2_cur->next;
	}
	p_sub2_cur->next = new Node;
	p_sub2_cur->course_id = enroll;
	return true;
}

// arguments: course id + student id + the heads of the student and subject lists.
// return true if it successfully deletes something.
// return false if the id is wrong, the studentid isn't found, or the student isn't enrolled.
bool remove_course(char* remove, int studentid, profile* &pstudent, subjects* psubject)
{
	subjects* p_sub_cur = psubject;

	while(p_sub_cur != NULL)
	{
		if (!strcmp(remove, p_sub_cur -> course_id));
			break;
		p_sub_cur = p_sub_cur -> next;
	}
	
	if (p_sub_cur == NULL)
		return false;
	cout << endl;
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
	
	if (p_sub2_cur == NULL) return false;
	
	if(!strcmp(remove, p_sub2_cur->course_id))
	{
		subject2* temp = p_sub2_cur;
		p_sub2_cur = p_sub2_cur->next;
		p_pro_cur->psub2 = p_sub2_cur;
		delete temp;
		return true;
	}
	
	while (p_sub2_cur->next != NULL)
	{
		if (!strcmp(remove, p_sub2_cur->next->course_id))
		{
			subject2* temp = p_sub2_cur->next;
			p_sub2_cur = p_sub2_cur->next->next;
			delete temp;
			return true;
		}
		p_sub2_cur = p_sub2_cur->next;
	}
	
	return false;
}
