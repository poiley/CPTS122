/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 122, Spring 2018
* Programming Assignment: PA 1
* Date: Jan 15th, 2018
* Credits: Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//Credit to Andrew O'Fallon for code
typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

//Credit to Andrew O'Fallon for code
typedef struct fitbit {
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


//Credit to filip-roséen-refp on Stack Overflow
char *strtok_single(char * str, char const * delims);

//Personal Code:
FitbitData * getData(FILE *infile, FitbitData data[]);

void writeData(FILE *outfile, FitbitData data[]);

double caloriesBurned(FitbitData data[]);

double distanceWalked(FitbitData data[]);

double averageHeartrate(FitbitData data[]);

int floorsWalked(FitbitData data[]);

int stepsTaken(FitbitData data[]);

int maximumSteps(FitbitData data[]);

int * consecutivePoorSleep(FitbitData data[], int indicies[]);