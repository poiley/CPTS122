/*****************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS**/
#include "Node.h"

/**CONSTRUCTORS**/
Node::Node() {
	studentData.absences = studentData.recordNumber = studentData.IDNumber = studentData.units = NULL;
	studentData.name = studentData.email = studentData.major = studentData.level = "";
	pNext = nullptr;
}

Node::Node(Data newData) {
	studentData.absences		= newData.absences;
	studentData.recordNumber	= newData.recordNumber;
	studentData.IDNumber		= newData.IDNumber;
	studentData.units			= newData.units;
	studentData.name			= newData.name;
	studentData.email			= newData.email;
	studentData.major			= newData.major;
	studentData.level			= newData.level;
	studentData.dateOfAbsences	= newData.dateOfAbsences;
	pNext = nullptr;
}

Node::Node(const Node &copy) {
	this->studentData.absences		= copy.getAbsences();
	this->studentData.recordNumber	= copy.getRecordNumber();
	this->studentData.IDNumber		= copy.getID();
	this->studentData.units			= copy.getUnits();
	this->studentData.name			= copy.getName();
	this->studentData.email			= copy.getEmail();
	this->studentData.major			= copy.getMajor();
	this->studentData.level			= copy.getLevel();
	this->studentData.dateOfAbsences= copy.getAbsencesList();
	this->pNext						= copy.getNext();
}

/**GETTERS**/
int Node::getAbsences() const { return studentData.absences; }

int Node::getRecordNumber() const { return studentData.recordNumber; }

int Node::getID() const { return studentData.IDNumber; }

int Node::getUnits() const { return studentData.units; }

string Node::getName() const { return studentData.name; }

string Node::getEmail() const { return studentData.email; }

string Node::getMajor() const { return studentData.major; }

string Node::getLevel() const { return studentData.level; }

Data Node::getData() const { return studentData; }

Node * Node::getNext() const { return pNext; }

string Node::getRecentAbsence() { return studentData.dateOfAbsences.peek(); }

Stack Node::getAbsencesList() const { return studentData.dateOfAbsences; }

/**SETTERS**/
void Node::setAbsences(int newData) { studentData.absences = newData; }

void Node::setRecordNumber(int newData) { studentData.recordNumber = newData; }

void Node::setID(int newData) { studentData.IDNumber = newData; }

void Node::setUnits(int newData) { studentData.units = newData; }

void Node::setName(string newData) { studentData.name = newData; }

void Node::setEmail(string newData) { studentData.email = newData; }

void Node::setMajor(string newData) { studentData.major = newData; }

void Node::setLevel(string newData) { studentData.level = newData; }

void Node::setNext(Node * const newData) { pNext = newData; }

void Node::setAbsencesStack(Stack newData) { studentData.dateOfAbsences = newData; }

// CREDIT ANON STACK OVERFLOW USER - https://stackoverflow.com/questions/997946
void Node::setAbsencesDate() { 
	stringstream date;
	
	time_t t = time(0);
	struct tm * now = localtime(&t);
	date << (now->tm_year + 1900) << '-'
		 << (now->tm_mon + 1) << '-'
		 << now->tm_mday;
	
	studentData.dateOfAbsences.push(date.str()); // Add date to Stack
	setAbsences(getAbsences() + 1); // Add one to absence list
}