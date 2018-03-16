#include "Functions.h"

void csvToList(List **pList) {
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

	while (pTemp != NULL) {
		if (pTemp->getAbsencesList().isEmpty())
			cout << pTemp->getName() << ",0," << endl;
		else
			cout << pTemp->getName() << "," << pTemp->getAbsences() << "," << pTemp->getRecentAbsence() << endl;

		pTemp = pTemp->getNext();
	}
}

void generateReport(List *pList, int attendanceThreshold) {
	Node *pTemp = pList->getHead();

	while (pTemp != NULL) {
		if (pTemp->getAbsencesList().isEmpty() || pTemp->getAbsences() < attendanceThreshold) {
			pTemp = pTemp->getNext();
			continue;
		}

		cout << pTemp->getName() << endl;

		Stack absentDates = pTemp->getAbsencesList();
		for (int i = 0; i < pTemp->getAbsences(); i++) {
			cout << "\t" << i+1 << ".) " << absentDates.pop() << endl;
		}

		pTemp = pTemp->getNext();
	}
}