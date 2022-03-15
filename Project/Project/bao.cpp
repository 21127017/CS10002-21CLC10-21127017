#include "project.h"

//----------COLORS----------//
void set_color(int code) {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code );
}

//-----------VIEW DESIGN SPACE-------------//
void view_student(profile *&pstudent, subjects *&ps, int &semester){
	cout << "\t\tSTUDENT PROFILE" << endl << endl;
	if (pstudent == NULL){
		cout << "No result." << endl << endl;
		system("cls");
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
	if (num == 0){
		//read file csv
		return;
	}
	//manual
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

void subject_edit(int num, subjects *&psubject, int &semester, int &year){
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
		if (choice == 1) subject_edit(1, psubject, semester, year);
	}
	if (num == 2){

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
		if (current -> id == tmp){
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
					else return;

			}
			strcpy(current -> classroom, auxilary);
			cout << "=> Import successfully!" << endl;
		} else 
			cout << "The id does not exits!!!" << endl;
		cout << "Do you want to add another student?" << endl;
		cout << "\t1. Sure!" << endl << "\t2. No." << endl << "\t=> Input:";
		int choice;
		cin >> choice;
		if (choice == 1) class_edit(1, pstudent, pclassid, semester);
	}
  	return;
}

void semester_edit(int num, subjects *&psubject, int &semester, int &year){
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
	subject_edit(0, psubject, semester, year);
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
	semester_edit(1, psubject, semester, year);
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
	cout << "0. Import file csv." << endl;
	cout << "1. Add student manual." << endl;
	cout << "2. Remove student." << endl;
	cout << "3. View list of student." << endl;
	cout << "\tInput: ";
	int num;
	cin >> num;
	if (num == 3) 
		view_student(pstudent, psubject, semester);
	else 
		student_edit(num, no, pstudent, semester, classroom, year);
	return;
}
void subject_function(subjects *&psubject, int &semester, int &year){
	//1. Add subject.
	//	subject_edit(1);
	//2. Remove subject.
	//	subject_edit(2);
	//3. View list of subject.
	//	view_subject();
	//4. Update mark.
	//	update_mark();

    int num;
    cin >> num;
    if (num != 3) subject_edit(num, psubject, semester, year);
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

	cout << "\t\t>> CLASS EDIT <<" << endl << endl;
	cout << "\t0. Create new class." << endl;
	cout << "\t1. Add student to class." << endl;
	cout << "\t2. Remove student from class" << endl;
	cout << "\t3. View list of class." << endl;
	cout << "\t4. View scoreboard of class." << endl;
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

void semester_function(subjects *&psubject, int &semester, int &year){
	//1. Create new semester (1 - 3).
	//	semester_edit(0);
	//2. View semester.
	//	view_semester();
	system("cls");
	cout << "\t1. Create new semester." << endl;
	cout << "\t2. View semester: " << endl;
	cout << "\t\tInput:";
    int num;
    cin >> num;
    if (num == 1) semester_edit(0, psubject, semester, year);

}

void year_function(profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year){
	//1. Create new school year.
	//	school_year_edit();
	//2. View school year.
	//	view_school_year();
	system("cls");
	cout <<"\t\t>> YEAR EDIT <<" << endl;
	cout << "\t1. Create new school year." << endl;
	cout << "\t2. View school year." << endl;
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
			semester_function(psubject, semester, year);
			break;
		case 3:
			class_function(pstudent, pclassid, semester);
			break;
		case 4:
			subject_function(psubject, semester, year);
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