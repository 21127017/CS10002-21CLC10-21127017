#include "project.h"
using std::cout;
using std::cin;
/*
void set_space(char tmp[], int space){
	char gap[200] = "";
	space -= strlen(tmp);
	for (int i = 0; i < space / 2; ++i)
		strcat_s(gap, " ");
	strcat_s(tmp, gap);
	strcat_s(gap, tmp);
	if (space % 2) strcat_s(gap, " ");
}
*/

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
		cout << "\t1. No: " << p -> no << endl;
		cout << "\t2. Name: " << p -> first_name << " " << p-> last_name << endl;
		cout << "\t3. ID student: " << p -> id << endl;
		cout << "\t4. Class:" << p -> classroom << endl;
		cout << "\t5. Social ID: " << p -> social_id << endl;
		cout << "\t6. Gender: " << p -> gender << endl;
		cout << "\t7. Date of birth: " << p -> dob.day <<  "/" << p -> dob.month << "/" << p -> dob.year << endl;
		cout << "\t8. Year join to school: " << p -> year << endl;
		cout << "\t9. Subject enroll in semester " << semester << ":";
		if (p -> psub2 == NULL)
			cout << "No result." << endl;
		else {
			subject2 *current = p -> psub2;
			while (current != NULL){
				subjects *auxilary = ps;
				while (auxilary != NULL){
					if (strcmp(auxilary -> course_id,  current -> course_id) == 0){
						cout << "\t\t+ " << auxilary -> name << endl;
						break;
					}
					auxilary = auxilary -> next;
				}
				current = current -> next;
			}
		}
		p = p -> next;
		cout << endl;
	}
	system("pause");
}

void view_subject(subjects *p){
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
	system("cls");
	cout << "\t\t>> COURSE INFORMATION <<" << endl << endl;
	if (p == NULL){
		cout << "\tNo result!";
		return;
	}
	cout << "\t1. Course name: " <<  p -> name << endl;
	cout << "\t2. Course id: " << p -> course_id << endl;
	cout << "\t3. Month start: " << p -> start << endl;
	cout << "\t4. Month end: " << p -> end << endl;
	cout << "\t5. Teacher: " << p -> teacher_name << endl;
	cout << "\t6. Day of week: " << p -> day_of_week << endl;
	cout << "\t7. Session: " << endl;
	for (int i = 0; i < 2; ++i)
		cout << "\t\t+ " << p -> session[i].day << " " << p -> session[i].hour_start << ":" << p -> session[i].minute_start << endl;
	cout << "\t8. Credit: " << p -> num_of_credits << endl;
	cout << "\t9. Num of enrool: " << p -> maximum << "/50" << endl << endl;
	cout << "\t(Create in year " << p -> year << " semester " << p -> semester << ")" << endl;
	system("pause");
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
	view_space();
	char temp[200];
	if (num == 1) {
		//read file csv
		return;
	}
	//manual
	if (num == 2) {
		GoTo(36, 1);
		cout << ">> ADD STUDENT MANUAL <<";
		if (!year || !semester) {
			int num2 = 0;
			memcpy(temp, "You need to create year and semester first.", 44);
			announcement(temp, 0, num2, -1);
			return;
		}
		profile *newnode = new profile;
		char auxilary[100];

		newnode->no = ++no;
		memcpy(temp, "Student no:   ", 15);
		designSquare(25, 9, 3, 19, temp, 7, 7);

		memcpy(temp, "Student ID:           ", 23);
		designSquare(46, 9, 3, 27, temp, 7, 7);
		
		memcpy(temp, "First name:                                ", 44);
		designSquare(25, 12, 3, 48, temp, 7, 7);

		memcpy(temp, "Last name:                                 ", 44);
		designSquare(25, 15, 3, 48, temp, 7, 7);

		memcpy(temp, "Gender:    ", 12);
		designSquare(25, 18, 3, 16, temp, 7, 7);

		memcpy(temp, "Social Id:             ", 24);
		designSquare(43, 18, 3, 30, temp, 7, 7);

		memcpy(temp, "Date of birth: Year:      Month:    Day:   ", 44);
		designSquare(25, 21, 3, 48, temp, 7, 7);

		GoTo(39, 10);
		cout << no;
		newnode->psub2 = NULL;

		GoTo(60, 10);
		cin >> newnode->id;

		newnode->classroom = new char[10];
		strcpy_s(newnode->classroom, 8, "Unknown");

		cin.ignore();
		GoTo(39, 13);
		cin.getline(auxilary, 50);
		newnode->first_name = new char[strlen(auxilary) + 1];
		strcpy_s(newnode->first_name, strlen(auxilary) + 1, auxilary);

		//cin.ignore();
		GoTo(38, 16);
		cin.getline(auxilary, 50);
		newnode->last_name = new char[strlen(auxilary) + 1];
		strcpy_s(newnode->last_name, strlen(auxilary) + 1, auxilary);

		//cin.ignore();
		GoTo(35, 19);
		cin.getline(auxilary, 50);
		newnode->gender = new char[strlen(auxilary) + 1];
		strcpy_s(newnode->gender, strlen(auxilary) + 1, auxilary);

		GoTo(57, 19);
		cin >> newnode->social_id;

		GoTo(48, 22);
		cin >> newnode->dob.year;

		GoTo(60, 22);
		cin >> newnode->dob.month;

		GoTo(68, 22);
		cin >> newnode->dob.day;

		newnode->next = NULL;
		if (pstudent == NULL)
			pstudent = newnode;
		else {
			profile *current = pstudent;
			while (current->next != NULL) current = current->next;
			current->next = newnode;
		}
		memcpy(temp, "Do you want to input again?", 28);
		int choice = 0;
		announcement(temp, 1, choice, 1);
		if (choice == 1) student_edit(2, no, pstudent, semester, classroom, year);
		return;
	}
	if (num == 3) {
		GoTo(39, 1);
		cout << ">> REMOVE STUDENT <<";
		if (pstudent == NULL) {
			memcpy(temp, "No result! Do you want to input again?", 39);
			int choice = 0;
			announcement(temp, 1, choice, -1);
			if (choice == 1) student_edit(3, no, pstudent, semester, classroom, year);
			return;
		}
		memcpy(temp, "Input student ID:           ", 29);
		designSquare(32, 15, 3, 33, temp, 7, 7);
		GoTo(52, 16);
		int student_id;
		cin >> student_id;
		profile *cur = pstudent;
		if (cur->id == student_id) {
			pstudent = pstudent->next;
			delete cur;
		} else {
			profile *auxilary;
			while (cur->next != NULL && cur->next->id != student_id)
				cur = cur->next;
			if (cur->next == NULL) {
				memcpy(temp, "ID doesn't exist. Do you want to input again?", 46);
				int choice = 0;
				announcement(temp, 1, choice, -1);
				if (choice == 1) student_edit(3, no, pstudent, semester, classroom, year);
				return;
			}
			auxilary = cur->next;
			cur->next = cur->next->next;
			delete auxilary;
		}
		memcpy(temp, "Do you want to remove another student?", 39);
		int choice;
		announcement(temp, 1, choice, 1);
		if (choice == 1) student_edit(3, no, pstudent, semester, classroom, year);
	}
}

void subject_edit(int num, profile *&pstudent, subjects *&psubject, int &semester, int &year){
	view_space();
	char temp[200];
	int choice = 0;
	if (num == 1){
		GoTo(37, 1);
		cout << ">> CREATE NEW COURSE <<";
		subjects *newnode = new subjects;
		newnode->year = year;
		newnode->semester = semester;
		char auxilary[50];

		memcpy(temp, "Course name:                              ", 43);
		designSquare(13, 8, 3, 46, temp, 7, 7);

		memcpy(temp, "Id course:            ", 23);
		designSquare(59, 8, 3, 26, temp, 7, 7);

		memcpy(temp, "Teacher:                                                            ", 69);
		designSquare(13, 11, 3, 72, temp, 7, 7);

		memcpy(temp, "Num of credits:              ", 30);
		designSquare(13, 14, 3, 33, temp, 7, 7);

		memcpy(temp, "Month start:          end:         ", 36);
		designSquare(46, 14, 3, 39, temp, 7, 7);

		designSquare(13, 17, 7, 72, 0, 7, 7);
		GoTo(15, 18);
		cout << "Input the session of this course: ";

		GoTo(28, 9); // input course name
		cin.ignore();
		cin.getline(auxilary, 50);
		newnode->name = new char[strlen(auxilary) + 1];
		strcpy_s(newnode->name, strlen(auxilary) + 1, auxilary);

		GoTo(72, 9); //input id course
		cin.getline(auxilary, 50);
		newnode->course_id = new char[(strlen(auxilary) + 1)];
		strcpy_s(newnode->course_id, strlen(auxilary) + 1, auxilary);

		GoTo(24, 12); //input teacher
		cin.getline(auxilary, 50);
		newnode->teacher_name = new char[strlen(auxilary) + 1];
		strcpy_s(newnode->teacher_name, strlen(auxilary) + 1, auxilary);

		GoTo(31, 15); //input num of credits
		cin >> newnode->num_of_credits;

		GoTo(61, 15);
		cin >> newnode->start;
		GoTo(75, 15);
		cin >> newnode->end;

		for (int i = 0; i < 2; ++i) {
			GoTo(15, (19 + 2 * i));
			cout << "Session " << i + 1 << ": ";
			cout << "Day (MON / TUE / WED / THU / FRI / SAT): ";

			GoTo(67, (19 + 2 * i));
			cin.ignore();
			cin.getline(auxilary, 50);
			newnode->session[i].day = new char[strlen(auxilary) + 1];
			strcpy_s(newnode->session[i].day, strlen(auxilary) + 1, auxilary);

			GoTo(26, (20 + 2 * i));
			cout << "Hour start:     Minute start:";

			GoTo(38, (20 + 2 * i));
			cin >> newnode->session[i].hour_start;
			GoTo(56, (20 + 2 * i));
			cin >> newnode->session[i].minute_start;
		}

		newnode -> next = NULL;
		if (psubject == NULL) 
			psubject = newnode;
		else {
			subjects *current = psubject;
			while (current -> next != NULL) current = current -> next;
			current -> next = newnode;
		}
		memcpy(temp, "Do you want to create another one?", 35);
		announcement(temp, 1, choice, 1);
		if (choice == 1) subject_edit(1, pstudent, psubject, semester, year);
	}
	if (num == 2){
		GoTo(39, 1);
		cout << ">> REMOVE COURSE <<";


		//show list of course in this semester


		memcpy(temp, "Input the id of course you want to delete:                ", 59);
		designSquare(18, 17, 3, 62, temp, 7, 7);
		char auxilary[50];
		GoTo(63, 18);
		cin.ignore();
		cin.getline(auxilary, 50);
		subjects *current = psubject;
		if (strcmp(current -> course_id, auxilary) == 0){
			psubject = psubject -> next;
			delete current;
		} else {
			while (current -> next != NULL && strcmp(current -> next -> course_id, auxilary) != 0)
				current = current -> next;
			if (current -> next == NULL){
				
				memcpy(temp, "Do you want to input again?", 28);
				int choice = 0;
				announcement(temp, 1, choice, -1);
				if (choice == 1) subject_edit(2, pstudent, psubject, semester, year);
				return;
			} else {
				subjects *tmp = current -> next;
				current -> next = current -> next -> next;
				delete tmp;
			}
		}
		memcpy(temp, "Do you want to remove another one ?", 36);
		announcement(temp, 1, choice, 1);
		if (choice == 1) subject_edit(2, pstudent, psubject, semester, year);
	}
	if (num == 4){

		//Show list of course.

		memcpy(temp, "Input the course id you want to update score:                ", 62);
		designSquare(16, 17, 3, 65, temp, 7, 7);

		GoTo(65, 18);
		char auxilary[50];
		cin.ignore();
		cin.getline(auxilary, 50);
		subjects *current = psubject;
		while (current != NULL && strcmp(current -> course_id, auxilary) != 0)
			current = current -> next;
		if (current == NULL){
			memcpy(temp, "Do you want to input again?", 28);
			announcement(temp, 1, choice, -1);
			if (choice == 1) subject_edit(4, pstudent, psubject, semester, year);
			return;
		} else {
			view_space();
			int count = 0;
			GoTo(40, 1);
			cout << ">> INPUT SCORE <<" << endl << endl;
			profile *cur1 = pstudent;
			while (cur1 != NULL){
				subject2 *cur2 = cur1 -> psub2;
				while (cur2 != NULL && strcmp(cur2 -> course_id, auxilary) != 0)
					cur2 = cur2 -> next;
				if (cur2 != NULL){
					GoTo(37, 4 + count);
					cout << "ID: " << cur1 -> id;
					cout << "\tScore: ";
					cin >> cur2 -> score;
					++count;
				}
				cur1 = cur1 -> next;
			}
			if (count == 0) {
				memcpy(temp, "No result.", 11);
				announcement(temp, 0, choice, -1);
			}
		}
	}
	if (num == 5){
		GoTo(40, 1);
		cout << ">> UPDATE SCORE <<";
		if (pstudent == NULL || psubject == NULL){
			memcpy(temp, "You need to create data first.", 31);
			announcement(temp, 0, choice, -1);
			return;
		}


		//show list of course


		memcpy(temp, "Input the Course Id:                ", 37);
		char auxilary[50];
		designSquare(29, 15, 3, 40, temp, 7, 7);

		GoTo(52, 16);
		cin.ignore();
		cin.getline(auxilary, 50);

		subjects *cur1 = psubject;
		while (cur1 != NULL && strcmp(cur1 -> course_id, auxilary) != 0)
			cur1 = cur1 -> next;
		if (cur1 == NULL){
			memcpy(temp, "Do you want to input again?", 28);
			announcement(temp, 1, choice, -1);
			if (choice == 1) subject_edit(5, pstudent, psubject, semester, year);
			return;
		}

		view_space();

		// show list student in course.


		memcpy(temp, "Input student id you want to update:              ", 51);
		designSquare(22, 15, 3, 54, temp, 7, 7);
		int student_id;
		GoTo(62, 16);
		cin >> student_id;
		profile *cur2 = pstudent;
		while (cur2 != NULL && cur2 -> id != student_id)
			cur2 = cur2 -> next;
		if (cur2 == NULL){
			memcpy(temp, "Do you want to input again?", 28);
			announcement(temp, 1, choice, -1);
			if (choice == 1) subject_edit(5, pstudent, psubject, semester, year);
			return;
		}
		subject2 *cur3 = cur2 -> psub2;
		while (cur3 != NULL && strcmp(cur3 -> course_id, auxilary) != 0)
			cur3 = cur3 -> next;
		if (cur3 == NULL) {
			memcpy(temp, "Do you want to input again?", 28);
			announcement(temp, 1, choice, -1);
			if (choice == 1) subject_edit(5, pstudent, psubject, semester, year);
			return;
		}
		designSquare(37, 14, 4, 24, 0, 7, 7);
		GoTo(39, 15);
		cout << "Old score: " << cur3 -> score;
		GoTo(39, 16);
		cout << "Input new score: ";
		cin >> cur3 -> score;

		memcpy(temp, "Do you want to do another update?", 34); 
		announcement(temp, 1, choice, 1);
		if (choice == 1) subject_edit(5, pstudent, psubject, semester, year);
		return;
	}
	if (num == 6){
		GoTo(33, 1);
		cout << ">> UPDATE COURSE INFORMATION <<";

		if (psubject == NULL){
			memcpy(temp, "Can't updated. You have no course to update.", 45);
			announcement(temp, 0, choice, -1);
			return;
		}


		//show list of course

		memcpy(temp, "Input the Course Id:                ", 37);
		char auxilary[50];
		designSquare(29, 15, 3, 40, temp, 7, 7);

		GoTo(52, 16);
		cin.ignore();
		cin.getline(auxilary, 50);

		subjects *cur = psubject;
		while (cur != NULL && strcmp(cur -> course_id, auxilary) != 0)
			cur = cur -> next;
		if (cur == NULL){
			memcpy(temp, "Do you want to input again?", 28);
			announcement(temp, 1, choice, -1);
			if (choice == 1) subject_edit(6, pstudent, psubject, semester, year);
			return;
		}
		view_subject(cur);
	}
	return;
}

void class_edit(int num, profile *&pstudent, classrooms *&pclassid, int &semester){ 
	view_space();
	char temp[200];
	int choice = 0;
	if (num == 0){
		GoTo(38, 1);
		cout << ">> CREATE NEW CLASS <<";
		if (semester != 1){
			memcpy(temp, "It's not the 1st semester of the year", 38);
			announcement(temp, 0, choice, -1);
			return;
		}
		memcpy(temp, "Name of class:             ", 28);
		designSquare(33, 15, 3, 31, temp, 7, 7);
		GoTo(50, 16);
	  	classrooms *newnode = new classrooms;
	  	char auxilary[50];
	  	cin.ignore();
	  	cin.getline(auxilary, 50);
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
		memcpy(temp, "Do you want to create another class?", 37);
		announcement(temp, 1, choice, 1);
	  	if (choice == 1) class_edit(0, pstudent, pclassid, semester);
	}
	if (num == 2){
		//remove
		GoTo(39, 1);
		cout << ">> REMOVE CLASS <<";
		if (pclassid == NULL){
			memcpy(temp, "There isn't any classroom in this semester.", 44);
			announcement(temp, 0, choice, -1);
			return;
		}
	}
	if  (num == 1){
		cout << "\t\t>> ADD STUDENT TO CLASS <<" << endl;
		if (pclassid == NULL){
			memcpy(temp, "There is no class in this semester.", 36);
			announcement(temp, 0, choice, -1);
			return;
		}
		if (pstudent == NULL){
			memcpy(temp, "You don't have any student to add to class.", 44);
			announcement(temp, 0, choice, -1);
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
			char auxilary[50];
			cout << "Input student classroom:";
			cin.ignore();
			cin.getline(auxilary, 50);
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
			strcpy_s(current -> classroom, 50, auxilary);
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
		cout << "\tNow is just semester " << semester << "/3. You can't create new one." << endl << endl;
		system("pause");
		return;
	}
	cout << "\tDo you want to create new school year?" << endl;
	cout << "\t1. I'm sure with that." << endl;
	cout << "\t2. No, i changed my mind." << endl << endl;
	cout << "\tInput: ";
	int choice;
	cin >> choice;
	if (choice == 2) return;
	++year;
	classroom = 0;
	delete_class(pclassid);
	cout << endl;
	cout << "\tYou have successfully initialized new school year!" << endl;
	cout << "\tNow you need to create new class and new semester." << endl << endl;
	system("pause");
	semester = 0;
	//semester_edit(1, pstudent, psubject, semester, year);
	//class_edit(0, pstudent, pclassid, semester);
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
	/*system("cls");
	cout << "\t\t>> STUDENT EDIT <<" << endl << endl;
	cout << "\t1. Import file csv." << endl;
	cout << "\t2. Add student manual." << endl;
	cout << "\t3. Remove student." << endl;
	cout << "\t4. View list of student." << endl << endl;
	cout << "\tInput: ";*/
	int num;
	//cin >> num;
	showcur(0);
	print_undergraduate_function(num);
	showcur(1);
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
	/*cout << "\t1. Add new course." << endl;
	cout << "\t2. Remove course." << endl;
	cout << "\t3. View list of course." << endl;
	cout << "\t4. Update mark" << endl;
	cout << "\t5. Update course information." << endl << endl;*/
    int num;
    showcur(0);
    print_subject_function(num);
    showcur(1);
    //cin >> num;
    if (num != 3) subject_edit(num, pstudent, psubject, semester, year);
        else view_subject(psubject);
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
	/*system("cls");
	cout << "\t\t>> CLASS EDIT <<" << endl << endl;
	cout << "\t0. Create new class." << endl;
	cout << "\t1. Add student to class." << endl;
	cout << "\t2. Remove student from class" << endl;
	cout << "\t3. View list of class." << endl;
	cout << "\t4. View scoreboard of class." << endl << endl;
	cout << "\tInput: ";*/
    
    int num;
    showcur(0);
    print_class_function(num);
    showcur(1);
    //cin >> num;
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
	/*system("cls");
	cout << "\t1. Create new semester." << endl;
	cout << "\t2. View semester: " << endl << endl;
	cout << "\tInput:";*/
    int num;
    showcur(0);
    print_semester_function(num);
    showcur(1);
    //cin >> num;
    if (num == 1) semester_edit(0, pstudent, psubject, semester, year);

}

void year_function(profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year){
	//1. Create new school year.
	//	school_year_edit();
	//2. View school year.
	//	view_school_year();
	/*system("cls");
	cout <<"\t\t>> YEAR EDIT <<" << endl;
	cout << "\t1. Create new school year." << endl;
	cout << "\t2. View school year." << endl << endl;
	cout << "\tInput: ";*/
    system("cls");
    int num = 0;
    showcur(0);
    print_year_function(num);
    showcur(1);
    //cin >> num;
    if (num == 1) school_year_edit(pstudent, psubject, pclassid, classroom, semester, year);
        else view_school_year();
}

//----------ACCOUNT------------//

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

void delete_class(classrooms *&pclassid) {
    classrooms *auxilary;
    while (pclassid != NULL) {
	  auxilary = pclassid;
	  pclassid = pclassid->next;
	  delete auxilary;
    }
    return;
}

//---------INPUT SPACE--------//
// void print_option_1(){
// 	system("cls");
// 	cout << "Choose your action:" << endl;
// 	cout << "\t0. Log out." << endl;
// 	cout << "\t1. Year." << endl;
// 	cout << "\t2. Semester." << endl;
// 	cout << "\t3. Class." << endl;
// 	cout << "\t4. Subject." << endl;
// 	cout << "\t5. Student." << endl;
// 	cout << "\t6. View my profile." << endl;
// 	cout << "\t7. Exit program." << endl;
// 	return;
// }

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

// void print_option_2(){
// 	system("cls");
// 	cout << "Choose your action: " << endl;
// 	cout << "\t0. Log out." << endl;
// 	cout << "\t1. Enroll Course." << endl;
// 	cout << "\t2. Remove Course." << endl;
// 	cout << "\t3. View list of course." << endl;
// 	cout << "\t4. View scoreboard." << endl;
// 	cout << "\t5. View my profile." << endl;
// 	cout << "\t6. Exit program." << endl;
// 	return;
// }

//void make_choice_2(int &choice, int &id_profile){
//	switch (choice){
//		case 0:
//			logout();
//			break;
//		case 1:
//			enroll_course();
//			break;
//		case 2:
//			remove_course();
//			break;
//		case 3:
//			view_list_of_course();
//			break;
//		case 4:
//			view_scoreboard();
//			break;
//		case 5: 
//			//View profile;
//			break;
//		case 6: 
//			break;
//	}
//	return;
//}