/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 1
* Date : Jan 15th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
*			StackOverflow user filip-roseen-refp for mystrtok()
**********************************************************************/

#include "Header.h"

int main(void) {

	FitbitData data[1440] = { "0:00:00", 0.00, 0.00, 0, 0, 0, NONE };
	FILE *infile = NULL, *outfile = NULL;

	infile = fopen("FitbitData.csv", "r");
	outfile = fopen("Results.csv", "w+");

	getData(infile, data);

	fclose(infile);

	writeData(outfile, data);

	fclose(outfile);
	
	return 0;
}