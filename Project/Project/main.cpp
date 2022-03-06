#include "project.h"

int main() {

	int no = 0, semester = 0, year = 0, classroom = -1;
	profile *pstudent;
	subjects *psubject;
	classrooms *pclassid;
	pstudent = NULL;
	psubject = NULL;
	pclassid = NULL;

	while (true) {
		int roll = 1, choice = 1;
		login(roll);
		if (roll == 3) break;
		if (roll == 1) {
			while (choice) {
				print_option_1();
				cin >> choice;
				make_choice_1(choice, pstudent, psubject, pclassid, no, classroom, semester, year);
			}
		} else {
			while (choice) {
				print_option_2();
				cin >> choice;
				make_choice_2(choice);
			}
		}
	}

	return 0;
}