/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 6
* Date : Mar 15th, 2018
* Credits : Andrew O'Fallon for instructions 
**********************************************************************/
#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>

#include "Stack.h"

using std::getline;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::stringstream;
using std::string;
using std::to_string;
using std::cout;
using std::cin;
using std::endl;

using std::istream;


typedef struct data {
	int absences;
	int recordNumber;
	int IDNumber;
	int units;
	string name;
	string email;
	string major;
	string level;
	Stack dateOfAbsences;
} Data;