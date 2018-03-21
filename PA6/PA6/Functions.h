#include "Resources.h"
#include "List.h"

void readCSVToList(List **pList);
void readMasterToList(List **pList);

void attendanceCheck(List **pList);

void generateReport(List *pList);
void generateReport(List *pList, int attendanceThreshold);

void writeListToMaster(List *pList);

//bonus
void editAbsence(List **pList);

//random
string formatName(string unformatted);
string makeLowerCase(string unformatted);