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

//Credit to filip-roséen-refp on Stack Overflow
char *strtok_single(char * str, char const * delims);


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



