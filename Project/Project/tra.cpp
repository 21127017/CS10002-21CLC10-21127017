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
	COORD Position;
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
		int len = strlen(content);
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

			memcpy(temp, "Subject", 8);
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
				num = 9;
				break;
			case 3:
				memcpy(temp, "Semester", 9);
				designSquare(51, 14, 3, 20, temp, 11, 432);
				num = 2;
				break;
			case 4:
				memcpy(temp, "Subject", 8);
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
}

bool inputNewPass(char *&oldpassword) {
	//input old password
	char temp_string[200], temp_str[200];
Again:
	cout << "Are you sure to change your password?";
	cout << endl << "\t1. Sure!" << endl << "\t2. No." << endl << "\t=> Input:";
	int a;
	cin >> a;
	if (a != 1) return false;

	cout << "Old password: ";
	cin.ignore();
	cin.getline(temp_string, 200);

	if (strcmp(temp_string, oldpassword) == 0) {
		//Old password is true, input new password
		cout << "New password: ";
		cin.getline(temp_string, 200);
		cout << "Confirm new password: ";
		cin.getline(temp_str, 200);

		if (strcmp(temp_string, temp_str) == 0) { //Ok
			memcpy(oldpassword, temp_string, strlen(temp_string) + 1);
			cout << "Successfully!";
			return true;
		} else {
			cout << "Confirm error!";
			cout << endl << "Do you want change your password again?";
			cout << endl << "\t1. Sure!" << endl << "\t2. No." << endl << "\t=> Input:";
			int choice;
			cin >> choice;
			if (choice == 1) {
				goto Again;
			} else
				return false;
		}
	} else {
		cout << "Wrong password";
		return false;
	}
}

void changePassword(const int &changed_id) {
	ifstream inp;
	inp.open("login_information.csv");

	char temp_char;
	char temp_string[200];

	int N = 0; //read number of accounts in file
	inp >> N >> temp_char >> temp_char >> temp_char;
	inp.ignore();

	login_information *inf = new login_information[N + 1]; //allocate N slots

	int i = 0;
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
		inp.ignore();
		i++;
	}
	inp.close();

	int k = changed_id - 1;
	if (inputNewPass(inf[k].password)) {
		ofstream out;
		out.open("login_information.csv");
		out << N << ",,," << endl;
		for (int i = 0; i < N; i++) {
			out << inf[i].role << "," << inf[i].username << "," << inf[i].password << "," << inf[i].user_id << endl;
		}
		out << "0,,,";
		out.close();
	}

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
	GoTo(46, 11);
	cin.getline(temp_string, 200);
	username = new char[strlen(temp_string) + 1];
	memcpy(username, temp_string, strlen(temp_string) + 1);

	//input password from keyboard
	char *password;
	GoTo(46, 14);
	cin.getline(temp_string, 200);
	password = new char[strlen(temp_string) + 1];
	memcpy(password, temp_string, strlen(temp_string) + 1);

	login_information inf;
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
}

void print_semester_function(int &choice/*profile *&pstudent, subjects *&psubject, int &semester, int &year*/) {
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
}

void print_class_function(int &choice/*profile *&pstudent, classrooms *&pclassid, int &semester*/) {
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

			memcpy(temp, "View scoreboard of class", 25);
			designSquare(50, 15, 3, 30, temp, 7, 7);

			memcpy(temp, "Back to menu", 13);
			designSquare(50, 19, 3, 30, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "Create new class", 17);
				designSquare(17, 11, 3, 30, temp, 11, 432);
				num = 1;
				break;
			case 1:
				memcpy(temp, "View list of class", 19);
				designSquare(50, 11, 3, 30, temp, 11, 432);
				num = 2;
				break;
			case 2:
				memcpy(temp, "Add student to class", 21);
				designSquare(17, 15, 3, 30, temp, 11, 432);
				num = 3;
				break;
			case 3:
				memcpy(temp, "View scoreboard of class", 25);
				designSquare(50, 15, 3, 30, temp, 11, 432);
				num = 4;
				break;
			case 4:
				memcpy(temp, "Remove student from class", 26);
				designSquare(17, 19, 3, 30, temp, 11, 432);
				num = 5;
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
}

void print_subject_function(int &choice/*profile *&pstudent, subjects *&psubject, int &semester, int &year*/) {
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
			designSquare(17, 11, 3, 30, temp, 7, 7);

			memcpy(temp, "Remove course", 14);
			designSquare(17, 15, 3, 30, temp, 7, 7);

			memcpy(temp, "View list of course", 20);
			designSquare(17, 19, 3, 30, temp, 7, 7);

			memcpy(temp, "Update mark", 12);
			designSquare(50, 11, 3, 30, temp, 7, 7);

			memcpy(temp, "Update course information", 26);
			designSquare(50, 15, 3, 30, temp, 7, 7);

			memcpy(temp, "Back to menu", 13);
			designSquare(50, 19, 3, 30, temp, 7, 7);

			switch (i) {
			case 0:
				memcpy(temp, "Add new course", 15);
				designSquare(17, 11, 3, 30, temp, 11, 432);
				num = 1;
				break;
			case 1:
				memcpy(temp, "Update mark", 12);
				designSquare(50, 11, 3, 30, temp, 11, 432);
				num = 2;
				break;
			case 2:
				memcpy(temp, "Remove course", 14);
				designSquare(17, 15, 3, 30, temp, 11, 432);
				num = 3;
				break;
			case 3:
				memcpy(temp, "Update course information", 26);
				designSquare(50, 15, 3, 30, temp, 11, 432);
				num = 4;
				break;
			case 4:
				memcpy(temp, "View list of course", 20);
				designSquare(17, 19, 3, 30, temp, 11, 432);
				num = 5;
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
}

void print_undergraduate_function(int choice/*int &no, profile *&pstudent, subjects *&psubject, int &semester, int &classroom, int &year*/) {
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
}

void announcement(char *content, bool title, int &num) {

}