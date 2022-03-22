#include "project.h"

int main(){

    int no = 0, semester = 0, year = 0, classroom = -1, id_profile = 0;
    profile *pstudent;
    subjects *psubject;
    classrooms *pclassid;
    pstudent = NULL;
    psubject = NULL;
    pclassid = NULL;

	while (true){
		int role = 0, choice = 1;
		while (role == 3 || role == 0) {
		    login(role, id_profile);
		    GoTo(34, 18);
		    system("pause");
		}
		if (role == 1){
			while (choice){
				print_option_1(choice);
				//cin >> choice;
				if (choice == 7){
					role = 4;
					break;
				}
				make_choice_1(choice, pstudent, psubject, pclassid, no, classroom, semester, year, id_profile);
			}
		} else if (role == 2) {
			while (choice){
				//print_option_2(choice);
				//cin >> choice;
				if (choice == 5){
					role = 4;
					break;
				}
				//make_choice_2(choice, id_profile);
			}
		}
		if (role == 4) break;
	}

	system("cls");
	cout <<"THANK FOR USING OUR APPLICATION!" << endl;
	cout << "We hope you have a good experience.";

	GoTo(0, 31);
	return 0;
}