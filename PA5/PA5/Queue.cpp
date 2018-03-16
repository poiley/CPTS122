/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 5
* Date : Mar 1st, 2018
* Credits : Andrew O'Fallon for instructions and guidance with Queue
*			code
**********************************************************************/

#include "Resources.h"
#include "Queue.h"

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Default constructor. Sets Head and Tail nodes to null.
 */
Queue::Queue() {
	this->pHead = nullptr;
	this->pTail = nullptr;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Deconstructor. Calls helper function `destroy`.
 */
Queue::~Queue() {
	destroy();
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Insert into queue
 * CREDIT: Used Andy O'Fallon's code as a starting point
 */
bool Queue::enqueue(const Data &newData) { 
	QueueNode *pMem = nullptr; // inserting at the end of the linked list
	pMem = new QueueNode(newData); //create new object that's a copy of the parameter Data `newData`

	if (this->pHead == nullptr) // if the lenght of the queue is 0 (null), assign accordingly
		this->pHead = pMem;
	else // queue is not empty
		this->pTail->setNextPtr(pMem);
	this->pTail = pMem;

	return true; 
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Delete from queue
 * CREDIT: Used Andy O'Fallon's code as a starting point
 */
Data Queue::dequeue() { 
	Data *dataToDelete; //store the data do delete for returning

	if (this->pHead == this->pTail) { // if the length of the queue's start is the same as the end (length = 1), empty the queue 
		dataToDelete = this->pHead->getData();

		delete this->pHead; 
		
		this->pHead = nullptr;
		this->pTail = nullptr;
	} else { // if the queue is not empty and not of size 1
		QueueNode *pTemp = nullptr; // create a new node, assign the data and remove it.
		pTemp = this->pHead;
		
		dataToDelete = this->pHead->getData();
		this->pHead = this->pHead->getNextPtr();
		
		delete pTemp;
	}

	return *dataToDelete; // return data of the deleted node
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Print all items in queue.
 */
void Queue::printQueue() { //print
	QueueNode *pMem = this->pHead;
	while (pMem != nullptr) {
		Data *tempData = pMem->getData();
		cout << "CUSTOMER #" << tempData->getCustomerNumber() << endl;
		cout << "\tSvc Time: " << tempData->getServiceTime() << endl;
		pMem = pMem->getNextPtr();
	}

	if (this->isEmpty())
		cout << "Queue Empty." << endl;

	cout << endl;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Returns simple boolean if the Queue is empty or not.
 */
bool Queue::isEmpty() { 
	if (this->pHead == nullptr)
		return true;
	return false;
}

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Helper function for deleting and clearing the Queue. 
 * CREDIT: Used Andy O'Fallon's code as a starting point
 */
void Queue::destroy() {
	while ( !isEmpty() )
		dequeue(); // calls dequeue while the queue isn't empty
}
