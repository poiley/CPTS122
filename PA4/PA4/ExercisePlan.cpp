/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 4
* Date : Feb 20th, 2018
* Credits : Andrew O'Fallon for instructions
**********************************************************************/

#include "ExercisePlan.h"

/**CONSTRUCTORS**/
ExercisePlan::ExercisePlan() {
	steps = 0;
	date = name = "";
}

ExercisePlan::ExercisePlan(int newSteps, string newName, string newDate) {
	steps = newSteps;
	name = newName;
	date = newDate;
}

ExercisePlan::ExercisePlan(ExercisePlan &newPlan) {
	steps = newPlan.getSteps();
	name = newPlan.getName();
	date = newPlan.getDate();
}

/**DECONSTRUCTOR**/
ExercisePlan::~ExercisePlan() {}

/**GETTERS**/
int ExercisePlan::getSteps() const {
	return steps;
}

string ExercisePlan::getName() const {
	return name;
}

string ExercisePlan::getDate() const {
	return date;
}

/**SETTERS**/
void ExercisePlan::setSteps(int newSteps) {
	steps = newSteps;
}

void ExercisePlan::setName(string newName) {
	name = newName;
}

void ExercisePlan::setDate(string newDate) {
	date = newDate;
}

/**MEMBER FUNCTIONS**/
void ExercisePlan::editGoal(){
	int newSteps;
	
	cout << "New step goal?" << endl << "-> ";
	cin >> newSteps;

	setSteps(newSteps);

	cout << "New goal: " << steps << endl;
}

/**NON MEMBER FUNCTIONS**/
ostream& operator << (ostream &out, const ExercisePlan &plan) {
	out << plan.getName()  << endl
		<< plan.getSteps() << endl
		<< plan.getDate()  << endl;

	return out;
}

istream& operator >> (istream &in, ExercisePlan &plan) {
	string data;

	getline(in, data);
	plan.setName(data);

	getline(in, data);
	plan.setSteps(stoi(data));

	getline(in, data);
	plan.setDate(data);

	in.ignore(sizeof(char), '\n');

	return in;
}