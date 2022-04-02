#include "project.h"	 
using std::cout;
using std::cin;

char *int_to_char(long long x){
	int tmp = x, count = 0, base = 1;
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
	designSquare(12, 4, 3, 14, NULL, 7, 7);//Cread 58
	designSquare(28, 4, 3, 10, NULL, 7, 7);//Average 74
	designSquare(40, 4, 3, 10, NULL, 7, 7);//GPA 86

	int line = 7;
	int maxlist = 80;
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

	int tmp = line;
	int value = 1;
	while (true){
		line = tmp;
		showcur(0);
		
		/*
		profile *auxilary = pstudent;
		while (auxilary != NULL){
			if (auxilary -> id == id_student) break;
			auxilary = auxilary -> next;
		}

		subject2 *cur = auxilary -> psub2;
		for (int i = 1; i < value; ++i)
			cur = cur -> next;
		*/
	
		for (int t = 1; t <= 8; ++t){
			++line;
			gt( 4, line); cout << sc(186);
			gt(13, line); cout << sc(186);
			gt(20, line); cout << sc(186);
			gt(31, line); cout << sc(186);
			gt(62, line); cout << sc(186);
			gt(70, line); cout << sc(186);
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
			//cur = cur -> next;
		}
		

		draw_button(26, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}

void view_student_enroll_course(int id_student, profile *pstudent){
	// 4 30 10 20 7 6 8
	showcur(0);
	view_space();
	int line = 5;
	int maxlist = 80;
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

	int tmp = line;
	int value = 1;
	while (true){
		line = tmp;
		showcur(0);
		
		/*
		profile *auxilary = pstudent;
		while (auxilary != NULL){
			if (auxilary -> id == id_student) break;
			auxilary = auxilary -> next;
		}

		subject2 *cur = auxilary -> psub2;
		for (int i = 1; i < value; ++i)
			cur = cur -> next;
		*/
	
		for (int t = 1; t <= 8; ++t){
			++line;
			gt( 3, line); cout << sc(186);
			gt( 8, line); cout << sc(186);
			gt(39, line); cout << sc(186);
			gt(50, line); cout << sc(186);
			gt(71, line); cout << sc(186);
			gt(79, line); cout << sc(186);
			gt(86, line); cout << sc(186);
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
			//cur = cur -> next;
		}
		

		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}

void view_scoreboard_of_course(char *id_course, profile *pstudent){
	// 4 30 10 9 5
	showcur(0);
	view_space();
	int line = 5;
	int maxlist = 80;
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

void view_list_of_course(subjects *psubject, profile *pstudent){
	//10 30 7 5 5 5 5 6
	showcur(0);
	view_space();
	int line = 5;
	int maxlist = 80;
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

	int tmp = line;
	int value = 1;
	while (true){
		line = tmp;
		showcur(0);

		/*
		subjects *cur = psubject;
		for (int i = 1; i < value; ++i)
			cur = cur -> next;

		*/

		for (int t = 1; t <= 8; ++t){
			/*
			profile *cur1 = pstudent;
			int count = 0;
			while (cur1 != NULL){
				subject2 *auxilary = cur1 -> psub2;
				while (auxilary != NULL){
					if (strcmp(auxilary -> course_id, cur ->course_id) == 0){
						++count;
						break;
					}
					auxilary = auxilary -> next;
				}
				cur1 = cur1 -> next;
			}
			*/
			++line;
			gt( 9, line); cout << sc(186);
			gt(20, line); cout << sc(186);
			gt(51, line); cout << sc(186);
			gt(59, line); cout << sc(186);
			gt(65, line); cout << sc(186);
			gt(71, line); cout << sc(186);
			gt(77, line); cout << sc(186);
			gt(83, line); cout << sc(186);
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
	int maxlist = 80;
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
	gt(66, line); cout << sc(186) << "    Birth";
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

	int tmp = line;
	int value = 1;
	while (true){
		line = tmp;
		showcur(0);

		profile *cur = pstudent;
		//while (true/*cur != NULL*/)
		for (int x = 0; x < 8; ++x)
		{
			int count = value;
			//if (strcmp(cur -> classroom, classid) == 0){
				if (count < value + 8 && count >= value) {
					++line;
					gt(19, line); cout << sc(186) << " " << ((value < 10) ? "0" : "") << value;
					gt(24, line); cout << sc(186);//
					gt(55, line); cout << sc(186);//
					gt(66, line); cout << sc(186);//
					gt(79, line); cout << sc(186);//
					gt(87, line); cout << sc(186);//
				}
				++count;
			//}
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
		}
		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}

//lam lai ham nay
void view_student_in_course(char *id_course, profile *p){
	//head table
	//2 20 8 3 10
	int maxlist = 80;
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

	//code
	int value = 1;
	int endline = 7;
	int tmp = endline;
	while (true){
		endline = tmp;
		while (p != NULL){
			subject2 *cur = p -> psub2;
			bool dd = 0;
			while (cur != NULL){
				if (strcmp(id_course, cur -> course_id) == 0){
					dd = 1;
					break;
				}
				if (dd){
					++endline;
					int no = 0;
					GoTo(24, endline); cout << static_cast<char>(186) << no++ << static_cast<char>(186) 
						<< p -> last_name << " " << p -> first_name;
					GoTo(48, endline); cout << static_cast<char>(186) << p -> id;
					GoTo(57, endline); cout << static_cast<char>(186) << p -> gender;
					GoTo(61, endline); cout << static_cast<char>(186) 
						<< p -> dob.day << "/" << p ->dob.month << "/" << p -> dob.year;
					GoTo(72, endline); cout << static_cast<char>(186);
				}
			}
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

	showcur(0);
	int maxlist = 80; // duyet pstudent
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
	int value = 1;
	int tmp = line;
	while (true){
		line = tmp;
		showcur(0);
		// Mo code cho nay
		//classrooms *p = pclassid;
		//for (int i = 1; i <= value; ++i)
		//	p = p -> next;
		//

		int test = 8;
		for (int i = 1; i <= test; ++i){
			++line;
			//code
			gt(31, line); cout << sc(186) << " " << ((value < 10) ? "0" : "") << value;
			gt(36, line); cout << sc(186);// << "  " << p -> classroom;
			gt(48, line); cout << sc(186);// << "  " << count << "/" << count;
			gt(58, line); cout << sc(186);// << " " << p -> year;
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
			//p = p -> next;
			//if (p == NULL) break;
		}
		draw_button(25, value, maxlist);
		char key = _getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}
