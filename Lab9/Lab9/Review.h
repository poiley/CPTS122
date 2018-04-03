#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>

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

class Node {
	public:
		Node() {};
		Node(Node &copy) { this->pNext = copy.pNext; this->data = copy.data; };
	private:
		Node *pNext;
		int data;
};

class List {
	public:
		List() {};
		List(List &copy);
	private:
		Node *pHead = (Node *)malloc(sizeof(Node));
};