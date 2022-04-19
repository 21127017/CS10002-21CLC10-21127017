#include "project.h"	 
using std::cout;
using std::cin;

char *int_to_char(long long x){
	long long tmp = x;
	int count = 0, base = 1;
	while (tmp != 0){
		++count;
		tmp /= 10;
		base = base * 10;
	}
	base = base / 10;
	char *auxilary = new char[count + 1];
	int i = 0;
	while (base != 0){
		auxilary[i++] = (x / base) % 10 + 48;
		base = base / 10;
	}
	//auxilary[i] = '\n';
	return auxilary;
}

void draw_button(int line, int value, int maxlist){
	int color = 240;
	//int line = 25;
	gt(40, line); 
	cout << sc(218) << sc(196) << sc(196) << sc(196) << sc(196) << sc(196) << sc(196) << sc(191);
	cout << "  ";
	cout << sc(218) << sc(196) << sc(196) << sc(196) << sc(196) << sc(196) << sc(196) << sc(191);
	++line;
	gt(40, line); cout << sc(179) << " ";
	if (value > 8) set_color(color); 
	cout << " " << sc(174) << sc(174) << " ";
	set_color(7); cout << " " << sc(179);
	int tmp = value / 8 + 1;
	cout << ((tmp < 10) ? "0" : "") << tmp;
	gt(50, line); cout << sc(179) << " ";
	if (value <= maxlist - 8) set_color(color); 
	cout << " " << sc(175) << sc(175) << " ";
	set_color(7); cout << " " << sc(179);

	++line;
	gt(40, line);
	cout << sc(192) << sc(196) << sc(196) << sc(196) << sc(196) << sc(196) << sc(196) << sc(217);
	cout << "  ";
	cout << sc(192) << sc(196) << sc(196) << sc(196) << sc(196) << sc(196) << sc(196) << sc(217);
	gt(40, ++line); cout << "Press ESC to exit.";
	return;
}

void print_information(char *x1, char *x2, int x, int y, int color){
	int n1 = static_cast<int>(strlen(x1));
	int n2 = static_cast<int>(strlen(x2));
	designSquare(x, y, 3, 12, x1, color, color);
	set_color(7);
	gt(x + 13, y + 1); cout << " " << x2 << " ";
	set_color(color);
	gt(x + 13, y);
	for (int i = 1; i <= 30; ++i) 
		cout << sc(196);
	gt(x + 13, y + 2);
	for (int i = 1; i <= 30; ++i)
		cout << sc(196);
	set_color(7);
}

void view_profile(int user_id, profile *p){
    if (p == NULL) return;
	while (p != NULL){
		if (p -> id == user_id) break;
		p = p -> next;
	}
	view_space();
	
	int line = 2; 
	gt(60, line++); cout << sc(203);
	for (int i = 1; i <= 27; ++i){
		gt(60, line++); cout << sc(186);
	}
	gt(60, line); cout << sc(202);

	line = 3;
	set_color(14);
	gt(61, line++); cout << "............  ..::::::..  ............";
	gt(61, line++); cout << ".......... .:^~!!!!!!!!~^.  ..........";
	gt(61, line++); cout << "......... :~!!!!!!!!!!!!!!~. .........";
	gt(61, line++); cout << "........ :!!!!!!!!!!!!!!!!!!. ........";
	gt(61, line++); cout << ".........~!!!!!!!!!!!!!!!!!!~.........";
	gt(61, line++); cout << "....... .!!!!!!!!!!!!!!!!!!!!.........";
	gt(61, line++); cout << ".........~!!!!!!!!!!!!!!!!!!~.........";
	gt(61, line++); cout << "........ :!!!!!!!!!!!!!!!!!~. ........";
	gt(61, line++); cout << "........  .^!!!!!!!!!!!!!!^. .........";
	gt(61, line++); cout << "......  .:^:::^~!!!!!!~^::^^:.  ......";
	gt(61, line++); cout << ".... .:~!!!!!~^::::::::^~!!!!!^:  ....";
	gt(61, line++); cout << "... :~!!!!!!!!!!!!!!!!!!!!!!!!!!^. ...";
	gt(61, line++); cout << ".. ^!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!^ ..";
	gt(61, line++); cout << ". ^!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!^ .";
	gt(61, line++); cout << ". !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! .";
	gt(61, line++); cout << ". !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! .";
	//gt(61, line++); cout << " :^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^. ";
	//gt(61, line++); cout << "";
	set_color(7);

	line = 19;
	gt(60, line); cout << sc(204);
	for (int i = 0; i < 38; ++i) cout << sc(205);
	cout << sc(185);
	
	int color = 11, spacex = 6;
	line = 4;
	set_color(color);
	gt(spacex, line++); cout <<" ____  _             _            _   ";// " _____         ___ _ _";     
	gt(spacex, line++); cout <<"/ ___|| |_ _   _  __| | ___ _ __ | |_ ";// "|  _  |___ ___|  _|_| |___ ";
	gt(spacex, line++); cout <<"\\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __|";// "|   __|  _| . |  _| | | -_|";
	gt(spacex, line++); cout <<" ___) | |_| |_| | (_| |  __/ | | | |_ ";// "|__|  |_| |___|_| |_|_|___|";
	gt(spacex, line++); cout <<"|____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__|";//
	set_color(7);                        

	char *auxilary1 = new char[25];
	char *auxilary2 = new char[30];
	line += 2;
	strcpy_s(auxilary1, 5, "Name");
	strcpy_s(auxilary2, 30, "Vo Nguyen Gia Bao");
	strcpy_s(auxilary2, 25, p -> last_name);
	strcat_s(auxilary2, 25, p -> first_name);
	print_information(auxilary1, auxilary2, spacex, ++line, color);

	line += 3;
	strcpy_s(auxilary1, 7, "Gender");
	//strcpy_s(auxilary2, 5, "Male");
	print_information(auxilary1, p -> gender, spacex, line, color);
	strcpy_s(auxilary2, 2, "?");
	line += 3;
	//strcpy_s(auxilary1, 4, "ID");
	//strcpy_s(auxilary2, 10, "21127017");
	print_information(auxilary1, auxilary2, spacex, line, color);
	gt(20, line + 1); cout << p -> id;

	line += 3;
	/*strcpy_s(auxilary1, 6, "Year");
	strcpy_s(auxilary2, 5, int_to_char(p -> dob.day));
	strcat_s(auxilary2, 2, "/");
	strcat_s(auxilary2, 5, int_to_char(p -> dob.month));
	strcat_s(auxilary2, 2, "/");
	strcat_s(auxilary2, 6, int_to_char(p -> dob.year));*/
	print_information(auxilary1, auxilary2, spacex, line, color);
	gt(20, line + 1); cout << p -> dob.day << "/" << p -> dob.month << "/" << p -> dob.year;

	line += 3;
	strcpy_s(auxilary1, 11, "Social ID");
	//strcpy_s(auxilary2, 11, "352637777");
	print_information(auxilary1, auxilary2, spacex, line, color);
	gt(20, line + 1); cout << p -> social_id;

	int key = 0, i = 1, height = 26, width = 5;
	spacex = 67;
	showcur(0);
	while (key != 13)
	{
		strcpy_s(auxilary1, 17, "Change Password");
		designSquare(spacex, 20, width, height, auxilary1, 7, 7);

		strcpy_s(auxilary1, 16, "Back to Menu");
		designSquare(spacex, 25, width, height, auxilary1, 7, 7);

		if (i == 1){
			strcpy_s(auxilary1, 16, "Change Password");
			designSquare(spacex, 20, width, height, auxilary1, 11, 432);	
		} else {
			strcpy_s(auxilary1, 16, "Back to Menu");
			designSquare(spacex, 25, width, height, auxilary1, 11, 432);
		}

		key = _getch();
		if (key == 72) i -= 1;
		if (key == 80) i += 1;
		if (i == 0) i = 2;
		if (i == 3) i = 1;
	}
	if (i == 1) changePassword(user_id);
	showcur(1);
}

void view_student_scoreboard(int id_student, profile *pstudent, subjects *psubject){
	//8 6 10 30 7 5 18
	showcur(0);
	view_space();

	gt(4, 5); cout << "RESULT:";
	char *auxilary1 = new char[10];
	strcpy_s(auxilary1, 10, "Creadit");
	designSquare(12, 4, 3, 14, auxilary1, 7, 7);//Creadit 58
	strcpy_s(auxilary1, 10, "Average");
	designSquare(28, 4, 3, 10, auxilary1, 7, 7);//Average 74
	strcpy_s(auxilary1, 10, "GPA");
	designSquare(40, 4, 3, 10, auxilary1, 7, 7);//GPA 86

	int line = 7;
	gt(5, line); 
	for (int i = 1; i < 92; ++i)
		cout << sc(205);
	gt( 4, line); cout << sc(201);
	gt(13, line); cout << sc(203);
	gt(20, line); cout << sc(203);
	gt(31, line); cout << sc(203);
	gt(62, line); cout << sc(203);
	gt(70, line); cout << sc(203);
	gt(76, line); cout << sc(203);
	gt(95, line); cout << sc(187);

	++line;
	gt( 4, line); cout << sc(186) << "Semester";
	gt(13, line); cout << sc(186) << " Year";
	gt(20, line); cout << sc(186) << "Course ID";
	gt(31, line); cout << sc(186) << "             Name";
	gt(62, line); cout << sc(186) << "Creadit";
	gt(70, line); cout << sc(186) << "Score";
	gt(76, line); cout << sc(186) << "       Note";
	gt(95, line); cout << sc(186);

	++line;
	gt(5, line);
	for (int i = 1; i < 92; ++i)
		cout << sc(205);
	gt( 4, line); cout << sc(204);
	gt(13, line); cout << sc(206);
	gt(20, line); cout << sc(206);
	gt(31, line); cout << sc(206);
	gt(62, line); cout << sc(206);
	gt(70, line); cout << sc(206);
	gt(76, line); cout << sc(206);
	gt(95, line); cout << sc(185);

	profile *auxilary = pstudent;
	while (auxilary != NULL){
		if (auxilary -> id == id_student) break;			
		auxilary = auxilary -> next;
	}
	
	int maxlist = 0, creadit = 0;
	double score = 0, gpa = 0;
	subject2 *pp = auxilary->psub2;
	while (pp != NULL) {
		++maxlist;
		subjects *ppp = psubject;
		while (ppp != NULL && strcmp(ppp->course_id, pp->course_id) != 0)
			ppp = ppp->next;
		creadit += ppp->num_of_credits;
		score += pp->score * ppp->num_of_credits;
		pp = pp->next;
	}

	score /= creadit;
	gpa = score * 0.4;

	gt(58, 4); cout << creadit;
	gt(74, 4); cout << setprecision(2) << fixed << score;
	gt(86, 4); cout << setprecision(2) << fixed << gpa;

	int tmp = line;
	int value = 1;
	while (true){
		line = tmp;
		showcur(0);

		subject2 *cur = auxilary -> psub2;
		for (int i = 1; i < value; ++i)
			cur = cur -> next;

		subjects *p = psubject;
		while (p != NULL && strcmp(p->course_id, cur->course_id) != 0)
			p = p->next;
	
		for (int t = 1; t <= 8; ++t){
			++line;
			gt( 4, line); cout << sc(186) << p -> semester;
			gt(13, line); cout << sc(186) << p -> year;
			gt(20, line); cout << sc(186) << p -> course_id;
			gt(31, line); cout << sc(186) << p -> name;
			gt(62, line); cout << sc(186) << p -> num_of_credits;
			gt(70, line); cout << sc(186) << cur -> score;
			gt(76, line); cout << sc(186);
			gt(95, line); cout << sc(186);
			
			++line;
			if (t != 8){
				gt(5, line);
				for (int i = 1; i < 92; ++i)
					cout << sc(205);
				gt( 4, line); cout << sc(204);
				gt(13, line); cout << sc(206);
				gt(20, line); cout << sc(206);
				gt(31, line); cout << sc(206);
				gt(62, line); cout << sc(206);
				gt(70, line); cout << sc(206);
				gt(76, line); cout << sc(206);
				gt(95, line); cout << sc(185);
			} else {
				gt(5, line);
				for (int i = 1; i < 92; ++i)
					cout << sc(205);
				gt( 4, line); cout << sc(200);
				gt(13, line); cout << sc(202);
				gt(20, line); cout << sc(202);
				gt(31, line); cout << sc(202);
				gt(62, line); cout << sc(202);
				gt(70, line); cout << sc(202);
				gt(76, line); cout << sc(202);
				gt(95, line); cout << sc(188);
			}
			cur = cur -> next;
			if (cur == NULL) {
				gt( 4, line); cout << sc(200);
				gt(13, line); cout << sc(202);
				gt(20, line); cout << sc(202);
				gt(31, line); cout << sc(202);
				gt(62, line); cout << sc(202);
				gt(70, line); cout << sc(202);
				gt(76, line); cout << sc(202);
				gt(95, line); cout << sc(188);
				break;
			}
		}
		

		draw_button(26, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}

void view_student_enroll_course(int id_student, profile *pstudent, subjects *psubject){
	// 4 30 10 20 7 6 8
	showcur(0);
	view_space();
	int line = 5;
	gt(4, line); 
	for (int i = 1; i < 93; ++i)
		cout << sc(205);
	gt( 3, line); cout << sc(201);
	gt( 8, line); cout << sc(203);
	gt(39, line); cout << sc(203);
	gt(50, line); cout << sc(203);
	gt(71, line); cout << sc(203);
	gt(79, line); cout << sc(203);
	gt(86, line); cout << sc(203);
	gt(95, line); cout << sc(187);

	++line;
	gt( 3, line); cout << sc(186) << " No";
	gt( 8, line); cout << sc(186) << "            Name";
	gt(39, line); cout << sc(186) << "Course ID";
	gt(50, line); cout << sc(186) << "      Teacher";
	gt(71, line); cout << sc(186) << "Creadit";
	gt(79, line); cout << sc(186) << " Year";
	gt(86, line); cout << sc(186) << "Semester";
	gt(95, line); cout << sc(186);

	++line;
	gt(4, line);
	for (int i = 1; i < 93; ++i)
		cout << sc(205);
	gt( 3, line); cout << sc(204);
	gt( 8, line); cout << sc(206);
	gt(39, line); cout << sc(206);
	gt(50, line); cout << sc(206);
	gt(71, line); cout << sc(206);
	gt(79, line); cout << sc(206);
	gt(86, line); cout << sc(206);
	gt(95, line); cout << sc(185);	

	profile *auxilary = pstudent;
	while (auxilary != NULL){
		if (auxilary -> id == id_student) break;
		auxilary = auxilary -> next;
	}

	if (auxilary == NULL) {
		gt( 3, line); cout << sc(200);
		gt( 8, line); cout << sc(202);
		gt(39, line); cout << sc(202);
		gt(50, line); cout << sc(202);
		gt(71, line); cout << sc(202);
		gt(79, line); cout << sc(202);
		gt(86, line); cout << sc(202);
		gt(95, line); cout << sc(188);
	}

	int maxlist = 0;
	subject2 *curtmp = auxilary -> psub2;
	while (curtmp != NULL) {
		curtmp = curtmp->next;
		++maxlist;
	}

	int tmp = line;
	int value = 1;
	while (true){
		line = tmp;
		showcur(0);
		subject2 *cur = auxilary -> psub2;
		for (int i = 1; i < value; ++i)
			cur = cur -> next;
		subjects *p = psubject;
		while (p != NULL && strcmp(p->course_id, cur->course_id) != 0)
			p = p->next;

		if (p == NULL) {
			gt( 3, line); cout << sc(200);
			gt( 8, line); cout << sc(202);
			gt(39, line); cout << sc(202);
			gt(50, line); cout << sc(202);
			gt(71, line); cout << sc(202);
			gt(79, line); cout << sc(202);
			gt(86, line); cout << sc(202);
			gt(95, line); cout << sc(188);
			break;
		}
	
		for (int t = 1; t <= 8; ++t){
			++line;
			gt( 3, line); cout << sc(186) << t;
			gt( 8, line); cout << sc(186) << p -> name;
			gt(39, line); cout << sc(186) << p -> course_id;
			gt(50, line); cout << sc(186) << p -> teacher_name;
			gt(71, line); cout << sc(186) << p -> num_of_credits;
			gt(79, line); cout << sc(186) << p -> year;
			gt(86, line); cout << sc(186) << p -> semester;
			gt(95, line); cout << sc(186);
			
			++line;
			if (t != 8){
				gt(4, line);
				for (int i = 1; i < 93; ++i)
					cout << sc(205);
				gt( 3, line); cout << sc(204);
				gt( 8, line); cout << sc(206);
				gt(39, line); cout << sc(206);
				gt(50, line); cout << sc(206);
				gt(71, line); cout << sc(206);
				gt(79, line); cout << sc(206);
				gt(86, line); cout << sc(206);
				gt(95, line); cout << sc(185);
			} else {
				gt(4, line);
				for (int i = 1; i < 93; ++i)
					cout << sc(205);
				gt( 3, line); cout << sc(200);
				gt( 8, line); cout << sc(202);
				gt(39, line); cout << sc(202);
				gt(50, line); cout << sc(202);
				gt(71, line); cout << sc(202);
				gt(79, line); cout << sc(202);
				gt(86, line); cout << sc(202);
				gt(95, line); cout << sc(188);
			}
			cur = cur -> next;
			if (cur == NULL) {
				gt( 3, line); cout << sc(200);
				gt( 8, line); cout << sc(202);
				gt(39, line); cout << sc(202);
				gt(50, line); cout << sc(202);
				gt(71, line); cout << sc(202);
				gt(79, line); cout << sc(202);
				gt(86, line); cout << sc(202);
				gt(95, line); cout << sc(188);
				break;
			}
		}
		

		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}
//khong nho o dau
void view_scoreboard_of_course(char *id_course, profile *pstudent){
	// 4 30 10 9 5
	showcur(0);
	view_space();
	int maxlist = 80;
	int line = 5;
	gt(19, line); 
	for (int i = 1; i < 64; ++i)
		cout << sc(205);
	gt(18, line); cout << sc(201);
	gt(23, line); cout << sc(203);
	gt(54, line); cout << sc(203);
	gt(65, line); cout << sc(203);
	gt(75, line); cout << sc(203);
	gt(81, line); cout << sc(187);

	++line;
	gt(18, line); cout << sc(186) << " No";
	gt(23, line); cout << sc(186) << "          Full Name";
	gt(54, line); cout << sc(186) << "    ID";
	gt(65, line); cout << sc(186) << "  Class";
	gt(75, line); cout << sc(186) << "Score";
	gt(81, line); cout << sc(186);

	++line;
	gt(19, line);
	for (int i = 1; i < 64; ++i)
		cout << sc(205);
	gt(18, line); cout << sc(204);
	gt(23, line); cout << sc(206);
	gt(54, line); cout << sc(206);
	gt(65, line); cout << sc(206);
	gt(75, line); cout << sc(206);
	gt(81, line); cout << sc(185);

	int tmp = line;
	int value = 1;
	while (true){
		line = tmp;
		showcur(0);
		
		/*
		profile *cur = pstudent;
		for (int i = 1; i < value; ++i){
			while (cur != NULL){
				subject2 *cur1 = cur -> psub2;
				bool dd = 0;
				while (cur1 != NULL){
					if (strcmp(cur1 -> course_id, id_course) == 0){
						dd = 1;
						break;
					}
					cur1 = cur1 -> next;
				}
				if (dd) break;
				cur = cur -> next;
			}
		}
		*/

		for (int t = 1; t <= 8; ++t){
			/*
			while (cur != NULL){
				subject2 *cur1 = cur -> psub2;
				bool dd = 0;
				while (cur1 != NULL){
					if (strcmp(cur1 -> course_id, id_course) == 0){
						dd = 1;
						break;
					}
					cur1 = cur1 -> next;
				}
				if (dd) break;
				cur = cur -> next;
			}
			*/
			++line;
			gt(18, line); cout << sc(186);
			gt(23, line); cout << sc(186);
			gt(54, line); cout << sc(186);
			gt(65, line); cout << sc(186);
			gt(75, line); cout << sc(186);
			gt(81, line); cout << sc(186);
			
			++line;
			if (t != 8){
				gt(19, line);
				for (int i = 1; i < 64; ++i)
					cout << sc(205);
				gt(18, line); cout << sc(204);
				gt(23, line); cout << sc(206);
				gt(54, line); cout << sc(206);
				gt(65, line); cout << sc(206);
				gt(75, line); cout << sc(206);
				gt(81, line); cout << sc(185);
			} else {
				gt(19, line);
				for (int i = 1; i < 64; ++i)
					cout << sc(205);
				gt(18, line); cout << sc(200);
				gt(23, line); cout << sc(202);
				gt(54, line); cout << sc(202);
				gt(65, line); cout << sc(202);
				gt(75, line); cout << sc(202);
				gt(81, line); cout << sc(188);
			}
		}
		

		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}
//danh sach lop hoc
void view_list_of_course(subjects *psubject, profile *pstudent, int semester, int year){
	//10 30 7 5 5 5 5 6
	showcur(0);
	view_space();
	int line = 5;
	gt(10, line); 
	for (int i = 1; i <= 81; ++i)
		cout << sc(205);
	gt( 9, line); cout << sc(201);
	gt(20, line); cout << sc(203);
	gt(51, line); cout << sc(203);
	gt(59, line); cout << sc(203);
	gt(65, line); cout << sc(203);
	gt(71, line); cout << sc(203);
	gt(77, line); cout << sc(203);
	gt(83, line); cout << sc(203);
	gt(90, line); cout << sc(187);

	++line;
	gt( 9, line); cout << sc(186) << "Course ID";
	gt(20, line); cout << sc(186) << "             Name";
	gt(51, line); cout << sc(186) << "Creadit";
	gt(59, line); cout << sc(186) << "Start";
	gt(65, line); cout << sc(186) << " End";
	gt(71, line); cout << sc(186) << "Sess1";
	gt(77, line); cout << sc(186) << "Sess2";
	gt(83, line); cout << sc(186) << "Enroll";
	gt(90, line); cout << sc(186);

	++line;
	gt(10, line);
	for (int i = 1; i <= 81; ++i)
		cout << sc(205);
	gt( 9, line); cout << sc(204);
	gt(20, line); cout << sc(206);
	gt(51, line); cout << sc(206);
	gt(59, line); cout << sc(206);
	gt(65, line); cout << sc(206);
	gt(71, line); cout << sc(206);
	gt(77, line); cout << sc(206);
	gt(83, line); cout << sc(206);
	gt(90, line); cout << sc(185);
	
	int maxlist = 0;
	subjects *p = psubject;
	while (p != NULL) {
		if (p->year == year && p->semester == semester)
			++maxlist;
		p = p->next;
	}

	int tmp = line;
	int value = 1;
	while (true){
		line = tmp;
		showcur(0);
		subjects *cur = psubject;
		for (int i = 1; i < value; ++i) {
			while (cur != NULL && (cur->year != year || cur->semester != semester))
				cur = cur->next;
			if (cur == NULL) {
				gt( 9, line); cout << sc(200);
				gt(20, line); cout << sc(202);
				gt(51, line); cout << sc(202);
				gt(59, line); cout << sc(202);
				gt(65, line); cout << sc(202);
				gt(71, line); cout << sc(202);
				gt(77, line); cout << sc(202);
				gt(83, line); cout << sc(202);
				gt(90, line); cout << sc(188);
				break;
			}
			cur = cur->next;
		}

		for (int t = 1; t <= 8; ++t){
			while (cur != NULL && (cur->year != year || cur->semester != semester))
				cur = cur->next;
			if (cur == NULL) {
				gt( 9, line); cout << sc(200);
				gt(20, line); cout << sc(202);
				gt(51, line); cout << sc(202);
				gt(59, line); cout << sc(202);
				gt(65, line); cout << sc(202);
				gt(71, line); cout << sc(202);
				gt(77, line); cout << sc(202);
				gt(83, line); cout << sc(202);
				gt(90, line); cout << sc(188);
				break;
			}
			++line;
			gt( 9, line); cout << sc(186) << cur -> course_id;
			gt(20, line); cout << sc(186) << cur -> name;
			gt(51, line); cout << sc(186) << cur -> num_of_credits;
			gt(59, line); cout << sc(186) << cur -> start;
			gt(65, line); cout << sc(186) << cur -> end;
			gt(71, line); cout << sc(186) << cur -> session[0].day;
			gt(77, line); cout << sc(186) << cur -> session[1].day;
			gt(83, line); cout << sc(186) << cur -> maximum << "/" << 50;
			gt(90, line); cout << sc(186);

			++line;
			if (t != 8){
				gt(10, line);
				for (int i = 1; i <= 81; ++i)
					cout << sc(205);
				gt( 9, line); cout << sc(204);
				gt(20, line); cout << sc(206);
				gt(51, line); cout << sc(206);
				gt(59, line); cout << sc(206);
				gt(65, line); cout << sc(206);
				gt(71, line); cout << sc(206);
				gt(77, line); cout << sc(206);
				gt(83, line); cout << sc(206);
				gt(90, line); cout << sc(185);
			} else {
				gt(10, line);
				for (int i = 1; i <= 81; ++i)
					cout << sc(205);
				gt( 9, line); cout << sc(200);
				gt(20, line); cout << sc(202);
				gt(51, line); cout << sc(202);
				gt(59, line); cout << sc(202);
				gt(65, line); cout << sc(202);
				gt(71, line); cout << sc(202);
				gt(77, line); cout << sc(202);
				gt(83, line); cout << sc(202);
				gt(90, line); cout << sc(188);
			}
			cur = cur->next;
			if (cur == NULL) {
				gt( 9, line); cout << sc(200);
				gt(20, line); cout << sc(202);
				gt(51, line); cout << sc(202);
				gt(59, line); cout << sc(202);
				gt(65, line); cout << sc(202);
				gt(71, line); cout << sc(202);
				gt(77, line); cout << sc(202);
				gt(83, line); cout << sc(202);
				gt(90, line); cout << sc(188); 
				break;
			}
		}

		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}

void view_student_in_class(char *classid, profile *pstudent){
	/*
	No 10
	Full Name 30
	ID 10
	Birth 12
	Gen 7
	*/
	showcur(0);
	view_space();
	int line = 5;
	gt(20, line); 
	for (int i = 1; i <= 68; ++i)
		cout << sc(205);
	gt(19, line); cout << sc(201);
	gt(24, line); cout << sc(203);
	gt(55, line); cout << sc(203);
	gt(66, line); cout << sc(203);
	gt(79, line); cout << sc(203);
	gt(87, line); cout << sc(187);

	++line;
	gt(19, line); cout << sc(186) << " No"; 
	gt(24, line); cout << sc(186) << "           Full Name";
	gt(55, line); cout << sc(186) << "    ID";
	gt(66, line); cout << sc(186) << "     DOB";
	gt(79, line); cout << sc(186) << "  Gen";
	gt(87, line); cout << sc(186);

	++line;
	gt(19, line); cout << sc(204);
	for (int i = 1; i <= 68; ++i)
		cout << sc(205);
	gt(24, line); cout << sc(206);
	gt(55, line); cout << sc(206);
	gt(66, line); cout << sc(206);
	gt(79, line); cout << sc(206);
	gt(87, line); cout << sc(185);

	if (pstudent == NULL) {
		gt(19, line); cout << sc(200);
		gt(24, line); cout << sc(202);
		gt(55, line); cout << sc(202);
		gt(66, line); cout << sc(202);
		gt(79, line); cout << sc(202);
		gt(87, line); cout << sc(188);
		gt(24, line + 1); cout << "No result." << endl;
		system("pause");
		return;
	}
	
	int maxlist = 0;
	profile *p = pstudent;
	while (p != NULL) {
		if (strcmp(p->classroom, classid) == 0)
			++maxlist;
		p = p->next;
	}

	int tmp = line;
	int value = 1;
	while (true){
		view_space();
		line = 5;
		gt(20, line); 
		for (int i = 1; i <= 68; ++i)
			cout << sc(205);
		gt(19, line); cout << sc(201);
		gt(24, line); cout << sc(203);
		gt(55, line); cout << sc(203);
		gt(66, line); cout << sc(203);
		gt(79, line); cout << sc(203);
		gt(87, line); cout << sc(187);

		++line;
		gt(19, line); cout << sc(186) << " No"; 
		gt(24, line); cout << sc(186) << "           Full Name";
		gt(55, line); cout << sc(186) << "    ID";
		gt(66, line); cout << sc(186) << "     DOB";
		gt(79, line); cout << sc(186) << "  Gen";
		gt(87, line); cout << sc(186);

		++line;
		gt(19, line); cout << sc(204);
		for (int i = 1; i <= 68; ++i)
			cout << sc(205);
		gt(24, line); cout << sc(206);
		gt(55, line); cout << sc(206);
		gt(66, line); cout << sc(206);
		gt(79, line); cout << sc(206);
		gt(87, line); cout << sc(185);
		//line = tmp;
		showcur(0);

		profile *cur = pstudent;
		for (int i = 1; i < value; ++i) {
			while (cur != NULL && strcmp(cur->classroom, classid) != 0)
				cur = cur->next;
			cur = cur->next;
		}

		for (int x = 0; x < 8; ++x){
			while (cur != NULL && strcmp(cur->classroom, classid) != 0)
				cur = cur->next;

			if (cur == NULL) {
				gt(19, line); cout << sc(200);
				gt(24, line); cout << sc(202);
				gt(55, line); cout << sc(202);
				gt(66, line); cout << sc(202);
				gt(79, line); cout << sc(202);
				gt(87, line); cout << sc(188);
				break;
			}
			++line;
			gt(19, line); cout << sc(186) << x + 1;
			gt(24, line); cout << sc(186) << cur -> last_name << " " << cur -> first_name;//
			gt(55, line); cout << sc(186) << cur -> id;//
			gt(66, line); cout << sc(186) << cur -> dob.day << "/" << cur -> dob.month << "/" << cur -> dob.year;//
			gt(79, line); cout << sc(186) << cur -> gender;//
			gt(87, line); cout << sc(186);//
			++line;
			if (x == 7/*count == value + 8*/){
				gt(19, line); cout << sc(200);
				for (int j = 1; j <= 68; ++j)
					cout << sc(205);
				gt(24, line); cout << sc(202);
				gt(55, line); cout << sc(202);
				gt(66, line); cout << sc(202);
				gt(79, line); cout << sc(202);
				gt(87, line); cout << sc(188);
			} else {
				gt(19, line); cout << sc(204);
				for (int j = 1; j <= 68; ++j)
					cout << sc(205);
				gt(24, line); cout << sc(206);
				gt(55, line); cout << sc(206);
				gt(66, line); cout << sc(206);
				gt(79, line); cout << sc(206);
				gt(87, line); cout << sc(185);
			}
			cur = cur->next;
			if (cur == NULL) {
				gt(19, line); cout << sc(200);
				gt(24, line); cout << sc(202);
				gt(55, line); cout << sc(202);
				gt(66, line); cout << sc(202);
				gt(79, line); cout << sc(202);
				gt(87, line); cout << sc(188);
				break;
			}
		}
		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}


void view_student_in_course(char *id_course, profile *p){
	//head table
	//2 20 8 3 10
	GoTo(24, 5);
	cout << static_cast<char>(201);
	for (int i = 1; i <= 47; ++i)
		cout << static_cast<char>(205);
	
	GoTo(27, 5); cout << static_cast<char>(203);
	GoTo(48, 5); cout << static_cast<char>(203);
	GoTo(57, 5); cout << static_cast<char>(203);
	GoTo(61, 5); cout << static_cast<char>(203);
	GoTo(72, 5); cout << static_cast<char>(187);

	GoTo(24, 6); cout << static_cast<char>(186) << "No" << static_cast<char>(186);
	GoTo(34, 6); cout << "Full Name";
	GoTo(48, 6); cout << static_cast<char>(186);
	GoTo(52, 6); cout << "ID";
	GoTo(57, 6); cout << static_cast<char>(186) << "Gen";
	GoTo(61, 6); cout << static_cast<char>(186);
	GoTo(65, 6); cout << "Birth";
	GoTo(72, 6); cout << static_cast<char>(186);

	GoTo(24, 7); cout << static_cast<char>(204);
	for (int i = 1; i <= 47; ++i) 
		cout << static_cast<char>(205);
	GoTo(27, 7); cout << static_cast<char>(206);
	GoTo(48, 7); cout << static_cast<char>(206);
	GoTo(57, 7); cout << static_cast<char>(206);
	GoTo(61, 7); cout << static_cast<char>(206);
	GoTo(72, 7); cout << static_cast<char>(185);

	if (p == NULL) {
		GoTo(24, 8); cout << static_cast<char>(200);
		for (int i = 1; i <= 47; ++i) 
			cout << static_cast<char>(205);
		GoTo(27, 8); cout << static_cast<char>(202);
		GoTo(48, 8); cout << static_cast<char>(202);
		GoTo(57, 8); cout << static_cast<char>(202);
		GoTo(61, 8); cout << static_cast<char>(202);
		GoTo(72, 8); cout << static_cast<char>(188);
		GoTo(27, 9); cout << "No result." << endl;
		return;
	}
	
	int maxlist = 0;
	profile *pp = p;
	while (pp != NULL) {
		subject2 *ppp = pp->psub2;
		while (ppp != NULL) {
			if (strcmp(ppp->course_id, id_course) == 0) {
				++maxlist;
				break;
			}
			ppp = ppp->next;
		}
		pp = pp->next;

	}
	//code
	int value = 1;
	int endline = 7;
	int tmp = endline;
	while (true){
		endline = tmp;
		profile *curx = p;
		for (int i = 1; i < value; ++i) {
			while (curx != NULL) {
				subject2 *cur1 = curx -> psub2;
				bool dd = 0;
				while (cur1 != NULL) {
					if (strcmp(id_course, cur1->course_id) == 0) {
						dd = 1;
						break;
					}
				}
				if (dd) break;
			}
			curx = curx -> next;
		}
		int count = 0;
		while (curx != NULL && count < 8){
			subject2 *cur = curx -> psub2;
			bool dd = 0;
			while (cur != NULL){
				if (strcmp(id_course, cur -> course_id) == 0){
					dd = 1;
					break;
				}
				if (dd){
					++endline;
					GoTo(24, endline); cout << static_cast<char>(186) << count++ << static_cast<char>(186) 
						<< curx -> last_name << " " << curx -> first_name;
					GoTo(48, endline); cout << static_cast<char>(186) << curx -> id;
					GoTo(57, endline); cout << static_cast<char>(186) << curx -> gender;
					GoTo(61, endline); cout << static_cast<char>(186) 
						<< curx -> dob.day << "/" << curx ->dob.month << "/" << curx -> dob.year;
					GoTo(72, endline); cout << static_cast<char>(186);
				}
			}
			curx = curx->next;
			if (curx == NULL) break;
		}
		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}

	//end table
	++endline;
	GoTo(24, endline); cout << static_cast<char>(200);
	for (int i = 1; i <= 47; ++i) 
		cout << static_cast<char>(205);
	GoTo(27, endline); cout << static_cast<char>(202);
	GoTo(48, endline); cout << static_cast<char>(202);
	GoTo(57, endline); cout << static_cast<char>(202);
	GoTo(61, endline); cout << static_cast<char>(202);
	GoTo(72, endline); cout << static_cast<char>(188);
}

void view_list_of_class(classrooms *pclassid, profile *pstudent){
	/*
	gt(31, line); cout << sc(186);
	gt(36, line); cout << sc(186);
	gt(48, line); cout << sc(186);
	gt(58, line); cout << sc(186);
	gt(65, line); cout << sc(186);
	4 11 9 6
	*/

	//showcur(0); // duyet pstudent
	//view_space();
	//int line = 5;
	//gt(31, line); cout << sc(201);
	//for (int i = 1; i < 35; ++i)
	//	cout << sc(205);

	//gt(36, line); cout << sc(203);
	//gt(48, line); cout << sc(203);
	//gt(58, line); cout << sc(203);
	//gt(65, line); cout << sc(187);

	//++line;
	//gt(31, line); cout << sc(186);
	//cout << " No ";
	//gt(36, line); cout << sc(186);
	//cout << "   Class   ";
	//gt(48, line); cout << sc(186);
	//cout << "   Num   ";
	//gt(58, line); cout << sc(186);
	//cout << " Year ";
	//gt(65, line); cout << sc(186);

	//gt(31, line); cout << sc(186);
	//gt(36, line); cout << sc(186);
	//gt(48, line); cout << sc(186);
	//gt(58, line); cout << sc(186);
	//gt(65, line); cout << sc(186);

	//++line;
	//gt(31, line); cout << sc(204);
	//for (int i = 1; i < 35; ++i)
	//	cout << sc(205);
	//gt(36, line); cout << sc(206);
	//gt(48, line); cout << sc(206);
	//gt(58, line); cout << sc(206);
	//gt(65, line); cout << sc(185);
	
	int maxlist = 0;
	classrooms *pp = pclassid;
	while (pp != NULL) {
		++maxlist;
		pp = pp->next;
	}

	int value = 1;
	//int tmp = line;
	while (true){
		//line = tmp;
		showcur(0);
		view_space();
		int line = 5;
		gt(31, line); cout << sc(201);
		for (int i = 1; i < 35; ++i)
			cout << sc(205);

		gt(36, line); cout << sc(203);
		gt(48, line); cout << sc(203);
		gt(58, line); cout << sc(203);
		gt(65, line); cout << sc(187);

		++line;
		gt(31, line); cout << sc(186);
		cout << " No ";
		gt(36, line); cout << sc(186);
		cout << "   Class   ";
		gt(48, line); cout << sc(186);
		cout << "   Num   ";
		gt(58, line); cout << sc(186);
		cout << " Year ";
		gt(65, line); cout << sc(186);

		gt(31, line); cout << sc(186);
		gt(36, line); cout << sc(186);
		gt(48, line); cout << sc(186);
		gt(58, line); cout << sc(186);
		gt(65, line); cout << sc(186);

		++line;
		gt(31, line); cout << sc(204);
		for (int i = 1; i < 35; ++i)
			cout << sc(205);
		gt(36, line); cout << sc(206);
		gt(48, line); cout << sc(206);
		gt(58, line); cout << sc(206);
		gt(65, line); cout << sc(185);
		// Mo code cho nay
		classrooms *p = pclassid;
		for (int i = 1; i < value; ++i)
			p = p -> next;

		if (p == NULL) {
			gt(31, line); cout << sc(200);
			gt(36, line); cout << sc(202);
			gt(48, line); cout << sc(202);
			gt(58, line); cout << sc(202);
			gt(65, line); cout << sc(188);
			break;
		}

		int test = 8;
		for (int i = 1; i <= test; ++i){
			++line;
			//code
			int count = 0;
			profile *cur = pstudent;
			while (cur != NULL) {
				if (strcmp(cur->classroom, p->classroom) == 0)
					++count;
				cur = cur->next;
			}

			gt(31, line); cout << sc(186) << " " << i;
			gt(36, line); cout << sc(186) << "  " << p -> classroom;
			gt(48, line); cout << sc(186) << "   " << count;
			gt(58, line); cout << sc(186) << " " << p -> year;
			gt(65, line); cout << sc(186);

			++line;
			if (i != test){
				gt(31, line); cout << sc(204);
				for (int j = 1; j < 35; ++j)
					cout << sc(205);
				gt(36, line); cout << sc(206);
				gt(48, line); cout << sc(206);
				gt(58, line); cout << sc(206);
				gt(65, line); cout << sc(185);
			} else {
				gt(31, line); cout << sc(200);
				for (int j = 1; j < 35; ++j)
					cout << sc(205);
				gt(36, line); cout << sc(202);
				gt(48, line); cout << sc(202);
				gt(58, line); cout << sc(202);
				gt(65, line); cout << sc(188);
			}
			p = p -> next;
			if (p == NULL) {
				gt(31, line); cout << sc(200);
				gt(36, line); cout << sc(202);
				gt(48, line); cout << sc(202);
				gt(58, line); cout << sc(202);
				gt(65, line); cout << sc(188);
				break;
			}
		}
		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}

void show_enroll_course(subjects *p, int semester, int year, char *&auxilary){
	//10 30 7 5 5 5 5 6
	if (p == NULL) return;
	showcur(0);
	view_space();
	int line = 4;
	gt(10, line); 
	for (int i = 1; i <= 81; ++i)
		cout << sc(205);
	gt( 9, line); cout << sc(201);
	gt(20, line); cout << sc(203);
	gt(51, line); cout << sc(203);
	gt(59, line); cout << sc(203);
	gt(65, line); cout << sc(203);
	gt(71, line); cout << sc(203);
	gt(77, line); cout << sc(203);
	gt(83, line); cout << sc(203);
	gt(90, line); cout << sc(187);

	++line;
	gt( 9, line); cout << sc(186) << "Course ID";
	gt(20, line); cout << sc(186) << "             Name";
	gt(51, line); cout << sc(186) << "Creadit";
	gt(59, line); cout << sc(186) << "Start";
	gt(65, line); cout << sc(186) << " End";
	gt(71, line); cout << sc(186) << "Sess1";
	gt(77, line); cout << sc(186) << "Sess2";
	gt(83, line); cout << sc(186) << "Enroll";
	gt(90, line); cout << sc(186);

	++line;
	gt(10, line);
	for (int i = 1; i <= 81; ++i)
		cout << sc(205);
	gt( 9, line); cout << sc(204);
	gt(20, line); cout << sc(206);
	gt(51, line); cout << sc(206);
	gt(59, line); cout << sc(206);
	gt(65, line); cout << sc(206);
	gt(71, line); cout << sc(206);
	gt(77, line); cout << sc(206);
	gt(83, line); cout << sc(206);
	gt(90, line); cout << sc(185);

	showcur(0);

	while (p != NULL && (p -> year != year || p -> semester != semester))
		p = p -> next;
	if (p == NULL) return;
	for (int t = 1; t <= 8; ++t){
		++line;
		gt( 9, line); cout << sc(186) << p -> course_id;
		gt(20, line); cout << sc(186) << p -> name;
		gt(51, line); cout << sc(186) << p -> num_of_credits;
		gt(59, line); cout << sc(186) << p -> start;
		gt(65, line); cout << sc(186) << p -> end;
		gt(71, line); cout << sc(186) << p -> session[0].day;
		gt(77, line); cout << sc(186) << p -> session[1].day;
		gt(83, line); cout << sc(186) << p -> maximum << "/" << 50;
		gt(90, line); cout << sc(186);
		++line;
		if (t != 8){
			gt(10, line);
			for (int i = 1; i <= 81; ++i)
				cout << sc(205);
			gt( 9, line); cout << sc(204);
			gt(20, line); cout << sc(206);
			gt(51, line); cout << sc(206);
			gt(59, line); cout << sc(206);
			gt(65, line); cout << sc(206);
			gt(71, line); cout << sc(206);
			gt(77, line); cout << sc(206);
			gt(83, line); cout << sc(206);
			gt(90, line); cout << sc(185);
		} else {
			gt(10, line);
			for (int i = 1; i <= 81; ++i)
				cout << sc(205);
			gt( 9, line); cout << sc(200);
			gt(20, line); cout << sc(202);
			gt(51, line); cout << sc(202);
			gt(59, line); cout << sc(202);
			gt(65, line); cout << sc(202);
			gt(71, line); cout << sc(202);
			gt(77, line); cout << sc(202);
			gt(83, line); cout << sc(202);
			gt(90, line); cout << sc(188);
		}
		p = p -> next;
		if (p == NULL || p -> semester != semester || p -> year != year){
			gt( 9, line); cout << sc(200);
			gt(20, line); cout << sc(202);
			gt(51, line); cout << sc(202);
			gt(59, line); cout << sc(202);
			gt(65, line); cout << sc(202);
			gt(71, line); cout << sc(202);
			gt(77, line); cout << sc(202);
			gt(83, line); cout << sc(202);
			gt(90, line); cout << sc(188);
			break;
		}
	}
	gt(10, 3); 
	set_color(2);
	cout << "*Look at the table and input the id course you want.";
	set_color(7);
	char *content = new char[15];
	memcpy(content, "Course id", 10);
	char *unknow = new char[3];
	memcpy(unknow, " ", 2);
	print_information(content, unknow, 30 , 24, 14);
	gt(44, 25);
	showcur(1);
	cin >> auxilary;
	delete[] content;
	delete[] unknow;
	return;
}
