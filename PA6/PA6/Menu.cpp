#include "Menu.h"

Menu::Menu() {
	menu_choice = -1;
}

void Menu::display() {
	cout << "1.)\tImport course list" << endl
		 << "2.)\tLoad master list" << endl
		 << "3.)\tStore master list" << endl
		 << "4.)\tMark absences" << endl
		 << "5.)\tBONUS: Edit absences" << endl
		 << "6.)\tGenerate report" << endl
		 << "7.)\tExit" << endl;
}

bool Menu::execute(List **pList) {
	List *tempList = *pList;
	int menu;
	switch (menu_choice) {
		case 1:
			readCSVToList(&tempList);
			break;
		case 2:
			readMasterToList(&tempList);
			break;
		case 3:
			writeListToMaster(tempList);
			break;
		case 4:
			attendanceCheck(&tempList);
			break;
		case 5:
			editAbsence(&tempList);
			break;
		case 6:
			cout << "1.)\tGenerate report for all students" << endl
				 << "2.)\tGenerate report for students with certain number of absences" << endl
			 	 << "-> ";
			cin >> menu;

			switch (menu) {
				case 1:
					generateReport(tempList);
					break;
				case 2:
					cout << "How many absences?" << endl << "-> ";
					cin >> menu;
					generateReport(tempList, menu);
					break;
			}
			break;
		default: 
			cout << "Invalid input" << endl;
		case 7:
			cout << endl << "Exiting..." << endl;
			return false;
	}

	*pList = tempList;
	return true;
}

int Menu::get_menu() {
	return menu_choice;
}

void Menu::set_menu(int newMenu) {
	menu_choice = newMenu;
}

istream& operator >> (istream &in, Menu &menu) {
	int newMenu;
	
	menu.display();
	cout << "-> ";
	
	cin >> newMenu;
	menu.set_menu(newMenu);

	cout << endl;

	return in;
}