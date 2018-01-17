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

// https://stackoverflow.com/questions/8705844/need-to-know-when-no-data-appears-between-two-token-separators-using-strtok
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
