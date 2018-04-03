/*****************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS**/
#include "Functions.h"

/**READ FROM FILES**/
void readCSVToList(List **pList) {
	List *dataList = *pList;
	Data dataTemp = { NULL };
	ifstream classData("classList.csv");
	string line, data, temp;
	int index = 0;

	while (getline(classData, line, '\n')) {
		istringstream iss(line);
		
		if (line.front() == *",")
			continue;
		
		for (int i = 0; i <= 7; i++) {
			getline(iss, data, ',');

			switch (i) {
				case 0:
					dataTemp.recordNumber = atoi(data.c_str());
					break;
				case 1:
					dataTemp.IDNumber = atoi(data.c_str());
					break;
				case 2: 
					if (data.front() == *"\"")
						dataTemp.name = data.erase(0,1);
					break;
				case 3:
					if (data.back() == *"\"")
						dataTemp.name = data.erase(data.size() - 1) + " " + dataTemp.name;
					break;
				case 4:
					dataTemp.email = data;
					break;
				case 5:
					if (data == "AU")
						dataTemp.units = -1;
					else 
						dataTemp.units = atoi(data.c_str());
					break;
				case 6:
					dataTemp.major = data;
					break;
				case 7:
					dataTemp.level = data;
					break;
			}
		}

		Node *nodeTemp = new Node(dataTemp);
		dataList->insertFront(nodeTemp);
	}

	*pList = dataList;
}

void readMasterToList(List **pList) {
	List *dataList = *pList;
	Data dataTemp = { NULL };

	int index = 0;
	string line, data, temp, date;
	ifstream studentData("master.txt");

	while (getline(studentData, line, '\n')) {
		istringstream iss(line);

		if (line.front() == *",")
			continue;
		
		for (int i = 0; i <= 9; i++) {
			getline(iss, data, ',');

			switch (i) {
				case 0:
					dataTemp.recordNumber = atoi(data.c_str());
					break;
				case 1:
					dataTemp.IDNumber = atoi(data.c_str());
					break;
				case 2:
					if (data.front() == *"\"")
						dataTemp.name = data.erase(0, 1);
					break;
				case 3:
					if (data.back() == *"\"")
						dataTemp.name = data.erase(data.size() - 1) + " " + dataTemp.name;
					if (data.front() == *" ")
						dataTemp.name.erase(0, 1);
					break;
				case 4:
					dataTemp.email = data;
					break;
				case 5:
					if (data == "AU")
						dataTemp.units = -1;
					else
						dataTemp.units = atoi(data.c_str());
					break;
				case 6:
					dataTemp.major = data;
					break;
				case 7:
					dataTemp.level = data;
					break;
				case 8:
					dataTemp.absences = atoi(data.c_str());
				case 9:
					if (data.at(0) == *"{")
						data.erase(0, 1);

					if (data == "}")
						break;
					else if (data.at(data.size() - 1) == *"}")
						data.erase(data.size() - 1);

					istringstream absenceListStream(data);
					
					while (getline(absenceListStream, date, ','))
						dataTemp.dateOfAbsences.push(date);
			}
		}

		Node *nodeTemp = new Node(dataTemp);
		dataList->insertFront(nodeTemp);
	}

	*pList = dataList;
}

/**CHECK ATTENDANCE**/
void attendanceCheck(List **pList) {
	List *dataList = *pList;
	Node *pTemp = dataList->getHead();

	int menu = 0;
	while (pTemp != NULL) {
		cout << endl << "Is " << pTemp->getName() << " absent? \n1.) Yes\n2.) No\n-> ";
		cin >> menu;

		if (menu == 1) {
			pTemp->setAbsencesDate();
			cout << endl << pTemp->getName() << " marked absent." << endl;
		}
		
		pTemp = pTemp->getNext();
	}

	*pList = dataList;
}

/**WRITE TO FILES**/
void writeListToMaster(List *pList) {
	List backup = *pList;
	Node *pTemp = pList->getHead();
	ofstream output("master.txt", ofstream::out | ofstream::trunc);

	output << ",ID,Name,Email,Units,Program,Level,Absences,{AbsenceList}" << endl;

	while (pTemp != NULL) {
		string absenceList = "{";

		Stack tempStack = pTemp->getAbsencesList();
		for (int i = 0; i < pTemp->getAbsences(); i++)
			absenceList += tempStack.pop();

		absenceList += "}";

		stringstream line;
		line << pTemp->getRecordNumber() << ","
			 << to_string(pTemp->getID()) << ","
			 << formatName(pTemp->getName()) << ","
			 << pTemp->getEmail() << ","
			 << to_string(pTemp->getUnits()) << ","
			 << pTemp->getMajor() << ","
			 << pTemp->getLevel() << ","
			 << to_string(pTemp->getAbsences()) << ","
			 << absenceList;

		output << line.str() << endl;

		pTemp = pTemp->getNext();
	}

	output.close();
}

/**GENERATE REPORTS**/
void generateReport(List *pList) { // For all Students
	Node *pTemp = pList->getHead();
	ofstream output("FullAttendanceReport.txt");

	while (pTemp != NULL) {
		if (pTemp->getAbsences() == 0)
			output << pTemp->getName() << ",0," << endl;
		else
			output << pTemp->getName() << "," << pTemp->getAbsences() << "," << pTemp->getRecentAbsence() << endl;

		pTemp = pTemp->getNext();
	}

	output.close();
}

void generateReport(List *pList, int attendanceThreshold) { // For all Students past a threshold
	Node *pTemp = pList->getHead();
	ofstream output("ThresholdAttendanceReport.txt");

	while (pTemp != NULL) {
		if (pTemp->getAbsences() >= attendanceThreshold) {
			output << pTemp->getName() << endl;

			Stack tempList = pTemp->getAbsencesList();
			for (int i = 0; i < pTemp->getAbsences(); i++)
				output << "\t" << i + 1 << ".) " << tempList.pop() << endl;
		}
		
		pTemp = pTemp->getNext();
	}

	output.close();
}

/**ASSIGNMENT BONUS**/
void editAbsence(List **pList) {
	List *dataList = *pList;
	Node *pTemp = dataList->getHead();

	string nameQuery, newDate;
	int absenceQuery, menu, date;

	cout << "Name to edit absence for (FIRST LAST)?" << endl << "-> ";
	cin.ignore(1, '\n');
	getline(cin, nameQuery);

	nameQuery = makeLowerCase(nameQuery);
	
	while (pTemp != NULL) {
		if (nameQuery == makeLowerCase(pTemp->getName()))
			break;
		pTemp = pTemp->getNext();
	}

	if (makeLowerCase(pTemp->getName()) != nameQuery) {
		cout << "Name match not found for name '" << nameQuery << "'" << endl << endl;
		return;
	}

	if (pTemp->getAbsences() == 0) {
		cout << "Student '" << pTemp->getName() << "' has no absences to edit" << endl << endl;
		return;
	}

	Stack attendanceStack = pTemp->getAbsencesList(), tempData;

	for (int i = 0; i < pTemp->getAbsences(); i++)
		cout << i + 1 << ".) " << attendanceStack.pop() << endl;

	cout << "Which # absence would you like to edit?" << endl << "-> ";
	cin >> absenceQuery;

	if (absenceQuery > pTemp->getAbsences() || absenceQuery < 1) {
		cout << endl << "Index out of bounds. Please try again." << endl << endl;
		return;
	}

	attendanceStack = pTemp->getAbsencesList();

	for (int i = 1; i <= absenceQuery; i++)
		tempData.push(attendanceStack.pop());

	cout << endl << "(1) Edit or (2) Delete entry?" << endl << "-> ";
	cin >> menu;

	if (menu == 1) {
		cout << endl << "Year? ";
		cin >> date;
		newDate = to_string(date) + "-";

		cout << endl << "Month? ";
		cin >> date;
		newDate = newDate + to_string(date) + "-";

		cout << endl << "Day? ";
		cin >> date;
		newDate = newDate + to_string(date);

		attendanceStack.push(newDate);
	} else if (menu == 2) {
		pTemp->setAbsences(pTemp->getAbsences() - 1);
	} else {
		cout << "Index out of bounds. Please try again." << endl << endl;
	}

	tempData.pop();
	while (!tempData.isEmpty())
		attendanceStack.push(tempData.pop());

	pTemp->setAbsencesStack(attendanceStack);

	cout << endl;

	*pList = dataList;
}

/**STRING UTILS**/
string formatName(string unformatted) {
	istringstream stream(unformatted);
	string str, out;
	int a = 0;

	while (getline(stream, str, ' ')) {
		if (a == 0)
			out = str;
		else if (a == 1)
			out = "\"" + str + "," + out + "\"";
		else
			break;
		a++;
	}
	return out;
}

string makeLowerCase(string unformatted) {
	string temp = unformatted;
	for (int i = 0; i < unformatted.length(); i++)
		temp[i] = tolower(temp[i]);
	return temp;
}