#pragma once

#include <iostream>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

class Queue
{
public:
	Queue();
	// bool = true, false
	bool enqueue(const string &newPrintJob);
	string dequeue();
	bool isEmpty(); // predicate function
	~Queue();

	// C - int enqueue (Queue *pQ, char *newPrintJob);

private:
	Node *mpHead;
	Node *mpTail;
	void destroyQueue();
};