#include "project.h"

#define sc(a) static_cast<char>(a)
#define gt GoTo
void draw_button(int value, int maxlist){
	int color = 240;
	int line = 25;
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


		draw_button(value, maxlist);
		char key = getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}

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
		draw_button(value, maxlist);
		char key = getch();
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
		draw_button(value, maxlist);
		char key = getch();
		if (key == 77) value = (value + 8 < maxlist) ? value + 8 : value;
		if (key == 75) value = (value - 8 > 0) ? value - 8 : value;
		if (key == 27) return;
	}
	showcur(1);
}