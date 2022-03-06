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

void view_student(){
	
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