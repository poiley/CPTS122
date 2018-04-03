/*****************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS**/
#include "Resources.h"
#include "List.h"

/**READ FROM FILES**/
void readCSVToList(List **pList); 
void readMasterToList(List **pList);

/**CHECK ATTENDANCE**/
void attendanceCheck(List **pList);

/**WRITE TO FILES**/
void writeListToMaster(List *pList);

/**ASSIGNMENT BONUS**/
void editAbsence(List **pList);

/**GENERATE REPORTS**/
void generateReport(List *pList); // For all Students
void generateReport(List *pList, int attendanceThreshold); // For all Students past a threshold

/**STRING UTILS**/
string formatName(string unformatted);
string makeLowerCase(string unformatted);