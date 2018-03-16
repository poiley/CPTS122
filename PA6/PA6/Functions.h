#include "Resources.h"
#include "List.h"

void csvToList(List **pList);
void attendanceCheck(List **pList);
void generateReport(List *pList);
void generateReport(List *pList, int attendanceThreshold);