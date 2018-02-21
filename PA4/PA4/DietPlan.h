/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 4
* Date : Feb 20th, 2018
* Credits : Andrew O'Fallon for instructions
**********************************************************************/

#include "Resources.h"

class DietPlan {
public:
	DietPlan();
	DietPlan(int newCalories, string newName, string newDate);
	DietPlan(DietPlan &newPlan);

	~DietPlan();

	int getCalories();
	string getName();
	string getDate();

	void setCalories(int newCalories);
	void setName(string newName);
	void setDate(string newDate);

	void editGoal();
private:
	int calories;
	string name, date;
};


//ifstream& operator >> (ifstream& in, DietPlan &play);