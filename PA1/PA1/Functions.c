/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 1
* Date : Jan 15th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include "Header.h"

/*
For every one minute of activity, there is a new line in the database
CSV: Minute, Calories, Distance (in miles), Floors, Heartrate, Steps, Sleep level
*/

/*
Code Credits go to 'filip-roséen-refp' from StackOverflow. The purpose of this function is to act 
just as strtok would, but it doesn't skip over double delimiters (for example ",,") but returns a 
null value when such an action occurs.
https://stackoverflow.com/questions/8705844/need-to-know-when-no-data-appears-between-two-token-separators-using-strtok
*/
char *strtok_single(char * str, char const * delims) { 
	static char  * src = NULL;
	char  *  p, *ret = 0;

	if (str != NULL)
		src = str;

	if (src == NULL)
		return NULL;

	if ((p = strpbrk(src, delims)) != NULL) {
		*p = 0;
		ret = src;
		src = ++p;
	} else if (*src) {
		ret = src;
		src = NULL;
	}

	return ret;
}

FitbitData * getData(FILE *infile, FitbitData data[]) {
	char line[256] = "";

	if (infile != NULL) {
		char *minute;
		double calories, distance;
		int floors, heartRate, steps, sleep_level, index = -1;
		Sleep sleepLevel;
		/*
		 *	title:		minute,		calories,		distance,	floors,	heartRate,	steps,	sleepLevel
		 *	type:		string,		double,			double,		int,	int,		int,	Sleep
		 *	example:	0:00:00,	0.968900025,	0,			0,		63,			0,		1
		 */

		while (fgets(line, 1440, infile)) {
			if (index == -1) { //skip the first line, the column titles of the CSV file.
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
	}

	return data;
}

double caloriesBurned(FitbitData data[]) {
	double caloriesBurned = 0.00;
	
	for (int i = 0; i < 1440; i++)
		caloriesBurned += data[i].calories;

	return caloriesBurned;
}

double distanceWalked(FitbitData data[]) {
	double distanceWalked = 0.00;

	for (int i = 0; i < 1440; i++)
		distanceWalked += data[i].distance;

	return distanceWalked;
}

int floorsWalked(FitbitData data[]) {
	int floorsWalked = 0;

	for (int i = 0; i < 1440; i++)
		floorsWalked += data[i].floors;

	return floorsWalked;
}

int stepsTaken(FitbitData data[]) {
	int stepsTaken = 0;

	for (int i = 0; i < 1440; i++)
		stepsTaken += data[i].steps;

	return stepsTaken;
}

double averageHeartrate(FitbitData data[]) {
	double average = 0;

	for (int i = 0; i < 1440; i++)
		average += data[i].heartRate;

	return average / (1440);
}

int maximumSteps(FitbitData data[]) {
	int maximum = data[0].steps;
	
	for (int i = 1; i < 1440; i++)
		if (maximum <= data[i].steps)
			maximum = data[i].steps;

	return maximum;
}

int * consecutivePoorSleep(FitbitData data[], int indicies[]) {
	int sumOfTime = 0, startIndex, endIndex, overallStartIndex, overallEndIndex;

	for (int i = 0; i < 1440; i++) {

		if (data[i].sleepLevel > 1) {
			startIndex = i;

			for (int j = i; j < (1440); j++) {
				if (data[j].sleepLevel > 1)
					endIndex = j;
				else
					break;
			}

			int sum = 0;
			for (int j = startIndex; j <= endIndex; j++)
				sum += data[j].sleepLevel;

			if (sum >= sumOfTime) {
				overallStartIndex = startIndex;
				overallEndIndex = endIndex;
			}
		}
	}

	indicies[0] = overallStartIndex;
	indicies[1] = overallEndIndex;
		
	return indicies;
}

void writeData(FILE *outfile, FitbitData data[]) {
	//Line 1: Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep
	fopenf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep");

	int sleep[2] = { -1 };
	consecutivePoorSleep(data, sleep);

	//Line 2: valueCalories, valueDistance, valueFloors, valueSteps, valueHeartrate, valueMax, valueSleepStart : valueSleepEnd
	fopenf(outfile, "%lf,%lf,%d,%d,%lf,%d,%d : %d", caloriesBurned(data), distanceWalked(data), floorsWalked(data), stepsTaken(data), averageHeartrate(data), maximumSteps(data), sleep[0], sleep[1]);
}
