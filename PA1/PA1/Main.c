/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 122, Spring 2018
* Programming Assignment: PA 1
* Date: Jan 15th, 2018
* Credits: Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include "Header.h"

/*
For every one minute of activity, there is a new line in the database
CSV: Minute, Calories, Distance (in miles), Floors, Heartrate, Steps, Sleep level
*/

int main(void) {
	FitbitData data[1440] = { "0:00:00", 0.00, 0.00, 0, 0, 0, NONE };
	FILE *infile = NULL;
	char line[256] = "";

	infile = fopen("FitbitData.csv", "r");

	if (infile != NULL) { 
		char *minute;
		double calories, distance;
		int floors, heartRate, steps, sleep_level, index = -1;
		Sleep sleepLevel;
		//title:	minute,		calories,		distance,	floors,	heartRate,	steps,	sleepLevel
		//type:		string,		double,			double,		int,	int,		int,	Sleep
		//example:	0:00:00,	0.968900025,	0,			0,		63,			0,		1

		while (fgets(line, 1440, infile)) {
			if (index == -1) { //skip the first line, the headers of the CSV file.
				index++;
				continue;
			}

			minute = strtok_single(line, ",");
			strcpy(data[index].minute, minute);

			calories = strtod(strtok_single(NULL, ","), NULL);
			data[index].calories = calories;

			distance = strtod(strtok_single(NULL, ","), NULL);
			data[index].distance = distance;

			floors = atoi(strtok_single(NULL, ","));
			data[index].floors = floors;

			heartRate = atoi(strtok_single(NULL, ","));
			data[index].heartRate = heartRate;

			steps = atoi(strtok_single(NULL, ","));
			data[index].steps = steps;

			sleepLevel = atoi(strtok_single(NULL, ","));
			switch (sleepLevel) {
				case 1:
					sleepLevel = ASLEEP;
					break;
				case 2: 
					sleepLevel = AWAKE;
					break;
				case 3:
					sleepLevel = REALLYAWAKE;
				default: 
					sleepLevel = NONE;
					break;
			}

			data[index].sleepLevel = sleepLevel;

			index++;
		}
		
		for (int i = 0; i < 1440; i++)
			printf("%s\t %lf\t %lf\t %d\t %d\t %d\t %d\n", data[i].minute, data[i].calories, data[i].distance, data[i].floors, data[i].heartRate, data[i].steps, data[i].sleepLevel);

	}
}