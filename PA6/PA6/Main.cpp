#include "Functions.h"

int main(void) {
	List *pList = (List *) malloc(sizeof(List));
	pList->setHead(NULL);
	
	csvToList(&pList);
	
	attendanceCheck(&pList);

	generateReport(pList);

	generateReport(pList, 1);
}