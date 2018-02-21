/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 4
* Date : Feb 20th, 2018
* Credits : Andrew O'Fallon for instructions
**********************************************************************/

#include "Resources.h"
#include "DietPlan.h"
#include "ExercisePlan.h"

/* 
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Starts the main application.
 */
void runApp();

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Must define two of these functions; one for a DietPlan and one for an 
 * ExercisePlan.This function reads one record from the given stream. These will be 
 * considered overloaded functions!Precondition: file is already open!
 */
void loadDailyPlan(fstream &fileStream, DietPlan &plan);
void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Must define two of these functions; one for a DietPlan and one for an 
 * ExercisePlan. This function must read in all seven daily plans from the given 
 * stream. Note: the array parameter would change if using a vector or linked list! 
 * This function should call loadDailyPlan(); directly.
 * PRECONDITION: file is already open!
 */
void loadWeeklyPlan(fstream &fileStream, DietPlan *weeklyPlan[]);
void loadWeeklyPlan(fstream &fileStream, ExercisePlan *weeklyPlan[]);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Writes a daily plan to the screen .You must apply the overloaded stream 
 * insertion operator here! Note: you must determine the appropriate parameters and 
 * return type. Once again you must define two of these!
 */
void displayDailyPlan(DietPlan plan);
void displayDailyPlan(ExercisePlan plan);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Writes a weekly plan to the screen. This function must call 
 * displayDailyPlan();. Note: you must determine the appropriate parameters and return 
 * type.Once again you must define two of these!
 */
void displayWeeklyPlan(DietPlan weeklyPlan[]);
void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: writes a daily plan to a file. You must apply the overloaded stream 
 * insertion operator here! Note: you must determine the appropriate parameters and 
 * return type. Once again you must define two of these!
 */
void storeDailyPlan(fstream &fileStream, DietPlan plan);
void storeDailyPlan(fstream &fileStream, ExercisePlan plan);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: writes a weekly plan to a file. This function must call 
 * storeDailyPlan();.You must apply the overloaded stream insertion operator here! 
 * Note: you must determine the appropriate parameters and return type. Once again you 
 * must define two of these!
 */
void storeWeeklyPlan(DietPlan weeklyPlan[]);
void storeWeeklyPlan(ExercisePlan weeklyPlan[]);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Displays nine menu options.
 */
int displayMenu(); 