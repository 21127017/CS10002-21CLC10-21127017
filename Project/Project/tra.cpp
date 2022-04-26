#include "project.h"

//-----------VIEW DESIGN SPACE-------------//
void set_color(int code) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}

int getkey() {
	char c = _getch();
	if (c == -32) {
		c = _getch();
		if (c == 72) {
			return 8; //top
		}
		if (c == 80) {
			return 2; //bottom
		}
		if (c == 75) {
			return 4; //left
		}
		if (c == 77) {
			return 6; //right
		}
	}
	if (c == 27) return 0; //ESC
	if (c == 13) return 5; //Enter
	return 100;
}

void GoTo(SHORT posX, SHORT posY) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = {posX, posY};
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void designSquare(SHORT posX, SHORT posY, int height, int width, char *content, int color1, int color2) {
	set_color(color1);
	GoTo(posX, posY); //cout -------------------
	cout << static_cast<char>(201);
	for (int i = 0; i < (width - 2); i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(187);

	for (int i = 1; i < (height - 1); i++) {
		GoTo(posX, (posY + i)); //cout |.........................|
		cout << static_cast<char>(186);
		cout << " ";
		set_color(color2);
		for (int j = 1; j < (width - 3); j++) {
			cout << " ";
		}
		set_color(color1);
		GoTo((posX + width - 1), (posY + i));
		cout << static_cast<char>(186);
	}

	GoTo(posX, (posY + height - 1)); //cout ---------------------
	cout << static_cast<char>(200);
	for (int i = 0; i < (width - 2); i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188);

	set_color(color2);
	if (content != nullptr) {
		//cout content of square
		int len;
		len = static_cast<int>(strlen(content));
		GoTo((posX + (width - len) / 2), (posY + (height - 1) / 2));
		cout << content;
	}
	set_color(7);
}

void view_space() {
	system("cls");
	GoTo(0, 0);

	cout << static_cast<char>(201);
	for (int i = 0; i < 86; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(203) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(203) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(203) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(187);

	GoTo(0, 1);

	cout << static_cast<char>(186);
	for (int j = 0; j < 86; j++) {
		cout << " ";
	}
	cout << static_cast<char>(186) << " " << static_cast<char>(196) << " ";
	cout << static_cast<char>(186) << " " << static_cast<char>(254) << " ";
	cout << static_cast<char>(186) << " X ";
	cout << static_cast<char>(186);

	GoTo(0, 2);

	cout << static_cast<char>(204);
	for (int i = 0; i < 86; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(202) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(202) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(202) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(185);

	GoTo(0, 3);
	for (int i = 0; i < 27; i++) {
		cout << static_cast<char>(186);
		for (int j = 0; j < 98; j++) {
			cout << " ";
		}
		cout << static_cast<char>(186) << endl;
	}

	cout << static_cast<char>(200);
	for (int i = 0; i < 98; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188);
}

void view_loginboard() {
	system("cls");
	view_space();

	GoTo(47, 9);
	cout << "LOGIN";

	char temp[200] = "USERNAME";
	designSquare(33, 10, 3, 12, temp, 7, 7);
	designSquare(45, 10, 3, 22, nullptr, 7, 7);

	memcpy(temp, "PASSWORD", 9);
	designSquare(33, 13, 3, 12, temp, 7, 7);
	designSquare(45, 13, 3, 22, nullptr, 7, 7);
}

void exitProgram() {
	view_space();
	set_color(14);
	GoTo(33, 14);
	cout << "THANK FOR USING OUR APPLICATION!";
	GoTo(32, 16);
	cout << "We hope you have a good experience.";
	set_color(7);
}

void print_option_1(int &choice) { //Board for teacher
	showcur(0);
	int key = 100;
	char temp[200];
	int i = 0;
	int num = 0;
	while (1) {
		view_space();
		set_color(14);
		GoTo(34, 3); cout << " __  __  _____  _   _  _   _ ";
		GoTo(34, 4); cout << "|  \\/  || ____|| \\ | || | | |";
		GoTo(34, 5); cout << "| |\\/| ||  _|  |  \\| || | | |";
		GoTo(34, 6); cout << "| |  | || |___ | |\\  || |_| |";
		GoTo(34, 7); cout << "|_|  |_||_____||_| \\_| \\___/ ";
		set_color(7);

		while (key != 5) {
			memcpy(temp, "Profile", 8);
			designSquare(27, 10, 3, 20, temp, 7, 7);

			memcpy(temp, "Logout", 7);
			designSquare(27, 14, 3, 20, temp, 7, 7);

			memcpy(temp, "Year", 5);
			designSquare(51, 10, 3, 20, temp, 7, 7);

			memcpy(temp, "Semester", 9);
			designSquare(51, 14, 3, 20, temp, 7, 7);

			memcpy(temp, "Class", 6);
			designSquare(51, 18, 3, 20, temp, 7, 7);

			memcpy(temp, "Course", 7);
			designSquare(27, 18, 3, 20, temp, 7, 7);

			memcpy(temp, "Student", 8);
			designSquare(27, 22, 3, 20, temp, 7, 7);

			memcpy(temp, "Guide", 6);
			designSquare(51, 22, 3, 20, temp, 7, 7);

			memcpy(temp, "Exit program", 13);
			designSquare(38, 26, 3, 20, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "Profile", 8);
				designSquare(27, 10, 3, 20, temp, 11, 432);
				num = 6;
				break;
			case 1:
				memcpy(temp, "Year", 5);
				designSquare(51, 10, 3, 20, temp, 11, 432);
				num = 1;
				break;
			case 2:
				memcpy(temp, "Logout", 7);
				designSquare(27, 14, 3, 20, temp, 11, 432);
				num = 0;
				break;
			case 3:
				memcpy(temp, "Semester", 9);
				designSquare(51, 14, 3, 20, temp, 11, 432);
				num = 2;
				break;
			case 4:
				memcpy(temp, "Course", 7);
				designSquare(27, 18, 3, 20, temp, 11, 432);
				num = 4;
				break;
			case 5:
				memcpy(temp, "Class", 6);
				designSquare(51, 18, 3, 20, temp, 11, 432);
				num = 3;
				break;
			case 6:
				memcpy(temp, "Student", 8);
				designSquare(27, 22, 3, 20, temp, 11, 432);
				num = 5;
				break;
			case 7:
				memcpy(temp, "Guide", 6);
				designSquare(51, 22, 3, 20, temp, 11, 432);
				num = 8;
				break;
			default:
				memcpy(temp, "Exit program", 13);
				designSquare(38, 26, 3, 20, temp, 11, 432);
				num = 7;
				break;
			}

			key = getkey();
			switch (key) {
			case 2:
				i += 2;
				break;
			case 4:
				i--;
				break;
			case 6:
				i++;
				break;
			case 8:
				i -= 2;
				break;
			default:
				break;
			}

			if (i < 0) i = 8;
			if (i > 8) i = 0;
		}

		choice = num;
		break;
	}
	showcur(1);
}

int inputNewPass(char *&oldpassword) {
	
	char temp_string[200], temp_str[200];

	memcpy(temp_str, "Are you sure to change your password?", 38);
	int a;
	announcement(temp_str, 1, a, 0);
	if (a != 1) return 0;

	view_space();
	memcpy(temp_str, "Old password:                         ", 39);
	designSquare(28, 8, 3, 42, temp_str, 7, 7);
	GoTo(44, 9);//input old password
	cin.getline(temp_string, 200);

	if (strcmp(temp_string, oldpassword) == 0) {
		//Old password is true, input new password
		memcpy(temp_str, "New password:                         ", 39);
		designSquare(28, 12, 3, 42, temp_str, 7, 7);
		memcpy(temp_str, "Confirm new password:                 ", 39);
		designSquare(28, 16, 3, 42, temp_str, 7, 7);

		GoTo(44, 13);
		cin.getline(temp_string, 200);
		GoTo(52, 17);
		cin.getline(temp_str, 200);

		if (strcmp(temp_string, temp_str) == 0) { //Ok
			memcpy(oldpassword, temp_string, strlen(temp_string) + 1);
			memcpy(temp_str, "Your password has been changed!", 32);
			announcement(temp_str, 0, a, 1);
			return 1;
		} else {
			memcpy(temp_str, "Do you want change your password again?", 40);
			int choice;
			announcement(temp_str, 1, choice, -1);
			if (choice != 1)
				return -1;
		}
	} else {
		memcpy(temp_str, "Wrong password!!!", 18);
		announcement(temp_str, 0, a, -1);
		return -1;
	}
	return -1;
}

void changePassword(int changed_id) {
	ifstream inp;
	inp.open("login_information.csv");

	char temp_char;
	char temp_string[200];

	int N = 0; //read number of accounts in file
	inp >> N >> temp_char >> temp_char >> temp_char;
	inp.ignore();

	login_information *inf = new login_information[N + 1]; //allocate N slots

	int i = 0;
	int k;
	while (!inp.eof()) {
		inp >> inf[i].role;
		if (inf[i].role == 0) break;
		inp >> temp_char; // read ,

		inp.getline(temp_string, 200, ',');
		inf[i].username = new char[strlen(temp_string) + 1]; //allocate username
		memcpy(inf[i].username, temp_string, strlen(temp_string) + 1);

		inp.getline(temp_string, 200, ',');
		inf[i].password = new char[strlen(temp_string) + 1]; //allocate password
		memcpy(inf[i].password, temp_string, strlen(temp_string) + 1);

		inp >> inf[i].user_id;
		if (changed_id == inf[i].user_id) k = i;
		inp.ignore();
		i++;
	}
	inp.close();

	int check = 0;
	do {
		check = inputNewPass(inf[k].password);
		if (check == 1) {
			ofstream out;
			out.open("login_information.csv");
			out << N << ",,," << endl;
			for (int i = 0; i < N; i++) {
				out << inf[i].role << "," << inf[i].username << "," << inf[i].password << "," << inf[i].user_id << endl;
			}
			out << "0,,,";
			out.close();
			break;
		} else if (check == 0) {
			break;
		}
	} while (1);

	for (int i = 0; i < N; i++) {
		delete[] inf[i].username;
		delete[] inf[i].password;
	}
	delete[] inf;
}

void login(int &role, int &id_profile) {
	ifstream inp;
	inp.open("login_information.csv");

	char temp_char;
	char temp_string[200];

	int N; //number of account in file
	view_loginboard();
	//input username from keyboard
	char *username;
	GoTo(47, 11);
	cin.getline(temp_string, 200);
	username = new char[strlen(temp_string) + 1];
	memcpy(username, temp_string, strlen(temp_string) + 1);

	//input password from keyboard
	char *password;
	GoTo(47, 14);
	cin.getline(temp_string, 200);
	password = new char[strlen(temp_string) + 1];
	memcpy(password, temp_string, strlen(temp_string) + 1);

	login_information inf = {0, 0, 0, 0};
	inp >> N >> temp_char >> temp_char >> temp_char;
	inp.ignore();
	while (!inp.eof()) {
		inp >> inf.role;
		if (inf.role == 0) {
			role = 3;
			id_profile = 0;
			GoTo(43, 16);
			set_color(4);
			cout << "LOGIN FAILED";
			set_color(7);
			break;
		} // end of file, cannot find account properly
		inp >> temp_char; // read ,

		//read username in file
		inp.getline(temp_string, 200, ',');
		inf.username = new char[strlen(temp_string) + 1];
		memcpy(inf.username, temp_string, strlen(temp_string) + 1);

		//read password in file
		inp.getline(temp_string, 200, ',');
		inf.password = new char[strlen(temp_string) + 1];
		memcpy(inf.password, temp_string, strlen(temp_string) + 1);

		inp >> inf.user_id;
		inp.ignore();

		if (!strcmp(inf.username, username)) {
			if (!strcmp(inf.password, password)) {//login successful
				role = inf.role;
				id_profile = inf.user_id;
				GoTo(40, 16);
				set_color(266);
				cout << "LOGIN SUCCESSFULLY";
				set_color(7);
				delete[] inf.username;
				delete[] inf.password;
				break;
			} else {//wrong password
				role = 3;
				id_profile = 0;
				GoTo(41, 16);
				set_color(4);
				cout << "WRONG PASSWORD";
				set_color(7);
				delete[] inf.username;
				delete[] inf.password;
				break;
			}
		}
		delete[] inf.username;
		delete[] inf.password;
	}
	delete[] username;
	delete[] password;
	inp.close();
}

void print_year_function(int &choice/*profile *&pstudent, subjects *&psubject, classrooms *&pclassid, int &classroom, int &semester, int &year*/) {
	showcur(0);
	int key = 100;
	char temp[200];
	int i = 0;
	int num = 0;
	while (1) {
		view_space();
		set_color(14);
		GoTo(21, 3); cout << "__   __ _____     _     ____    _____  ____  ___  _____ ";
		GoTo(21, 4); cout << "\\ \\ / /| ____|   / \\   |  _ \\  | ____||  _ \\|_ _||_   _|";
		GoTo(21, 5); cout << " \\ V / |  _|    / _ \\  | |_) | |  _|  | | | || |   | |  ";
		GoTo(21, 6); cout << "  | |  | |___  / ___ \\ |  _ <  | |___ | |_| || |   | |  ";
		GoTo(21, 7); cout << "  |_|  |_____|/_/   \\_\\|_| \\_\\ |_____||____/|___|  |_|  ";
		set_color(7);
		while (key != 5) {
			memcpy(temp, "Create new school year", 23);
			designSquare(34, 12, 3, 28, temp, 7, 7);

			memcpy(temp, "View school year", 17);
			designSquare(34, 16, 3, 28, temp, 7, 7);

			memcpy(temp, "Back to menu", 13);
			designSquare(34, 20, 3, 28, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "Create new school year", 23);
				designSquare(34, 12, 3, 28, temp, 11, 432);
				num = 1;
				break;
			case 1:
				memcpy(temp, "View school year", 17);
				designSquare(34, 16, 3, 28, temp, 11, 432);
				num = 2;
				break;
			default:
				memcpy(temp, "Back to menu", 13);
				designSquare(34, 20, 3, 28, temp, 11, 432);
				num = 3;
				break;
			}

			key = getkey();
			switch (key) {
			case 2:
				i++;
				break;
			case 4:
				i--;
				break;
			case 6:
				i++;
				break;
			case 8:
				i--;
				break;
			default:
				break;
			}

			if (i < 0) i = 2;
			if (i > 2) i = 0;
		}
		choice = num;
		break;
	}
	showcur(1);
}

void print_semester_function(int &choice/*profile *&pstudent, subjects *&psubject, int &semester, int &year*/) {
	showcur(0);
	int key = 100;
	char temp[200];
	int i = 0;
	int num = 0;
	while (1) {
		view_space();
		set_color(14);
		GoTo(8, 3); cout << " ____   _____  __  __  _____  ____  _____  _____  ____    _____  ____  ___  _____ ";
		GoTo(8, 4); cout << "/ ___| | ____||  \\/  || ____|/ ___||_   _|| ____||  _ \\  | ____||  _ \\|_ _||_   _|";
		GoTo(8, 5); cout << "\\___ \\ |  _|  | |\\/| ||  _|  \\___ \\  | |  |  _|  | |_) | |  _|  | | | || |   | |  ";
		GoTo(8, 6); cout << " ___) || |___ | |  | || |___  ___) | | |  | |___ |  _ <  | |___ | |_| || |   | |  ";
		GoTo(8, 7); cout << "|____/ |_____||_|  |_||_____||____/  |_|  |_____||_| \\_\\ |_____||____/|___|  |_|  ";
		set_color(7);
		while (key != 5) {
			memcpy(temp, "Create new semester", 20);
			designSquare(35, 12, 3, 26, temp, 7, 7);

			memcpy(temp, "View semester", 14);
			designSquare(35, 16, 3, 26, temp, 7, 7);

			memcpy(temp, "Back to menu", 13);
			designSquare(35, 20, 3, 26, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "Create new semester", 20);
				designSquare(35, 12, 3, 26, temp, 11, 432);
				num = 1;
				break;
			case 1:
				memcpy(temp, "View semester", 14);
				designSquare(35, 16, 3, 26, temp, 11, 432);
				num = 2;
				break;
			default:
				memcpy(temp, "Back to menu", 13);
				designSquare(35, 20, 3, 26, temp, 11, 432);
				num = 3;
				break;
			}

			key = getkey();
			switch (key) {
			case 2:
				i++;
				break;
			case 4:
				i--;
				break;
			case 6:
				i++;
				break;
			case 8:
				i--;
				break;
			default:
				break;
			}

			if (i < 0) i = 2;
			if (i > 2) i = 0;
		}
		choice = num;
		break;
	}
	showcur(1);
}

void print_class_function(int &choice/*profile *&pstudent, classrooms *&pclassid, int &semester*/) {
	showcur(0);
	int key = 100;
	char temp[200];
	int i = 0;
	int num = 0;
	while (1) {
		view_space();
		set_color(14);
		GoTo(18, 3); cout << "  ____  _         _     ____  ____    _____  ____  ___  _____ ";
		GoTo(18, 4); cout << " / ___|| |       / \\   / ___|/ ___|  | ____||  _ \\|_ _||_   _|";
		GoTo(18, 5); cout << "| |    | |      / _ \\  \\___ \\\\___ \\  |  _|  | | | || |   | |  ";
		GoTo(18, 6); cout << "| |___ | |___  / ___ \\  ___) |___) | | |___ | |_| || |   | |  ";
		GoTo(18, 7); cout << " \\____||_____|/_/   \\_\\|____/|____/  |_____||____/|___|  |_|  ";
		set_color(7);
		while (key != 5) {
			memcpy(temp, "Create new class", 17);
			designSquare(17, 11, 3, 30, temp, 7, 7);

			memcpy(temp, "Add student to class", 21);
			designSquare(17, 15, 3, 30, temp, 7, 7);

			memcpy(temp, "Remove student from class", 26);
			designSquare(17, 19, 3, 30, temp, 7, 7);

			memcpy(temp, "View list of class", 19);
			designSquare(50, 11, 3, 30, temp, 7, 7);

			memcpy(temp, "View student in class", 22); // view student in class
			designSquare(50, 15, 3, 30, temp, 7, 7);

			memcpy(temp, "Back to menu", 13);
			designSquare(50, 19, 3, 30, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "Create new class", 17);
				designSquare(17, 11, 3, 30, temp, 11, 432);
				num = 0;
				break;
			case 1:
				memcpy(temp, "View list of class", 19);
				designSquare(50, 11, 3, 30, temp, 11, 432);
				num = 3;
				break;
			case 2:
				memcpy(temp, "Add student to class", 21);
				designSquare(17, 15, 3, 30, temp, 11, 432);
				num = 1;
				break;
			case 3:
				memcpy(temp, "View student in class", 22);
				designSquare(50, 15, 3, 30, temp, 11, 432);
				num = 4;
				break;
			case 4:
				memcpy(temp, "Remove student from class", 26);
				designSquare(17, 19, 3, 30, temp, 11, 432);
				num = 2;
				break;
			default:
				memcpy(temp, "Back to menu", 13);
				designSquare(50, 19, 3, 30, temp, 11, 432);
				num = 6;
				break;
			}

			key = getkey();
			switch (key) {
			case 2:
				i += 2;
				break;
			case 4:
				i--;
				break;
			case 6:
				i++;
				break;
			case 8:
				i -= 2;
				break;
			default:
				break;
			}

			if (i < 0) i = 5;
			if (i > 5) i = 0;
		}
		choice = num;
		break;
	}
	showcur(1);
}

void print_subject_function(int &choice/*profile *&pstudent, subjects *&psubject, int &semester, int &year*/) {
	showcur(0);
	int key = 100;
	char temp[200];
	int i = 0;
	int num = 0;
	while (1) {
		view_space();
		set_color(14);
		GoTo(12, 3); cout << " ____   _   _  ____       _  _____  ____  _____   _____  ____  ___  _____ ";
		GoTo(12, 4); cout << "/ ___| | | | || __ )     | || ____|/ ___||_   _| | ____||  _ \\|_ _||_   _|";
		GoTo(12, 5); cout << "\\___ \\ | | | ||  _ \\  _  | ||  _| | |      | |   |  _|  | | | || |   | |  ";
		GoTo(12, 6); cout << " ___) || |_| || |_) || |_| || |___| |___   | |   | |___ | |_| || |   | |  ";
		GoTo(12, 7); cout << "|____/  \\___/ |____/  \\___/ |_____|\\____|  |_|   |_____||____/|___|  |_|  ";
		set_color(7);
		while (key != 5) {
			memcpy(temp, "Add new course", 15);
			designSquare(17, 10, 3, 30, temp, 7, 7);

			memcpy(temp, "Remove course", 14);
			designSquare(17, 14, 3, 30, temp, 7, 7);

			memcpy(temp, "View list of course", 20);
			designSquare(17, 18, 3, 30, temp, 7, 7);

			memcpy(temp, "Export file", 12);
			designSquare(17, 22, 3, 30, temp, 7, 7);

			memcpy(temp, "Update mark", 12);
			designSquare(50, 10, 3, 30, temp, 7, 7);

			memcpy(temp, "Update course information", 26);
			designSquare(50, 14, 3, 30, temp, 7, 7);

			memcpy(temp, "View student in course", 23);
			designSquare(50, 18, 3, 30, temp, 7, 7);
				
			memcpy(temp, "Back to menu", 13);
			designSquare(50, 22, 3, 30, temp, 7, 7);
			switch (i) {
			case 0:
				memcpy(temp, "Add new course", 15);
				designSquare(17, 10, 3, 30, temp, 11, 432);
				num = 1;
				break;
			case 1:
				memcpy(temp, "Update mark", 12);
				designSquare(50, 10, 3, 30, temp, 11, 432);
				num = 4;
				break;
			case 2:
				memcpy(temp, "Remove course", 14);
				designSquare(17, 14, 3, 30, temp, 11, 432);
				num = 2;
				break;
			case 3:
				memcpy(temp, "Update course information", 26);
				designSquare(50, 14, 3, 30, temp, 11, 432);
				num = 5;
				break;
			case 4:
				memcpy(temp, "View list of course", 20);
				designSquare(17, 18, 3, 30, temp, 11, 432);
				num = 3;
				break;
			case 5:
				memcpy(temp, "View student in course", 23);
				designSquare(50, 18, 3, 30, temp, 11, 432);
				num = 6;
				break;
			case 6:
				memcpy(temp, "Export file", 12);
				designSquare(17, 22, 3, 30, temp, 11, 432);
				num = 8;
				break;
			default:
				memcpy(temp, "Back to menu", 13);
				designSquare(50, 22, 3, 30, temp, 11, 432);
				num = 7;
				break;
			}

			key = getkey();
			switch (key) {
			case 2:
				i += 2;
				break;
			case 4:
				i--;
				break;
			case 6:
				i++;
				break;
			case 8:
				i -= 2;
				break;
			default:
				break;
			}

			if (i < 0) i = 7;
			if (i > 7) i = 0;
		}
		choice = num;
		break;
	}
	showcur(1);
}

void print_undergraduate_function(int &choice/*int &no, profile *&pstudent, subjects *&psubject, int &semester, int &classroom, int &year*/) {
	showcur(0);
	int key = 100;
	char temp[200];
	int i = 0;
	int num = 0;
	while (1) {
		view_space();
		set_color(14);
		GoTo(12, 3); cout << " ____  _____  _   _  ____   _____  _   _  _____   _____  ____  ___  _____ ";
		GoTo(12, 4); cout << "/ ___||_   _|| | | ||  _ \\ | ____|| \\ | ||_   _| | ____||  _ \\|_ _||_   _|";
		GoTo(12, 5); cout << "\\___ \\  | |  | | | || | | ||  _|  |  \\| |  | |   |  _|  | | | || |   | |  ";
		GoTo(12, 6); cout << " ___) | | |  | |_| || |_| || |___ | |\\  |  | |   | |___ | |_| || |   | |  ";
		GoTo(12, 7); cout << "|____/  |_|   \\___/ |____/ |_____||_| \\_|  |_|   |_____||____/|___|  |_|  ";
		set_color(7);
		while (key != 5) {
			memcpy(temp, "Import file csv", 16);
			designSquare(36, 10, 3, 26, temp, 7, 7);

			memcpy(temp, "Add student manual", 19);
			designSquare(36, 14, 3, 26, temp, 7, 7);

			memcpy(temp, "Remove student", 15);
			designSquare(36, 18, 3, 26, temp, 7, 7);

			memcpy(temp, "View list of student", 21);
			designSquare(36, 22, 3, 26, temp, 7, 7);

			memcpy(temp, "Back to menu", 13);
			designSquare(36, 26, 3, 26, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "Import file csv", 16);
				designSquare(36, 10, 3, 26, temp, 11, 432);
				num = 1;
				break;
			case 1:
				memcpy(temp, "Add student manual", 19);
				designSquare(36, 14, 3, 26, temp, 11, 432);
				num = 2;
				break;
			case 2:
				memcpy(temp, "Remove student", 15);
				designSquare(36, 18, 3, 26, temp, 11, 432);
				num = 3;
				break;
			case 3:
				memcpy(temp, "View list of student", 21);
				designSquare(36, 22, 3, 26, temp, 11, 432);
				num = 4;
				break;
			default:
				memcpy(temp, "Back to menu", 13);
				designSquare(36, 26, 3, 26, temp, 11, 432);
				num = 5;
				break;
			}

			key = getkey();
			switch (key) {
			case 2:
				i++;
				break;
			case 4:
				i--;
				break;
			case 6:
				i++;
				break;
			case 8:
				i--;
				break;
			default:
				break;
			}

			if (i < 0) i = 4;
			if (i > 4) i = 0;
		}
		choice = num;
		break;
	}
	showcur(1);
}

void announcement(char *content, bool yesno, int &num, int title) {
	showcur(0);
	GoTo(24, 9);
	cout << static_cast<char>(201);
	for (int i = 0; i < 36; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(203) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(203) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(203) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(187);

	GoTo(24, 10);

	cout << static_cast<char>(186);
	for (int j = 0; j < 36; j++) {
		cout << " ";
	}
	cout << static_cast<char>(186) << " " << static_cast<char>(196) << " ";
	cout << static_cast<char>(186) << " " << static_cast<char>(254) << " ";
	cout << static_cast<char>(186) << " X ";
	cout << static_cast<char>(186);

	GoTo(24, 11);

	cout << static_cast<char>(204);
	for (int i = 0; i < 36; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(202) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(202) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(202) << static_cast<char>(205) << static_cast<char>(205) << static_cast<char>(205);
	cout << static_cast<char>(185);

	for (int i = 0; i < 8; i++) {
		GoTo(24, 12 + i);
		cout << static_cast<char>(186);
		for (int j = 0; j < 48; j++) {
			cout << " ";
		}
		cout << static_cast<char>(186) << endl;
	}

	GoTo(24, 20);
	cout << static_cast<char>(200);
	for (int i = 0; i < 48; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188);

	if (title == 1) {
		set_color(10);
		GoTo(26, 10);
		cout << "Success !!!";
		set_color(7);
	} else if (title == -1) {
		set_color(4);
		GoTo(26, 10);
		cout << "Failure !!!";
		set_color(7);
	}

	set_color(14);
	if (content != nullptr) {
		//cout content of square
		int len = static_cast<int>(strlen(content));
		GoTo((24 + (51 - len) / 2), 13);
		cout << content;
	}
	set_color(7);
	if (yesno) {
		int key = 100;
		char temp[200];
		int i = 0;

		while (key != 5) {
			memcpy(temp, "YES", 4);
			designSquare(34, 16, 3, 10, temp, 7, 7);

			memcpy(temp, "NO", 3);
			designSquare(54, 16, 3, 10, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "YES", 4);
				designSquare(34, 16, 3, 10, temp, 4, 79);
				num = 1;
				break;
			default:
				memcpy(temp, "NO", 3);
				designSquare(54, 16, 3, 10, temp, 4, 79);
				num = 2;
				break;
			}

			key = getkey();
			switch (key) {
			case 2:
				i++;
				break;
			case 4:
				i--;
				break;
			case 6:
				i++;
				break;
			case 8:
				i--;
				break;
			default:
				break;
			}

			if (i < 0) i = 1;
			if (i > 1) i = 0;
		}
	} else {
		GoTo(32, 17);
		set_color(4);
		system("pause");
		set_color(7);
	}
	showcur(1);
}

void print_option_2(int &choice){
	showcur(0);
 	//system("cls");
 	//cout << "Choose your action: " << endl;
 	//cout << "\t0. Log out." << endl;
	//
	// just ->>> COURSE num == 1
 	//cout << "\t1. Enroll Course." << endl;
 	//cout << "\t2. Remove Course." << endl;
 	//cout << "\t3. View list of course." << endl;
	// 
 	//cout << "\t2. View scoreboard." << endl;
 	//cout << "\t3. View my profile." << endl;
 	//cout << "\t4 Exit program." << endl;
	// GUIDE -> num == 5
 	//return;

	int key = 100;
	char temp[200];
	int i = 0;
	int num = 0;
	while (1) {
		view_space();
		set_color(14);
		GoTo(34, 3); cout << " __  __  _____  _   _  _   _ ";
		GoTo(34, 4); cout << "|  \\/  || ____|| \\ | || | | |";
		GoTo(34, 5); cout << "| |\\/| ||  _|  |  \\| || | | |";
		GoTo(34, 6); cout << "| |  | || |___ | |\\  || |_| |";
		GoTo(34, 7); cout << "|_|  |_||_____||_| \\_| \\___/ ";
		set_color(7);

		while (key != 5) {
			memcpy(temp, "Profile", 8);
			designSquare(27, 12, 3, 20, temp, 7, 7);

			memcpy(temp, "Guide", 6);
			designSquare(27, 16, 3, 20, temp, 7, 7);

			memcpy(temp, "Logout", 7);
			designSquare(27, 20, 3, 20, temp, 7, 7);

			memcpy(temp, "Course", 7);
			designSquare(51, 12, 3, 20, temp, 7, 7);

			memcpy(temp, "Scoreboard", 11);
			designSquare(51, 16, 3, 20, temp, 7, 7);

			memcpy(temp, "Exit program", 13);
			designSquare(51, 20, 3, 20, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "Profile", 8);
				designSquare(27, 12, 3, 20, temp, 11, 432);
				num = 3;
				break;
			case 1:
				memcpy(temp, "Course", 7);
				designSquare(51, 12, 3, 20, temp, 11, 432);
				num = 1;
				break;
			case 2:
				memcpy(temp, "Guide", 6);
				designSquare(27, 16, 3, 20, temp, 11, 432);
				num = 5;
				break;
			case 3:
				memcpy(temp, "Scoreboard", 11);
				designSquare(51, 16, 3, 20, temp, 11, 432);
				num = 2;
				break;
			case 4:
				memcpy(temp, "Logout", 7);
				designSquare(27, 20, 3, 20, temp, 11, 432);
				num = 0;
				break;
			default:
				memcpy(temp, "Exit program", 13);
				designSquare(51, 20, 3, 20, temp, 11, 432);
				num = 4;
				break;
			}

			key = getkey();
			switch (key) {
			case 2:
				i += 2;
				break;
			case 4:
				i--;
				break;
			case 6:
				i++;
				break;
			case 8:
				i -= 2;
				break;
			default:
				break;
			}

			if (i < 0) i = 5;
			if (i > 5) i = 0;
		}

		choice = num;
		break;
	}
	showcur(1);
 }

 void view_guide() {
	 view_space();
	 GoTo(47, 1); cout << "Guide";
	 //cho chot data da
	 /*
	 -Navigate the menus with your arrow keys
- Log Out: exit this account and log in with a different one.
if Student:
- Profile: View your current profile and/or change your password.
- Course:
+ View list of course: 
+ Enroll course: sign up for a new course.
+ Remove course: remove a course from your current list.
+ View list of course: see what courses you are currently in.
Scoreboard: View your study results.
if staff:
- Year: Create a new school year or view existing ones.
- Semester: create a new semester or view existing ones.
- Course:
+ Add a new course to the list.
+ Update the marks of students in the courses.
+ Remove a course from the current list.
+ View the current list of courses.
+ View students from a course.
+ Export the list of students into a csv file.
- Class:
+ Create a new class.
+ Add/Remove student from class.
+ View a list of existing classes.
+ View the list of students from a class.
- Student:
+ Import csv: add a list of students from a csv file into the program.
+ Add a student manually from keyboard.
+ Remove students.
+ View a list of students.

	 */
 }

 void print_course_function(int &choice) {
	 showcur(0);
	 int key = 100;
	 char temp[200];
	 int i = 0;
	 int num = 0;
	 while (1) {
		 view_space();
		 set_color(14);
		 GoTo(31, 3); cout << "  ____ ___  _   _ ____  ____  _____ ";
		 GoTo(31, 4); cout << " / ___/ _ \\| | | |  _ \\/ ___|| ____|";
		 GoTo(31, 5); cout << "| |  | | | | | | | |_) \\___ \\|  _|  ";
		 GoTo(31, 6); cout << "| |__| |_| | |_| |  _ < ___) | |___ ";
		 GoTo(31, 7); cout << " \\____\\___/ \\___/|_| \\_\\____/|_____|";
		 set_color(7);
		 while (key != 5) {
			 memcpy(temp, "View list of course", 20);
			 designSquare(34, 10, 3, 30, temp, 7, 7);

			 memcpy(temp, "Enroll course", 14);
			 designSquare(34, 14, 3, 30, temp, 7, 7);

			 memcpy(temp, "Remove course", 14);
			 designSquare(34, 18, 3, 30, temp, 7, 7);

			 memcpy(temp, "View list enrolled courses", 27);
			 designSquare(34, 22, 3, 30, temp, 7, 7);

			 memcpy(temp, "Back to menu", 13);
			 designSquare(34, 26, 3, 30, temp, 7, 7);

			 switch (i) {
			 case 0:
				 memcpy(temp, "View list of course", 20);
				 designSquare(34, 10, 3, 30, temp, 11, 432);
				 num = 0;
				 break;
			 case 1:
				 memcpy(temp, "Enroll course", 14);
				 designSquare(34, 14, 3, 30, temp, 11, 432);
				 num = 1;
				 break;
			 case 2:
				 memcpy(temp, "Remove course", 14);
				 designSquare(34, 18, 3, 30, temp, 11, 432);
				 num = 2;
				 break;
			 case 3:
				 memcpy(temp, "View list enrolled courses", 27);
				 designSquare(34, 22, 3, 30, temp, 11, 432);
				 num = 3;
				 break;
			 default:
				 memcpy(temp, "Back to menu", 13);
				 designSquare(34, 26, 3, 30, temp, 11, 432);
				 num = 4;
				 break;
			 }

			 key = getkey();
			 switch (key) {
			 case 2:
				 i++;
				 break;
			 case 4:
				 i--;
				 break;
			 case 6:
				 i++;
				 break;
			 case 8:
				 i--;
				 break;
			 default:
				 break;
			 }

			 if (i < 0) i = 4;
			 if (i > 4) i = 0;
		 }
		 choice = num;
		 break;
	 }
	 showcur(1);
 }

 bool logout() {
	 char temp[200] = "";
	 int choice = 0;
	 memcpy(temp, "Do you want to log out?", 24);
	 announcement(temp, 1, choice, 0);
	 if (choice == 1) {
		 return true;
	 } else return false;
 }

 void export_to_file(profile *pstudent, subjects *psubject) {
	 if (!pstudent || !psubject) return;
	 char temp[200];
	 char *course_id;
	 int choice = 0;

	 memcpy(temp, "Input filename:                               ", 47);
	 designSquare(24, 16, 3, 50, temp, 7, 7);
	 memcpy(temp, "Input the course id:                          ", 47);
	 designSquare(24, 20, 3, 50, temp, 7, 7);

	 GoTo(42, 17);
	 cin.getline(temp, 200);
	 ofstream fout;
	 fout.open(temp);

	 GoTo(47, 21);
	 cin.getline(temp, 200);
	 course_id = new char[strlen(temp) + 1];
	 memcpy(course_id, temp, strlen(temp) + 1);

	 profile *curstu = pstudent;
	 subjects *cursub = psubject;

	 while (cursub) {
		 if (strcmp(course_id, cursub->course_id) == 0) {
			 break;
		 }
		 cursub = cursub->next;
	 }
	 if (!cursub) {
		 memcpy(temp, "Cannot find the courseid!", 26);
		 announcement(temp, 0, choice, -1);
		 delete [] course_id;
		 return;
	 }

	 int count = 0;
	 while (curstu) {
		 for (subject2 *cur = curstu->psub2; cur; cur = cur->next) {
			 if (strcmp(cur->course_id, course_id) == 0) {
				 fout << ++count << "," << curstu->id << "," << curstu->last_name << "," << curstu->first_name << "," << cur->score << "," << endl;
				 break;
			 }
		 }
		 curstu = curstu->next;
	 }
	 memcpy(temp, "Export successfully!", 21);
	 announcement(temp, 0, choice, 1);
	 delete[]course_id;
	 fout.close();
 }