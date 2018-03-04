#pragma once

#include <iostream>
#include <fstream>

#include "ListNode.h"
#include "List.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

class ListApp
{
public:
	ListApp();   // default constructor - open files
	~ListApp();  // destructor - close files

	// we will not define a copy constructor or overloaded assignment; will leave it up to compiler!

	void runApp(void);

private:
	ifstream mInputStream;  // the file stream associated with "ExamScore.csv"
	ofstream mOutputStream; // the file stream associated with "ExamStats.txt"
	List mList; // this is a sequence container!
};

// nonmember function - overloaded stream extraction (ifstream, List)
ifstream & operator>> (ifstream &input, List &rhs);