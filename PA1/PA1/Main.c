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
	FitbitData data[1440] = { "0:00:00", 0.00, 0, 0, 0, 0, 0 };

	FILE *infile = NULL;
	char line[1440] = "";

	infile = fopen("FitbitData.csv", "r");

	if (infile != NULL) { 
		char *split_data[7], *minute;
		double calories;
		int distance, floors, heart, steps, sleep_level;
		//minute,	calories,		distance,	floors,	heart,	steps,	sleep_level
		//string,	double,			int,		int,	int,	int,	int
		//0:00:00,	0.968900025,	0,			0,		63,		0,		1

		while (fgets(line, 1440, infile)) {
			minute = strtok(line, ",");
			printf("%s\t", minute);
			calories = strtod(strtok(NULL, ","), NULL);
			printf("%lf\t", calories);

			distance = atoi(strtok(NULL, ","));
			printf("%d\t", distance);
			floors = atoi(strtok(NULL, ","));
			printf("%d\t", floors);

			//char *restoflines = strtok(NULL, "\n");
			char *heartc = strtok(NULL, ",");
			if (atoi(heartc) == NULL) {
				heart = -1;
			} else {
				heart = atoi(heartc);
			}
			printf("%d\t", heart);

			steps = atoi(strtok(NULL, ","));
			printf("%d\t", steps);
			sleep_level = atoi(strtok(NULL, ","));
			printf("%d\n", sleep_level);

			//printf("min: %s\tcal: %lf\tdis: %d\tflr: %d\thrt: %d\tstp: %d\tslp: %d\t\n", minute,calories,distance,floors,heart,steps,sleep_level);
		}

	}
}