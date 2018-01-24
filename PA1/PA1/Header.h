/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 1
* Date : Jan 15th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
*			StackOverflow user filip-roseen-refp for mystrtok()
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/*****************
 * BORROWED CODE *
 *****************/

/*Credit to Andrew O'Fallon for enum code*/
typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

/*Credit to Andrew O'Fallon for struct code*/
typedef struct fitbit {
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


/* Credit to filip-roséen-refp on Stack Overflow (for documentation/explanation, see function)
 * Major edits and configurations made by Benjamin Poile*/
char *mystrtok(char * str);

/******************
 * Personal Code: * 
 ******************/

 /*
  * AUTHOR: Benjamin Poile
  * DESCRIPTION: Reads all data from the data file `FitbutData.csv` and creates a FitbitData object
  * for every line in the database. This object is then added to an array, cumulating to a total of
  * 1440 data entries, or 24 hours of data. Code from StackOverflow user (credited above) was used
  * for this method, as strtok doesn't natively support the reading of null values and sees double
  * delimiters as a single delimiter. Therefore, empty entries in the CSV file that appear as ',,'
  * are read as ','. This would cause a NullPointer exception.
  */
FitbitData * getData(FILE *infile, FitbitData data[]);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Writes the following Data to screen and file `Results.csv`
 */
void writeData(FILE *outfile, FitbitData data[]);

/*
 * AUTHOR: Benjamin Poile 
 * DESCRIPTION: Returns the total calories burned in the 24 hour period
 */
double caloriesBurned(FitbitData data[]);

/* 
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the total distance walked in the 24 hour period
 */
double distanceWalked(FitbitData data[]);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the total floors walked in the 24 hour period
 */
int floorsWalked(FitbitData data[]);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the total steps taken over the 24 hour period
 */
int stepsTaken(FitbitData data[]);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the average heart rate over the 24 hour period
 */
double averageHeartrate(FitbitData data[]);

/* 
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the maximum amount of steps taken in a single minute over the 24 hour period
 */
int maximumSteps(FitbitData data[]);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the range of times in which the sleep was considered "poor".
 * NOTE: I worked through this method with Glen Bennett. No code was explicitly shared but the logic may be similar.
 */
char * consecutivePoorSleep(FitbitData data[], int indicies[]);