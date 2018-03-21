#include "Functions.h"

void readCSVToList(List **pList) {
	List *dataList = *pList;
	Data dataTemp = { NULL };

	int index = 0;
	string line, data, temp;
	ifstream classData("classList.csv");

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

void writeListToMaster(List *pList) {
	Node *pTemp = pList->getHead();
	ofstream output("master.txt");

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

void attendanceCheck(List **pList) {
	List *dataList = *pList;
	Node *pTemp = dataList->getHead();

	int menu = 0;
	while (pTemp != NULL) {
		cout << "Is " << pTemp->getName() << " absent? \n1.) Yes\n2.) No\n-> ";
		cin >> menu;

		if (menu == 1) {
			pTemp->setAbsencesDate();
			cout << endl << pTemp->getName() << " marked absent." << endl;
		}

		cout << endl;
		
		pTemp = pTemp->getNext();
	}

	*pList = dataList;
}

void generateReport(List *pList) {
	Node *pTemp = pList->getHead();
	ofstream output("FullAttendanceReport.txt");

	while (pTemp != NULL) {
		if (pTemp->getAbsencesList().isEmpty())
			output << pTemp->getName() << ",0," << endl;
		else
			output << pTemp->getName() << "," << pTemp->getAbsences() << "," << pTemp->getRecentAbsence() << endl;

		pTemp = pTemp->getNext();
	}

	output.close();
}

void generateReport(List *pList, int attendanceThreshold) {
	Node *pTemp = pList->getHead();
	ofstream output("ThresholdAttendanceReport.txt");

	while (pTemp != NULL) {

		if ( pTemp->getAbsences() >= attendanceThreshold ) {
			output << pTemp->getName() << endl;

			Stack tempList = pTemp->getAbsencesList();
			for (int i = 0; i < pTemp->getAbsences(); i++)
				output << "\t" << i + 1 << ".) " << tempList.pop() << endl;
		}
		
		pTemp = pTemp->getNext();
	}

	output.close();
}

void editAbsence(List **pList) {
	List *dataList = *pList;
	Node *pTemp = dataList->getHead();

	string nameQuery, newDate;
	int absenceQuery, menu, date;
	cout << "Name to edit absence for (FIRST LAST)?" << endl << "-> ";
	cin >> nameQuery;
	cout << endl;

	cout << nameQuery << endl;
	nameQuery = makeLowerCase(nameQuery);
	
	while (pTemp != NULL) {
		if (nameQuery == makeLowerCase(pTemp->getName()))
			break;
		pTemp = pTemp->getNext();
	}

	if (makeLowerCase(pTemp->getName()) != nameQuery) {
		cout << "Name match not found for name '" << nameQuery << "'" << endl;
		return;
	}

	//pTemp is the entry we want to edit.
	if (pTemp->getAbsences() == 0) {
		cout << "Student '" << pTemp->getName() << "' has no absences to edit" << endl;
		return;
	}

	Stack tempStack = pTemp->getAbsencesList();

	for (int i = 0; i < pTemp->getAbsences(); i++)
		cout << i << ".) " << tempStack.pop() << endl;

	cout << "Which # absence would you like to edit?" << endl << "-> ";
	cin >> absenceQuery;
	cout << endl;

	if (absenceQuery > pTemp->getAbsences() || absenceQuery < 1) {
		cout << "Index out of bounds. Please try again." << endl;
		return;
	}

	tempStack = pTemp->getAbsencesList();
	Stack foo;
	for (int i = 1; i <= absenceQuery; i++)
		foo.push(tempStack.pop());

	cout << "(1) Edit or (2) Delete entry?" << endl << "-> ";
	cin >> menu;

	if (menu == 1) {
		cout << endl << "Year? ";
		cin >> date;
		newDate = date + "-";
		cout << endl << "Month? ";
		cin >> date;
		newDate = newDate + to_string(date) + "-";
		cout << endl << "Day? ";
		cin >> date;
		newDate = newDate + to_string(date);
		tempStack.push(newDate);
	}

	foo.pop();
	while (!foo.isEmpty())
		tempStack.push(foo.pop());

	pTemp->setAbsencesStack(tempStack);

	*pList = dataList;
}

string formatName(string unformatted) {
	string str, out;
	int a = 0;
	istringstream stream(unformatted);

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
	for (int i = 0; i < unformatted.length(); i++) {
		temp[i] = tolower(temp[i]);
	}
	return temp;
}