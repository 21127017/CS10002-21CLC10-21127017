#include "project.h"

//-----------VIEW DESIGN SPACE-------------//
void set_color(int code) {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code);
}

void GoTo(SHORT posX, SHORT posY) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void designSquare(SHORT posX, SHORT posY, int height, int width, char *content, int color) {
	set_color(color);
	GoTo(posX, posY); //cout -------------------
	cout << static_cast<char>(201);
	for (int i = 0; i < (width - 2); i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(187);

	for (int i = 1; i < (height - 1); i++) {
		GoTo(posX, (posY + i)); //cout |.........................|
		cout << static_cast<char>(186);
		GoTo((posX + width - 1), (posY + i));
		cout << static_cast<char>(186);
	}

	GoTo(posX, (posY + height - 1)); //cout ---------------------
	cout << static_cast<char>(200);
	for (int i = 0; i < (width - 2); i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188);
	set_color(7);
	if (content != nullptr) {
		//cout content of square
		int len = strlen(content);
		GoTo((posX + (width - len) / 2), (posY + (height - 1) / 2));
		cout << content;
	}
}

void view_space() {
	system("cls");
	designSquare(0, 0, 30, 100, nullptr, 7);
}

void view_loginboard() {
	system("cls");
	view_space();

	GoTo(47, 9);
	cout << "LOGIN";

	char temp[200] = "USERNAME";
	designSquare(33, 10, 3, 12, temp, 7);
	designSquare(45, 10, 3, 22, nullptr, 7);

	memcpy(temp, "PASSWORD", 9);
	designSquare(33, 13, 3, 12, temp, 7);
	designSquare(45, 13, 3, 22, nullptr, 7);
}

void view_student() {

}

void view_subject() {

}

void view_class() {

}

void view_semester() {

}

void view_school_year() {

}

void view_list_of_course() {

}

void view_scoreboard() {

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