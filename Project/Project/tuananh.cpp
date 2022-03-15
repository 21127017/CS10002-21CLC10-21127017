#include "project.h"
using namespace std;

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
		// subjects have different numbers of subjects 
	}
	input.close();
	return;
}

void enroll_course()
{
	
}

void remove_course()
{
	
}
