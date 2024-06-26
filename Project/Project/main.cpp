#include "project.h"

int main(){

    int no = 0, semester = 1, year = 2021, classroom = -1, id_profile = 0;
	int role = 0, choice = 1;
    profile *pstudent;
    subjects *psubject;
    classrooms *pclassid;
    pstudent = nullptr;
    psubject = nullptr;
    pclassid = nullptr;

	char temp[200];
	int num = 0;

	view_space();

	/*memcpy(temp, "Do you want to use the last data?", 34);
	announcement(temp, 1, num, 0);
	num = 1;*/
	read_csv_classroom(pclassid);
	read_csv_subject(psubject);
	read_csv_student(pstudent);

	while (true){
		role = 0; choice = 1;

		if (role == 3 || role == 0) {
		    login(role, id_profile);
		    GoTo(34, 18);
		    system("pause");
		}

		if (role == 1){
			while (choice){
				showcur(0);
				print_option_1(choice);
				showcur(1);
				if (choice == 7){
					role = 4;
					break;
				}
				make_choice_1(choice, pstudent, psubject, pclassid, no, classroom, semester, year, id_profile);
				if (choice == 0)
					if (logout()) break;
					else choice = 1;
			}
		} else if (role == 2) {
			while (choice){
				print_option_2(choice);
				if (choice == 4){
					role = 4;
					break;
				}
				make_choice_2(choice, pstudent, psubject, semester, year, id_profile);
				if (choice == 0)
					if (logout()) break;
					else choice = 1;
			}
		}
		if (role == 4) break;
	}

	write_csv_classroom(pclassid);
	write_csv_subject(psubject);
	write_csv_student(pstudent);


	exitProgram();

	GoTo(0, 31);
	return 0;
}