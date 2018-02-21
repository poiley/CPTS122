/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 4
* Date : Feb 20th, 2018
* Credits : Andrew O'Fallon for instructions
**********************************************************************/

#include "FitnessAppWrapper.h"

int main(void) {
	runApp();
}

/*
* AUTHOR: Benjamin Poile
* DESCRIPTION: Starts the main application.
*/
void runApp() {
	cout << "Running App..." << endl << endl;

	DietPlan *diet = new DietPlan[7];
	ExercisePlan *exercise = new ExercisePlan[7];

	fstream diet_outfile, exercise_outfile;
	diet_outfile.open("dietPlans.txt");
	exercise_outfile.open("exercisePlans.txt");

	int menu, day;
	do {
		menu = displayMenu();
		switch (menu) {
			case 1:
				loadWeeklyPlan(diet_outfile, &diet);
				break;
			case 2:
				loadWeeklyPlan(exercise_outfile, &exercise);
				break;
			case 3:
				storeWeeklyPlan(diet);
				break;
			case 4:
				storeWeeklyPlan(exercise);
				break;
			case 5:
				displayWeeklyPlan(diet);
				break;
			case 6:
				displayWeeklyPlan(exercise);
				break;
			case 7:
				cout << "Which day would you like to edit? (1-7)" << endl << "-> ";
				cin >> day;
				diet[day - 1].editGoal();
				break;
			case 8:
				cout << "Which day would you like to edit? (1-7)" << endl << "-> ";
				cin >> day;
				exercise[day - 1].editGoal();
				break;
			case 9:
				storeWeeklyPlan(diet);
				storeWeeklyPlan(exercise);
				diet_outfile.close();
				exercise_outfile.close();
				cout << "Exiting!" << endl;
		}
	} while (menu != 9);
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Must define two of these functions; one for a DietPlan and one for an
 * ExercisePlan. This function reads one record from the given stream. These will be
 * considered overloaded functions! 
 * PRECONDITION: file is already open!
 */
void loadDailyPlan(fstream &fileStream, DietPlan &plan) {
	fileStream >> plan;
	fileStream >> plan;
	fileStream >> plan;
}

void loadDailyPlan(fstream &fileStream, ExercisePlan &plan) {
	fileStream >> plan;
	fileStream >> plan;
	fileStream >> plan;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Must define two of these functions; one for a DietPlan and one for an
 * ExercisePlan. This function must read in all seven daily plans from the given
 * stream. Note: the array parameter would change if using a vector or linked list!
 * This function should call loadDailyPlan(); directly.
 * PRECONDITION: file is already open!
 */
void loadWeeklyPlan(fstream &fileStream, DietPlan *weeklyPlan[]) {
	DietPlan diet_temp;
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, diet_temp);
		(*weeklyPlan)[i] = diet_temp;
	}
}

void loadWeeklyPlan(fstream &fileStream, ExercisePlan *weeklyPlan[]) {
	ExercisePlan exercise_temp;
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, exercise_temp);
		(*weeklyPlan)[i] = exercise_temp;
	}
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Writes a daily plan to the screen. You must apply the overloaded stream
 * insertion operator here! Note: you must determine the appropriate parameters and
 * return type. Once again you must define two of these!
 */
void displayDailyPlan(DietPlan plan) {
	cout << plan << endl;
}

void displayDailyPlan(ExercisePlan plan) {
	cout << plan << endl;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Writes a weekly plan to the screen. This function must call
 * displayDailyPlan();. Note: you must determine the appropriate parameters and return
 * type. Once again you must define two of these!
 */
void displayWeeklyPlan(DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++)
		displayDailyPlan(weeklyPlan[i]);
}

void displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++)
		displayDailyPlan(weeklyPlan[i]);
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: writes a daily plan to a file. You must apply the overloaded stream
 * insertion operator here! Note: you must determine the appropriate parameters and
 * return type. Once again you must define two of these!
 */
void storeDailyPlan(fstream &fileStream, DietPlan plan) {
	fileStream << plan << endl;
}

void storeDailyPlan(fstream &fileStream, ExercisePlan plan) {
	fileStream << plan << endl;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: writes a weekly plan to a file. This function must call
 * storeDailyPlan();.You must apply the overloaded stream insertion operator here!
 * Note: you must determine the appropriate parameters and return type. Once again you
 * must define two of these!
 */
void storeWeeklyPlan(DietPlan weeklyPlan[]) {
	fstream diet_outfile;
	diet_outfile.open("dietPlans.txt");

	for (int i = 0; i < 7; i++)
		storeDailyPlan(diet_outfile, weeklyPlan[i]);
	
	diet_outfile.close();
}

void storeWeeklyPlan(ExercisePlan weeklyPlan[]) {
	fstream exercise_outfile;
	exercise_outfile.open("exercisePlans.txt");

	for (int i = 0; i < 7; i++)
		storeDailyPlan(exercise_outfile, weeklyPlan[i]);
	
	exercise_outfile.close();
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Displays nine menu options.
 */
int displayMenu() {
	int menu = -1;

	cout << "1.\tLoad weekly diet plan from file." << endl
		<< "2.\tLoad weekly exercise plan from file." << endl
		<< "3.\tStore weekly diet plan to file." << endl
		<< "4.\tStore weekly exercise plan to file." << endl
		<< "5.\tDisplay weekly diet plan to screen." << endl
		<< "6.\tDisplay weekly exercise plan to screen." << endl
		<< "7.\tEdit daily diet plan." << endl
		<< "8.\tEdit daily exercise plan." << endl
		<< "9.\tExit." << endl
		<< "-> ";

	cin >> menu;

	return menu;
}