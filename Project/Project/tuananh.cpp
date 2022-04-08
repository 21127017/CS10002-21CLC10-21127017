#include "project.h"

void showcur(bool CursorVisibility) // Show / Hide the cursor.
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// someone help me debug this please. The function reads through 
// stuffs just fine until the subjects part, then it refuses to work
// bool read_csv_student(profile* &pstudent)
// {	
// 	char tmp[200];
// 	char a; 
// 	// csv format: no -> id -> classroom -> year 
// 	// -> names -> gender -> dob -> socialid -> no. of subjects -> subjects
// 	profile* pCur = pstudent;
// 	ifstream input;
// 	input.open("studentinfo.csv");
// 	if (input.is_open())
// 	{
// 		while(!input.eof())
// 		{
// 			/*if (pstudent == NULL)
// 			{
// 				pstudent = new profile;
// 				pCur = pstudent;
// 			}
// 			else
// 			{
// 				pCur->next = new profile;
// 				pCur = pCur->next;
// 			}*/
// 		      profile *pCur = new profile;
// 			// just a fodder to skip the "," in the csv
// 			input >> pCur -> no;
// 			input.get(a);
			
// 			input >> pCur -> id;
// 			input.get(a);
			
// 			input.getline(tmp, 200, ',');
// 			pCur -> classroom = new char[strlen(tmp) + 1];
// 			memcpy(pCur -> classroom, tmp, strlen(tmp) +1);
			
// 			input >> pCur -> year;
// 			input.get(a);
			
// 			input.getline(tmp, 200, ',');
// 			pCur -> first_name = new char[strlen(tmp) + 1];
// 			memcpy(pCur -> first_name, tmp, strlen(tmp) + 1);
			
// 			input.getline(tmp, 200, ',');
// 			pCur -> last_name = new char[strlen(tmp) + 1];
// 			memcpy(pCur -> last_name, tmp, strlen(tmp) + 1);
			
// 			input.getline(tmp, 200, ',');
// 			pCur -> gender = new char[strlen(tmp) + 1];
// 			memcpy(pCur -> gender, tmp, strlen(tmp) + 1);
			
// 			input >> pCur -> dob.day;
// 			input.get(a);
// 			input >> pCur -> dob.month;
// 			input.get(a);
// 			input >> pCur -> dob.year;
// 			input.get(a);
			
// 			input >> pCur -> social_id;
// 			input.get(a);
			
// 			input >> pCur-> enrolled_subject_no;
// 			input.get(a);
			
// 			int n = pCur -> enrolled_subject_no;
// 			for (int i = 1; i <= n; i++)
// 			{
// 				if (i != n)
// 					input.getline(tmp, 200, ',');
// 				else
// 					input.getline(tmp, 200, '\n');
					
// 				subject2 *pNew = new subject2;
// 				memcpy(pNew -> course_id, tmp, strlen(tmp) + 1);
// 				pNew -> next = pCur -> psub2;
// 				pCur -> psub2 = pNew;
// 			}
// 			if (pstudent == NULL)
// 			    pstudent = pCur;
// 			else
// 			    pstudent -> next = pCur;
// 		}
// 		input.close();
// 		return true;
// 	}
// 	else
// 		return false;
// }

void read_csv_student(profile *&pstudent) {
	ifstream inp;
	char tmp[200];
	char a;
	inp.open("studentinfo.csv");
	profile *current = nullptr;
	if (inp.is_open()) {
		while (!inp.eof()) {
			if (!pstudent) {
				pstudent = new profile;
				current = pstudent;
			} else {
				current->next = new profile;
				current = current->next;
			}
			inp >> current->no >> a >> current->id >> a;

			inp.getline(tmp, 200, ',');
			current->classroom = new char[strlen(tmp) + 1];
			memcpy(current->classroom, tmp, strlen(tmp) + 1);

			inp >> a >> current->year >> a;

			inp.getline(tmp, 200, ',');
			current->first_name = new char[strlen(tmp) + 1];
			memcpy(current->first_name, tmp, strlen(tmp) + 1);

			inp.getline(tmp, 200, ',');
			current->last_name = new char[strlen(tmp) + 1];
			memcpy(current->last_name, tmp, strlen(tmp) + 1);

			inp.getline(tmp, 200, ',');
			current->gender = new char[strlen(tmp) + 1];
			memcpy(current->gender, tmp, strlen(tmp) + 1);

			inp >> current->dob.day >> a >> current->dob.month >> a >> current->dob.year >> a >> current->social_id >> a;
			inp >> current->enrolled_subject_no >> a;

			int num = current->enrolled_subject_no;
			if (!num) {
				current->psub2 = nullptr;
				continue;
			} else {
				current->psub2 = new subject2;
				subject2 *cur = current->psub2;

				for (int i = 0; i < (num - 1); i++) {
					inp.getline(tmp, 200, ',');
					cur->course_id = new char[strlen(tmp) + 1];
					memcpy(cur->course_id, tmp, strlen(tmp) + 1);
					cur->next = new subject2;
					cur = cur->next;
				}

				inp.getline(tmp, 200, ',');
				cur->course_id = new char[strlen(tmp) + 1];
				memcpy(cur->course_id, tmp, strlen(tmp) + 1);
				inp.ignore();
			}

			current->next = nullptr;
		}
	}
	inp.close();
}

void output_to_csv_student(profile* &pstudent)
{
	if (pstudent == NULL) return;
	ofstream output;
	output.open("studentinfo.csv", ios::out);
	profile* pCur = pstudent;
	while (pCur != NULL)
	{
		output << pCur->no << ","
		       << pCur->id << ","
  		       << pCur->classroom << ","
		       << pCur->year << ","
		       << pCur->first_name << ","
		       << pCur->last_name << ","
		       << pCur->gender << ","
		       << pCur->dob.day << ","
		       << pCur->dob.month << ","
		       << pCur->dob.year << ","
		       << pCur->social_id << ","
		       << pCur->enrolled_subject_no << ",";
		subject2  *p_cursub_2 = pCur->psub2;
		while (p_cursub_2 != NULL)
		{
			output << p_cursub_2->course_id;
			if (p_cursub_2->next != NULL)
				output << ",";
			else
				output << endl;
			p_cursub_2 = p_cursub_2->next;
		}
		pCur = pCur->next;
	}
	output.close();
	return;
}

void output_to_csv_staff(staff* pstaff)
{
	if (pstaff == NULL) return;
	ofstream output;
	output.open("staffinfo.csv", ios::out);
	staff* pCur = pstaff;
	while (pCur != NULL)
	{
		output << pCur->name << ","
			   << pCur->dob.day << ","
			   << pCur->dob.month << ","
			   << pCur->dob.year << ","
			   << pCur->role << ","
			   << pCur->gender << ","
			   << pCur->social_id << ",";
		output << endl;
		pCur = pCur->next;
	}
	output.close();
	return;
}
// arguments: course id + student id + the heads of the student and subject lists.
// return true if it successfully added the course.
// return false if: invalid course/student id, subject already found.
//---> Update: Because this function have many case, so we change the bool to int.
void enroll_course(int semester, int year, int studentid, profile* &pstudent, subjects *psubject, int &res) 
{	
	char *enroll = new char[100];
	//show_enroll_course(psubject, semester, year, enroll);
	subjects *p_sub_cur = psubject;

	while(p_sub_cur != NULL)
	{
		if (!strcmp(enroll, p_sub_cur -> course_id))
			break;
		p_sub_cur = p_sub_cur -> next;
	}
	
	if (p_sub_cur == NULL){
		delete[] enroll;
		res  = 1;
		return;
	}
	
	profile* p_pro_cur = pstudent;
	while(p_pro_cur != NULL)
	{
		if (studentid == p_pro_cur->id)
			break;
		p_pro_cur = p_pro_cur -> next;
	}
	
	if (p_pro_cur == NULL){
		delete[] enroll;
		res =  2;
		return;
	}
	
	subject2* p_sub2_cur = p_pro_cur->psub2;
	
	while (p_sub2_cur != NULL)
	{
		if (!strcmp(enroll, p_sub2_cur->course_id)){
			delete[] enroll;
			res = 3;
			return;
		}
		if (p_sub2_cur->next == NULL)
			break;
		p_sub2_cur = p_sub2_cur->next;
	}
	subject2 *newnode = new subject2;
	newnode -> course_id = new char[strlen(enroll) + 2];
	memcpy(newnode -> course_id, enroll, strlen(enroll) + 1);
	newnode -> score = 0;
	if (p_sub2_cur == NULL)
		p_sub2_cur = newnode;
	else
		p_sub2_cur -> next = newnode;
	res = 4;
	return;
}

void design_enroll_course(int semester, int year, int studentid, profile *&pstudent, subjects *&psubject) {
	int res;
	enroll_course(semester, year, studentid, pstudent, psubject, res);
	/*
	1: "Can't found the id."
	2: ...truong hop nay khong xay ra duoc :v
	3: "You are already in this course."
	4: "Register successfully!!!!"
	*/
	switch (res) {
		case 1:
			cout << "Can't found the id.";
			break;
		case 2:
			//
			break;
		case 3:
			cout << "You are already in this course.";
			break;
		case 4:
			cout << "Register successfully!!!!";
			break;
		default:
			break;
	}

	// "Do you want to register another course?" -Yes/No
	return;
}

// arguments: course id + student id + the heads of the student and subject lists.
// return true if it successfully deletes something.
// return false if the id is wrong, the studentid isn't found, or the student isn't enrolled.
bool remove_course(char* remove, int studentid, profile* &pstudent, subjects* psubject)
{
	subjects* p_sub_cur = psubject;

	while(p_sub_cur != NULL)
	{
		if (!strcmp(remove, p_sub_cur->course_id))
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

void output_to_csv_subject(subjects* psubject)
{
	if (psubject == NULL)
		return;
	ofstream output;
	output.open("subjectinfo.csv", ios::out);
	subjects* pCur = psubject;
	while (pCur != NULL)
	{
		output << pCur->year << ","
			   << pCur->semester << ","
			   << pCur->course_id << ","
			   << pCur->teacher_name << ","
			   << pCur->num_of_credits << ","
			   << pCur->name << ","
			   << pCur->start << ","
			   << pCur->end << ","
			   << pCur->session[0].day << ","
			   << pCur->session[0].hour_start << ","
			   << pCur->session[0].minute_start << ","
			   << pCur->session[1].day << ","
			   << pCur->session[1].hour_start << ","
			   << pCur->session[1].minute_start;
		output << endl;
		pCur = pCur->next;
	}
	output.close();
	return;
}

//void output_to_csv_class(classrooms *pclass)
//{
//	classrooms* pCur;
//	ofstream output;
//	output.open("classinfo.csv", ios::out);
//	while (pCur != NULL)
//	{
//		output << pCur->classroom;
//		list_student* pCurList = pCur->id_student;
//		while (pCur -> id_student != NULL)
//			output  << "," << pCur->id_student->id;
//		output << endl;
//	}
//	output.close();
//}
