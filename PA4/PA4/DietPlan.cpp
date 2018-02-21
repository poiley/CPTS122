/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 4
* Date : Feb 20th, 2018
* Credits : Andrew O'Fallon for instructions
**********************************************************************/

#include "DietPlan.h"

/**CONSTRUCTORS**/
DietPlan::DietPlan() {
	calories = 0;
	date = name	= "";
}

DietPlan::DietPlan(int newCalories, string newName, string newDate) {
	calories = newCalories;
	name	 = newName;
	date	 = newDate;
}

DietPlan::DietPlan(DietPlan &newPlan) {
	calories = newPlan.getCalories();
	name	 = newPlan.getName();
	date	 = newPlan.getDate();
}

/**DECONSTRUCTOR**/
DietPlan::~DietPlan() {}

/**GETTERS**/
int DietPlan::getCalories() {
	return calories;
}

string DietPlan::getName() {
	return name;
}

string DietPlan::getDate() {
	return date;
}

/**SETTERS**/
void DietPlan::setCalories(int newCalories) {
	calories = newCalories;
}

void DietPlan::setName(string newName) {
	name = newName;
}
void DietPlan::setDate(string newDate) {
	date = newDate;
}

/**MEMBER FUNCTIONS**/
void DietPlan::editGoal() {
	int newCalories;

	cout << "New calorie goal?" << endl << "-> ";
	cin >> newCalories;

	setCalories(newCalories);

	cout << "New goal: " << calories << endl;
}

/*ostream& operator << (ostream& out, DietPlan &plan) {
	out << "==New goal==" << endl
		<< "Name:\t" << &plan.getName() << endl
		<< "Goal:\t" << plan.getCalories() << endl
		<< "Date:\t" << &plan.getDate() << endl << endl;

	ofstream outfile;
	outfile.open("dietPlans.txt");

	outfile << &plan.getName() << endl
			<< plan.getCalories() << endl
			<< &plan.getDate();
	
	outfile.close();

	return out;
}*/