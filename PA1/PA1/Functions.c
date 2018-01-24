/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 1
* Date : Jan 15th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
*			StackOverflow user filip-roseen-refp for mystrtok()
**********************************************************************/

#include "Header.h"

/*
 * ORIGINAL AUTHOR: @filip-roseen-refp on StackOverflow
 * MAJOR MODIFICATIONS MADE BY: Benjamin Poile
 * DESCRIPTION: Code Credits go to 'filip-roseen-refp' from StackOverflow. The purpose of this function is to act
 * just as strtok would, but it doesn't skip over double delimiters (for example ",,") but returns a
 * null value when such an action occurs.
 * URL: https://stackoverflow.com/questions/8705844
 */
char *mystrtok(char *toSplit) { //comment this method line by line to show understanding
	static char *source = NULL; // static character means that it will stay the same between calls of `mystrtok`
	char *splitSection, *toReturn = 0;

	if (toSplit != NULL) //If the input string isn't empty
		source = toSplit; 

	if (source == NULL) // If the string hasn't been totally delimited
		return NULL;

	/*
	* strpbrk finds the first character in `source` that matches `,`
	* It's worth noting that I have manually set the delimiter to be ",". This isn't very dynamic, but considering 
	* that commas are CSV file standards, I figured it wasn't a problem.
	*/										//WHAT'S HAPPENING: 
	splitSection = strpbrk(source, ",");	//the entire line so far, minus the part we're trying to pull out the line (,0.1201384,0,0,68,0,1)
	if ( splitSection != NULL ) {			//essentially checking if a `,` still exists in the string, which doesn't happen at the end of the line
		*splitSection = 0;					//set to NULL
		toReturn = source;					//at this point, toReturn is the section we're pulling out of the line
		source = ++splitSection;			//removes toReturn (the part we're pulling out) from the line
	} else if ( *source != NULL ) {			//if there's no more commas in the line, but the line is not NULL
		toReturn = source;					//set what to return (literally everythign that's left)
		source = NULL;						//wipe the static source
	}

	return toReturn;				
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Reads all data from the data file `FitbutData.csv` and creates a FitbitData object
 * for every line in the database. This object is then added to an array, cumulating to a total of 
 * 1440 data entries, or 24 hours of data. Code from StackOverflow user (credited above) was used 
 * for this method, as strtok doesn't natively support the reading of null values and sees double
 * delimiters as a single delimiter. Therefore, empty entries in the CSV file that appear as ',,'
 * are read as ','. This would cause a NullPointer exception.
 */
FitbitData * getData(FILE *infile, FitbitData data[]) {
	//Assumes that each line will not exceed 256 characters
	char line[256] = ""; 

	//Only run logic if the file exists and is not empty.
	if (infile != NULL) {
		//Setup values. To be written to the FitbitData object, and then to the data array.
		char *minute;
		double calories, distance;
		int floors, heartRate, steps, sleep_level, index = -1;
		Sleep sleepLevel;
		
		/* For every one minute of data, there is an entry of the following: 
		 * title:		minute,		calories,		distance,	floors,	heartRate,	steps,	sleepLevel
		 * type:		string,		double,			double,		int,	int,		int,	Sleep
		 * example:		0:00:00,	0.968900025,	0,			0,		63,			0,		1
		 */

		//Run for all 1440 entries in the CSV file.
		while (fgets(line, 1440, infile)) {
			if (index == -1) { //skip the first line, the column titles of the CSV file.
				index++;
				continue;
			}

			minute = mystrtok(line);
			strcpy(data[index].minute, minute); //Write time ("00:00:00") to object

			calories = strtod(mystrtok(NULL), NULL); //convert string to double and store
			data[index].calories = calories; //Write calories burned (0.00) to object

			distance = strtod(mystrtok(NULL), NULL); //convert string to double and store
			data[index].distance = distance; //Write distance walked (0.00) to object

			floors = atoi(mystrtok(NULL)); //convert string to integer and store
			data[index].floors = floors; //Write floors climed (0) to object

			heartRate = atoi(mystrtok(NULL)); //convert string to integer and store
			data[index].heartRate = heartRate; //Write heart rate (0) to object

			steps = atoi(mystrtok(NULL)); //convert string to integer and store
			data[index].steps = steps; //Write steps taken (0) to object

			sleepLevel = atoi(mystrtok(NULL)); //convert string to integer and store
			switch (sleepLevel) { //convert integer to Sleep enum object
				case 1: //if 1, ASLEEP
					sleepLevel = ASLEEP;
					break;
				case 2: //if 2, AWAKE
					sleepLevel = AWAKE;
					break;
				case 3: //if 3, REALLYAWAKE
					sleepLevel = REALLYAWAKE;
					break;
				default: //if 0 or otherwise, NONE
					sleepLevel = NONE;
					break;
			}

			data[index].sleepLevel = sleepLevel; //Write sleep (0/NONE) to object

			index++; //Add one to index
		}
	}

	return data; //return the array of FitbitData 
}

/*
 * AUTHOR: Benjamin Poile 
 * DESCRIPTION: Writes the following Data to screen and file `Results.csv`
 */
void writeData(FILE *outfile, FitbitData data[]) {
	/*Line 1: Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep*/
	//Write line 1 to file, then to screen
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");

	//obtain sleep data, ready for formatting as string for output.
	char *sleep[2] = { "\0" };
	consecutivePoorSleep(data, sleep);

	/*Line 2: valueCalories,valueDistance,valueFloors,valueSteps,valueHeartrate,valueMax,valueSleepStart:valueSleepEnd*/
	//Write line 2 to file, then to screen
	fprintf(outfile, "%lf,%lf,%d,%d,%lf,%d,%s:%s", caloriesBurned(data), distanceWalked(data), floorsWalked(data), stepsTaken(data), averageHeartrate(data), maximumSteps(data), sleep[0], sleep[1]);
	printf("%lf,%lf,%d,%d,%lf,%d,%s:%s\n", caloriesBurned(data), distanceWalked(data), floorsWalked(data), stepsTaken(data), averageHeartrate(data), maximumSteps(data), sleep[0], sleep[1]);
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the total calories burned in the 24 hour period 
 */
double caloriesBurned(FitbitData data[]) {
	double caloriesBurned = 0.00;

	for (int i = 0; i < 1440; i++)
		caloriesBurned += data[i].calories;

	return caloriesBurned;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the total distance walked in the 24 hour period
 */
double distanceWalked(FitbitData data[]) {
	double distanceWalked = 0.00;

	for (int i = 0; i < 1440; i++)
		distanceWalked += data[i].distance;

	return distanceWalked;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the total floors walked in the 24 hour period
 */
int floorsWalked(FitbitData data[]) {
	int floorsWalked = 0;

	for (int i = 0; i < 1440; i++)
		floorsWalked += data[i].floors;

	return floorsWalked;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the total steps taken over the 24 hour period
 */
int stepsTaken(FitbitData data[]) {
	int stepsTaken = 0;

	for (int i = 0; i < 1440; i++)
		stepsTaken += data[i].steps;

	return stepsTaken;
}

/* 
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the average heart rate over the 24 hour period. If the heart rate is 0, it is not counted.
 */
double averageHeartrate(FitbitData data[]) {
	double average = 0;

	for (int i = 0; i < 1440; i++)
		if(data[i].heartRate != 0)
			average += data[i].heartRate;

	return average / 1440;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns the maximum amount of steps taken in a single minute over the 24 hour period
 */
int maximumSteps(FitbitData data[]) {
	int maximum = data[0].steps;

	for (int i = 1; i < 1440; i++)
		if (maximum <= data[i].steps)
			maximum = data[i].steps;

	return maximum;
}

/* 
 * AUTHOR: Benjamin Poile 
 * DESCRIPTION: Returns the range of times in which the sleep was considered "poor".
 * NOTE: I worked through this method with Glen Bennett. No code was explicitly shared but the logic may be similar.
 */
char * consecutivePoorSleep(FitbitData data[], int indicies[]) {
	int sumOfTime = 0, startIndex, endIndex, overallStartIndex, overallEndIndex; //Setup variables

	//For the length of the entire database (1440 entries)
	for (int i = 0; i < 1440; i++) {
		if (data[i].sleepLevel > 1) { // If sleep is poor
			startIndex = i; // set the temp start index value to index `i`

			for (int j = i; j < 1440; j++) //from there, cycle through the loop to find the end
				if (data[j].sleepLevel > 1) {
					endIndex = j;
				} else {
					i = j; //not necessary, but minimizes iterations from 41 to 16 for this specific data set
					break;
				}

			int sum = 0; // Reset sum counter
			for (int j = startIndex; j <= endIndex; j++) //for the bounds of the start and end index
				sum += data[j].sleepLevel; //count the sum of the sleepLevel in such range

			//If the sum of the range is the new maximum sum. 
			//If the two are equal, it finds the latest occurance in the 24 hour period.
			if (sumOfTime <= sum) {
				sumOfTime			= sum;			//Overwrite sum, store new maximum sum
				overallStartIndex	= startIndex;	//Overwrite overall index, store new start index
				overallEndIndex		= endIndex;		//Overwrite overall index, store new end index
			}
		}
	}

	//Store the start and end index in integer array
	indicies[0] = data[overallStartIndex].minute;
	indicies[1] = data[overallEndIndex].minute;

	//Return bounds as integer array.
	return indicies;
}