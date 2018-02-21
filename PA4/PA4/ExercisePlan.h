/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 4
* Date : Feb 20th, 2018
* Credits : Andrew O'Fallon for instructions
**********************************************************************/

#include "Resources.h"

class ExercisePlan {
public:
	ExercisePlan();
	ExercisePlan(int newSteps, string newName, string newDate);
	ExercisePlan(ExercisePlan &newPlan);

	~ExercisePlan();

	int getSteps();
	string getName();
	string getDate();

	void setSteps(int newSteps);
	void setName(string newName);
	void setDate(string newDate);

	void editGoal();
private:
	int steps;
	string name, date;
};