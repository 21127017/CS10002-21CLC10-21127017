#include "project.h"

//-----------VIEW DESIGN SPACE-------------//
void view_student(profile *&pstudent, subjects *&ps, int &semester){
	system("cls");
	cout << "\t\tSTUDENT PROFILE" << endl << endl;
	if (pstudent == NULL){
		cout << "No result." << endl << endl;
		system("pause");
		return;
	}
	profile *p = pstudent;
	while (p != NULL){
		cout << "\tNo: " << p -> no << endl;
		cout << "\tName: " << p -> first_name << " " << p-> last_name << endl;
		cout << "\tID student: " << p -> id << endl;
		cout << "\tClass:" << p -> classroom << endl;
		cout << "\tSocial ID: " << p -> social_id << endl;
		cout << "\tGender: " << p -> gender << endl;
		cout << "\tDate of birth: " << p -> dob.day <<  "/" << p -> dob.month << "/" << p -> dob.year << endl;
		cout << "\tYear join to school: " << p -> year << endl;
		cout << "\tSubject enroll in semester " << semester << ":" << endl;
		if (p -> psub2 == NULL)
			cout << "\t\tNo result." << endl;
		else {
			subject2 *current = p -> psub2;
			while (current != NULL){
				subjects *auxilary = ps;
				while (auxilary != NULL){
					if (auxilary -> course_id == current -> course_id) break;
					auxilary = auxilary -> next;
				}
				if (auxilary -> course_id == current -> course_id){
					cout << "\t\tName: " << auxilary -> name << endl;
				}
				current = current -> next;
			}
		}
		p = p -> next;
		cout << endl;
	}
	system("pause");
}

void view_subject(){
	
}

void view_class(){

}

void view_semester(){
	
}

void view_school_year(){
	
}

void view_list_of_course(){

}

void view_scoreboard(){

}



//--------EDIT SPACE----------------//
void student_edit(int num, int &no, profile *&pstudent, int &semester, int &classroom, int &year){
	system("cls");
	if (num == 1){
		//read file csv
		return;
	}
	//manual
	if (num == 2){
		cout << "\t\t>> ADD STUDENT MANUAL <<" << endl << endl;
		profile *newnode = new profile;
		char auxilary[200];

		newnode -> no = ++no;
		cout << "\tStudent no: " << no << endl;
		newnode -> psub2 = NULL;

		cout << "\tStudent Id: ";
		cin >> newnode -> id;

		cout << "\tFirst name: ";
		cin.ignore();
		cin.getline(auxilary, 200);
		newnode -> first_name = new char[strlen(auxilary) + 1];
		strcpy(newnode -> first_name, auxilary);

		cout << "\tLast name: ";
		//cin.ignore();
		cin.getline(auxilary, 200);
		newnode -> last_name = new char[strlen(auxilary) + 1];
		strcpy(newnode -> last_name, auxilary);

		cout << "\tGender: ";
		//cin.ignore();
		cin.getline(auxilary, 200);
		newnode -> gender = new char[strlen(auxilary) + 1];
		strcpy(newnode -> gender, auxilary);

		cout << "\tSocial Id: ";
		cin >> newnode -> social_id;

		cout << "\tDate of birth:" << endl;
		cout << "\t\tYear: ";
		cin >> newnode -> dob.year;
		cout << "\t\tMonth: ";
		cin >> newnode -> dob.month;
		cout << "\t\tDay: ";
		cin >> newnode -> dob.day;

		newnode -> next = NULL;
		if (pstudent == NULL) 
			pstudent = newnode;
		else {
			profile *current = pstudent;
			while (current -> next != NULL) current = current -> next;
			current -> next = newnode;
		}
	}
	if (num == 3){
		cout << "\t\t>> REMOVE STUDENT <<" << endl << endl;
		if (pstudent == NULL){
			cout << "\tNo result...." << endl << endl;
			cout << "\tDo you want to input again?" << endl;
			cout << "\t1. Yes" << endl << "\t2. No" << endl << "\tInput: ";
			int choice;
			cin >> choice;
			if (choice == 1) student_edit(3, no, pstudent, semester, classroom, year);
			return;
		}
		cout << "\tInput student id: ";
		int student_id;
		cin >> student_id;
		profile *cur = pstudent;
		if (cur -> id == student_id){
			pstudent = pstudent -> next;
			delete cur;
		} else {
			profile *auxilary;
			while (cur -> next != NULL && cur -> next -> id != student_id)
				cur = cur -> next;
			if (cur -> next == NULL){
				cout << "\tCan't find this id. " << endl << endl;
				cout << "\tDo you want to input again?" << endl;
				cout << "\t1. Yes" << endl << "\t2. No" << endl << "\tInput: ";
				int choice;
				cin >> choice;
				if (choice == 1) student_edit(3, no, pstudent, semester, classroom, year);
				return;
			}
			auxilary = cur -> next;
			cur -> next = cur -> next -> next;
			delete auxilary;
		}
		cout << "\t=> Delete complete!" << endl << endl;
		cout << "\tDo you want to remove another student?" << endl;
		cout << "\t1. Yes" << endl << "\t2. No" << endl << "\tInput: ";
		int choice;
		cin >> choice;
		if (choice == 1) student_edit(3, no, pstudent, semester, classroom, year);
	}
}

void subject_edit(int num, profile *&pstudent, subjects *&psubject, int &semester, int &year){
	system("cls");
	if (num == 1){
		cout << "\t\t>> CREATE NEW COURSE << " << endl;
		subjects *newnode = new subjects;
		newnode -> year = year;
		newnode -> semester = semester;
		char auxilary[200];

		cout << "Course name: ";
		cin.ignore();
		cin.getline(auxilary, 200);
		newnode -> name = new char[strlen(auxilary) + 1];
		strcpy(newnode -> name, auxilary);

		cout << "Id course:";
		cin.ignore();
		cin.getline(auxilary, 200);
		newnode -> course_id = new char[(strlen(auxilary) + 1)];
		strcpy(newnode -> course_id, auxilary);

		cout << "Teacher: ";
		cin.ignore();
		cin.getline(auxilary, 200);
		newnode -> teacher_name = new char[strlen(auxilary) + 1];
		strcpy(newnode -> teacher_name, auxilary);

		cout << "Num of creadits: ";
		cin >> newnode -> num_of_credits;

		cout << "Input the session of this course: " << endl;
		for (int i = 0; i < 2; ++i){
			cout << "\tSession " << i << ":" << endl;
			cout << "\t\tDay(MON / TUE / WED / THU / FRI / SAT): ";
			cin.ignore();
			cin.getline(auxilary, 200);
			newnode -> session[i].day = new char[strlen(auxilary) + 1];
			strcpy(newnode -> session[i].day, auxilary);
			cout << "\t\tHour start:";
			cin >> newnode -> session[i].hour_start;
			cout << "\t\tMinute start:";
			cin >> newnode -> session[i].minute_start;
		}

		newnode -> next = NULL;
		if (psubject == NULL) 
			psubject = newnode;
		else {
			subjects *current = psubject;
			while (current -> next != NULL) current = current -> next;
			current -> next = newnode;
		}
		cout << "=> Created successfully!" << endl;
		cout << "Do you want to create another one?";
		cout << "\t1. Sure!" << endl << "\t2. No." << endl << "\t=> Input:";
		int choice;
		cin >> choice;
		if (choice == 1) subject_edit(1, pstudent, psubject, semester, year);
	}
	if (num == 2){
		//show list of course in this semester
		cout << "\tInput the id of course you want to delete: ";
		char auxilary[200];
		cin.ignore();
		cin.getline(auxilary, 200);
		subjects *current = psubject;
		if (strcmp(current -> course_id, auxilary) == 0){
			psubject = psubject -> next;
			delete current;
		}
		while (current -> next != NULL && strcmp(current -> next -> course_id, auxilary) != 0)
			current = current -> next;
		if (current -> next == NULL){
			cout << "\tThe id was not exits." << endl;
			system("pause");
		} else {
			subjects *tmp = current -> next;
			current -> next = current -> next -> next;
			delete tmp;
			cout << "\tDelete course complete!" << endl;
			system("pause");
		}
	}
	if (num == 4){
		//Show list of course.
		cout << "\tChoose a course you want to update score." << endl << "\tInput: ";
		char auxilary[200];
		cin.ignore();
		cin.getline(auxilary, 200);
		subjects *current = psubject;
		while (current != NULL && strcmp(current -> course_id, auxilary) != 0)
			current = current -> next;
		if (current == NULL){
			cout << "\tThe id was not exits." << endl;
			cout << "\tDo you want to input again?" << endl;
			cout << "\t1. Yes" << endl << "\t2. No" << endl;
			cout << "\tInput:";
			int choice;
			cin >> choice;
			if (choice == 1) subject_edit(4, pstudent, psubject, semester, year);
			return;
		} else {
			system("cls");
			int count = 0;
			cout << "\t\t>> INPUT SCORE <<";
			profile *cur1 = pstudent;
			while (cur1 != NULL){
				subject2 *cur2 = cur1 -> psub2;
				while (cur2 != NULL && strcmp(cur2 -> course_id, auxilary) != 0)
					cur2 = cur2 -> next;
				if (cur2 != NULL){
					cout << "\tID: " << cur1 -> id << endl;
					cout << "\tScore: ";
					cin >> cur2 -> score;
					++count;
				}
				cur1 = cur1 -> next;
			}
			if (count == 0) cout << "\tNo result." << endl;
		}
	}
	if (num == 5){
		cout << "\t\t>> UPDATE SCORE <<" << endl << endl;
		if (pstudent == NULL || psubject == NULL){
			cout << "Error. You need to create data first." << endl
			system("pause");
			return;
		}
		cout << "Input student id you want to update:";
		int student_id;
		cin >> student_id;
		profile *cur = pstudent;
		while (cur != NULL && cur -> id != student_id)
			cur = cur -> next;
		if (cur == NULL){
			cout << "\tThe id was not exits." << endl << endl;
			cout << "\tDo you want to input again?" << endl;
			cout << "\t1. Yes" << endl << "\t2. No" << endl;
			cout << "\tInput:";
			int choice;
			cin >> choice;
			if (choice == 1) subject_edit(5, pstudent, psubject, semester, year);
			return;
		}
		cout << "\tOld score: " << cur -> score << endl;
		cout << "\tInput new score: ";
		cin >> cur -> score;
		cout << "\t=> Update successfully!" << endl << endl;
		cout << "\tDo you want to continue?" << endl;
		cout << "\t1. Yes" << endl << "\t2. No" << endl;
		cout << "\tInput:";
		int choice;
		cin >> choice;
		if (choice == 1) subject_edit(5, pstudent, psubject, semester, year);
	}
	if (num == 6){
		cout << "\t\t>> UPDATE COURSE INFORMATION <<" << endl << endl;
		if (psubject == NULL){
			cout << "\tCan't updated. You have no course to update." << endl;
			system("pause");
			return;
		}
		//show list of course
		cout << "Input id of course you want to delete:";
		cahr auxilary[200];
		cin.ignore;
		cin.getline(auxilary);
		subjects *cur = psubject;
		while (cur != NULL && strcmp(cur -> course_id, auxilary) != 0)
			cur = cur -> next;
		if (cur == NULL){
			cout << "\tThe id was not exits." << endl << endl;
			cout << "\tDo you want to input again?" << endl;
			cout << "\t1. Yes" << endl << "\t2. No" << endl;
			cout << "\tInput:";
			int choice;
			cin >> choice;
			if (choice == 1) subject_edit(6, pstudent, psubject, semester, year);
			return;
		}
		//--------------------sadjkasnfjksdnfjsdfkjsdfkjsdbfkjdsjfk
	}
	return;
}

void class_edit(int num, profile *&pstudent, classrooms *&pclassid, int &semester){ 
	system("cls");
	if (num == 0){
		cout << ">> CREATE NEW CLASS <<" << endl;
		if (semester != 1){
			cout << "you can't create new class because it's not the 1st semester of the year." << endl;
			system("pause");
			return;
		}
		cout << "\t Name of class: ";
	  	classrooms *newnode = new classrooms;
	  	char auxilary[200];
	  	cin.ignore();
	  	cin.getline(auxilary, 200);
	  	newnode->classroom = new char[strlen(auxilary) + 1];
	  	strcpy_s(newnode->classroom, strlen(auxilary) + 1, auxilary);
	  	newnode->next = NULL;
	  	if (pclassid == NULL)
	    	pclassid = newnode;
	  	else{
	  		classrooms *current = pclassid;
	  		while (current->next != NULL) current = current->next;
	    	current->next = newnode;
	  	}
	  	cout << "Do you want to create another class?" << endl;
	  	cout << "\t1. Sure!" << endl << "\t2.No." << endl << "\tInput: ";
	  	int choice;
	  	cin >> choice;
	  	if (choice == 1) class_edit(0, pstudent, pclassid, semester);
	}
	if (num == 2){
		//remove
		cout << ">> REMOVE CLASS <<" << endl;
		if (pclassid == NULL){
			cout << "You can't use remove function becasue there is zero classroom in this semester." << endl;
			system("pause");
			return;
		}
	}
	if  (num == 1){
		cout << "\t\t>> ADD STUDENT TO CLASS <<" << endl;
		if (pclassid == NULL){
			cout << "There is no class in this semester." << endl;
			system("pause");
			return;
		}
		if (pstudent == NULL){
			cout << "You don't have any student to add to class." << endl;
			system("pause");
			return;
		}
		cout << "Input student id: ";
		int tmp;
		cin >> tmp;
		profile *current = pstudent;
		while (current != NULL){
			if (current -> id == tmp) break;
			current = current -> next;
		}
		if (current != NULL && current -> id == tmp){
			char auxilary[200];
			cout << "Input student classroom:";
			cin.ignore();
			cin.getline(auxilary, 200);
			classrooms *pclass = pclassid;
			while (pclass != NULL){
				if (strcmp(pclass -> classroom, auxilary) == 0)
					break;
				pclass = pclass -> next;
			}
			if (pclass == NULL){
				cout << "=> Import failed!" << endl;
				cout << "The class was not exits." << endl;
				cout << "Do you want to add again?" << endl;
				cout << "\t1. Sure!" << endl << "\t2. No." << endl << "\t=> Input:";
				int choice;
				cin >> choice;
				if (choice == 1) class_edit(1, pstudent, pclassid, semester);
				return;
			}
			strcpy(current -> classroom, auxilary);
			cout << "=> Import successfully!" << endl;
		} else {
			cout << "The id does not exits!!!" << endl;
			cout << "Do you want to input again?" << endl;
			cout << "\t1. Sure!" << endl << "\t2. No." << endl << "\t=> Input:";
			int choice;
			cin >> choice;
			if (choice == 1) class_edit(1, pstudent, pclassid, semester);
			return;
		}
		cout << "Do you want to add another student?" << endl;
		cout << "\t1. Sure!" << endl << "\t2. No." << endl << "\t=> Input:";
		int choice;
		cin >> choice;
		if (choice == 1) class_edit(1, pstudent, pclassid, semester);
	}
  	return;
}

void semester_edit(int num, profile *&pstudent, subjects *&psubject, int &semester, int &year){
	system("cls");
	cout << "\t\t>> CREATE NEW SEMESTER << " << endl;
	if (semester == 0 && year == 0){
		cout << "Error!" << endl;
		cout << "Please create new school year first." << endl;
		system("pause");
		return;
	}
	if (semester == 3){
		cout << "You can't create the new one because there are only 3 semester in a year." << endl;
		cout << "Create new year if you want to go to next semester." << endl;
		system("pause");
		return;
	}
	cout << "Do you want to create new semester?" << endl;
	if (semester != 0) 
		cout << "(Notice that all class in semester " << semester << " can't operate anymore)." << endl;
	cout << "1. I'm sure with that." << endl;
	cout << "2. No, i changed my mind." << endl;
	cout << "Input: ";
	int choice;
	cin >> choice;
	if (choice == 2) return;
	++semester;
	cout << "=> Created successfully!" << endl;
	cout << "\tNow is Year: " << year << " Semester: " << semester << endl;
	cout << "\tLet's create new course for this semester!" << endl << endl;
	system("pause");
	subject_edit(0, pstudent, psubject, semester, year);
}

void school_year_edit(profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year){
	system("cls");
	cout << "\t\t>> CREATE NEW SCHOOL YEAR << " << endl << endl;
	if (semester != 3 && year != 0){
		cout << "Now is just semester " << semester << "/3. You can't create new one." << endl << endl;
		system("pause");
		return;
	}
	cout << "Do you want to create new school year?" << endl;
	cout << "1. I'm sure with that." << endl;
	cout << "2. No, i changed my mind." << endl;
	cout << "Input: ";
	int choice;
	cin >> choice;
	if (choice == 2) return;
	++year;
	classroom = 0;
	cout << endl;
	cout << "\tYou have successfully initialized new school year!" << endl;
	cout << "\tNow you need to create new class and new semester." << endl << endl;
	system("pause");
	semester = 0;
	semester_edit(1, pstudent, psubject, semester, year);
	class_edit(0, pstudent, pclassid, semester);
}

//----------STAFF MEMBER FUNCTION SPACE-------------//
void undergraduate_function(int &no, profile *&pstudent, subjects *&psubject, int &semester, int &classroom, int &year){
	//1. Import file csv.
	//	student_edit(0);
	//2. Add student manual.
	//	student_edit(1);
	//3. Remove student manual.
	//	student_edit(2);
	//4. View list of student.
	//	view_student(pstudent, psubject, semester);
	system("cls");
	cout << "\t\t>> STUDENT EDIT <<" << endl << endl;
	cout << "\t1. Import file csv." << endl;
	cout << "\t2. Add student manual." << endl;
	cout << "\t3. Remove student." << endl;
	cout << "\t4. View list of student." << endl << endl;
	cout << "\tInput: ";
	int num;
	cin >> num;
	if (num == 4) 
		view_student(pstudent, psubject, semester);
	else 
		student_edit(num, no, pstudent, semester, classroom, year);
	return;
}
void subject_function(profile *&pstudent, subjects *&psubject, int &semester, int &year){
	//1. Add subject.
	//	subject_edit(1);
	//2. Remove subject.
	//	subject_edit(2);
	//3. View list of subject.
	//	view_subject();
	//4. Update mark.
	//	subject_edit(4);
	//5. Update course information.
	//  subject_edit(5);
	cout << "\t1. Add new course." << endl;
	cout << "\t2. Remove course." << endl;
	cout << "\t3. View list of course." << endl;
	cout << "\t4. Update mark" << endl;
	cout << "\t5. Update course information." << endl << endl;
    int num;
    cin >> num;
    if (num != 3) subject_edit(num, pstudent, psubject, semester, year);
        else view_subject();
}

void class_function(profile *&pstudent, classrooms *&pclassid, int &semester){
	//1. Create new class (1 - 10).
	//	class_edit(0, NULL);
	//2. Add student to class.
	//	class_edit(1);
	//3. Remove student from class.
	//	class_edit(2);
	//4. View list of class.
	//	view_class();
	//5. View scoreboard of class.
	//	view_scorebard(class);
	system("cls");
	cout << "\t\t>> CLASS EDIT <<" << endl << endl;
	cout << "\t0. Create new class." << endl;
	cout << "\t1. Add student to class." << endl;
	cout << "\t2. Remove student from class" << endl;
	cout << "\t3. View list of class." << endl;
	cout << "\t4. View scoreboard of class." << endl << endl;
    int num;
    cout << "\tInput: ";
    cin >> num;
    if (num == 3) 
    	view_class();
    else if (num == 4) 
    	view_scoreboard(); 
    else 
    	class_edit(num, pstudent, pclassid, semester);
}

void semester_function(profile *&pstudent, subjects *&psubject, int &semester, int &year){
	//1. Create new semester (1 - 3).
	//	semester_edit(0);
	//2. View semester.
	//	view_semester();
	system("cls");
	cout << "\t1. Create new semester." << endl;
	cout << "\t2. View semester: " << endl << endl;
	cout << "\tInput:";
    int num;
    cin >> num;
    if (num == 1) semester_edit(0, pstudent, psubject, semester, year);

}

void year_function(profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year){
	//1. Create new school year.
	//	school_year_edit();
	//2. View school year.
	//	view_school_year();
	system("cls");
	cout <<"\t\t>> YEAR EDIT <<" << endl;
	cout << "\t1. Create new school year." << endl;
	cout << "\t2. View school year." << endl << endl;
	cout << "\tInput: ";
    int num;
    cin >> num;
    if (num == 1) school_year_edit(pstudent, psubject, pclassid, classroom, semester, year);
        else view_school_year();
}

//--------STUDENT FUNCTION SPACE-------------//
void enroll_course(){
	//show list of course
}

void remove_course(){
	//show list of couse
}


//----------ACCOUNT------------//
void login(int &roll, int &id_profile){

}

void logout(){

}

//-----DELETE SPACE-----//
void delete_student(profile *&pstudent){
	/*
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
	*/
	profile *auxilary;
	subject2 *tmp;
	while (pstudent != NULL){
		auxilary = pstudent;
		pstudent = pstudent -> next;
		subject2 *cur = auxilary -> psub2;
		while (cur != NULL){
			tmp = cur;
			cur = cur -> next;
			delete[] tmp -> course_id;
			delete tmp;
		}
		delete[] auxilary -> first_name;
		delete[] auxilary -> last_name;
		delete[] auxilary -> gender;
		delete[] auxilary -> classroom;
		delete auxilary;
	}
	return;
}

void delete_subject(subjects *&psubject){
	/* 
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
	*/
	subjects *auxilary;
	while (psubject != NULL){
		auxilary = psubject;
		psubject = psubject -> next;
		delete[] auxilary -> session[0].day;
		delete[] auxilary -> session[1].day;
		delete[] auxilary -> name;
		delete[] auxilary -> course_id;
		delete[] auxilary -> teacher_name;
		delete auxilary;
	}

}

//---------INPUT SPACE--------//
void print_option_1(){
	system("cls");
	cout << "Choose your action:" << endl;
	cout << "\t0. Log out." << endl;
	cout << "\t1. Year." << endl;
	cout << "\t2. Semester." << endl;
	cout << "\t3. Class." << endl;
	cout << "\t4. Subject." << endl;
	cout << "\t5. Student." << endl;
	cout << "\t6. View my profile." << endl;
	cout << "\t7. Exit program." << endl;
	return;
}

void make_choice_1(int &choice, profile *&pstudent, subjects *&psubject, 
	classrooms *&pclassid, int &no, int &classroom, int &semester, int &year, int &id_profile){
	switch (choice){
		case 0:
			logout();
			break;
		case 1:
			year_function(pstudent, psubject, pclassid, classroom, semester, year);
			break;
		case 2:
			semester_function(pstudent, psubject, semester, year);
			break;
		case 3:
			class_function(pstudent, pclassid, semester);
			break;
		case 4:
			subject_function(pstudent, psubject, semester, year);
			break;
		case 5:
			undergraduate_function(no, pstudent, psubject, semester, classroom, year);
			break;
		case 6:
			//view profile
			break;
		case 7:
			break;
	}
	return;
}

void print_option_2(){
	system("cls");
	cout << "Choose your action: " << endl;
	cout << "\t0. Log out." << endl;
	cout << "\t1. Enroll Course." << endl;
	cout << "\t2. Remove Course." << endl;
	cout << "\t3. View list of course." << endl;
	cout << "\t4. View scoreboard." << endl;
	cout << "\t5. View my profile." << endl;
	cout << "\t6. Exit program." << endl;
	return;
}

void make_choice_2(int &choice, int &id_profile){
	switch (choice){
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
		case 5: 
			//View profile;
			break;
		case 6: 
			break;
	}
	return;
}