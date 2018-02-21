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
int DietPlan::getCalories() const {
	return calories;
}

string DietPlan::getName() const {
	return name;
}

string DietPlan::getDate() const {
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

/**NON MEMBER FUNCTIONS**/
ostream& operator << (ostream &out, const DietPlan &plan) {
	out << plan.getName() << endl
		<< plan.getCalories() << endl
		<< plan.getDate() << endl;

	return out;
}

istream& operator >> (istream &in, DietPlan &plan) {
	char data[20];
	in >> data;

	if (plan.getName() == "")
		plan.setName(data);
	else if (plan.getCalories() == 0)
		plan.setCalories(stoi(data));
	else
		plan.setDate(data);
	
	return in;
}