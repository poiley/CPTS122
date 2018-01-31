/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 2
* Date : Jan 24th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include "Header.h"

//NOTE:
//	TA requests that dev reads and writes from the same .csv file.

int main() {
	Node *pList = NULL;
	int option = -1;

	while( option != 11 )
		option = displayMenu();

	printf("Quitting!\n");
	return 0;
}