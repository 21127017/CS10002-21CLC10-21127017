#include "project.h"

//-----------VIEW DESIGN SPACE-------------//
void GoTo(SHORT posX, SHORT posY) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void view_space() {
	system("cls");
	GoTo(0, 0);
	cout << static_cast<char>(201);
	for (int i = 0; i < 100; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(187) << endl;
	for (int j = 0; j < 50; j++) {
		cout << static_cast<char>(186);
		for (int i = 0; i < 100; i++)
			cout << " ";
		cout << static_cast<char>(186) << endl;
	}
	cout << static_cast<char>(200);
	for (int i = 0; i < 100; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188);
}

void view_loginboard() {
	system("cls");
	GoTo(0, 0);

	//In o login
	GoTo(45, 8);
	cout << static_cast<char>(201);
	for (int i = 0; i < 11; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(187);
	GoTo(45, 9);
	cout << static_cast<char>(186);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 143);
	cout << "   LOGIN   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << static_cast<char>(186);
	GoTo(45, 10);
	cout << static_cast<char>(200);
	for (int i = 0; i < 11; i++)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188);
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
			}
			else 
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
		inf[i].username = new char[strlen(temp_string) + 1];
		memcpy(inf[i].username, temp_string, strlen(temp_string) + 1);

		inp.getline(temp_string, 200, ',');
		inf[i].password = new char[strlen(temp_string) + 1];
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

	delete[] inf;
}

void login(int &role, int &id_profile) {
	system("cls");
	ifstream inp;
	inp.open("login_information.csv");

	char temp_char;
	char temp_string[200];

	int N; //number of account in file

	//input username from keyboard
	char *username;
	cout << "USERNAME: ";
	cin.getline(temp_string, 200, ',');
	username = new char[strlen(temp_string) + 1];
	memcpy(username, temp_string, strlen(temp_string) + 1);

	//input password from keyboard
	char *password;
	cout << "PASSWORD: ";
	cin.getline(temp_string, 200, ',');
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
				break;
			} else {//wrong password
				role = 3;
				id_profile = 0;
				break;
			}
		}
	}
	inp.close();
}