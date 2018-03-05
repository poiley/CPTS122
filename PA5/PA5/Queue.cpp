#include "Resources.h"
#include "Queue.h"

Queue::Queue() {
	this->pHead = nullptr;
	this->pTail = nullptr;
}

Queue::~Queue() {
	destroy();
}

bool Queue::enqueue(Data &newData) { //insert
	QueueNode *pMem = nullptr; // inserting at the end of the linked list

	pMem = new QueueNode(&newData);

	if (this->pHead == nullptr) {
		this->pHead = pMem;
		this->pTail = pMem;
	} else { // queue is not empty
		this->pTail->setNextPtr(pMem);
		this->pTail = pMem;
	}

	return true; 
}

Data Queue::dequeue() { // delete
	Data *toDelete;
	if (this->pHead == this->pTail) { 
		toDelete = this->pHead->getData();
		delete this->pHead; 
		this->pHead = nullptr;
		this->pTail = nullptr;
	} else { 
		QueueNode *pTemp = nullptr;
		pTemp = this->pHead;
		toDelete = this->pHead->getData();
		
		this->pHead = this->pHead->getNextPtr();
		delete pTemp;
	}

	return *toDelete;
}

void Queue::printQueue() { //print

}

bool Queue::isEmpty() {
	if (this->pHead == nullptr)
		return true;
	return false;
}

void Queue::destroy() {
	while ( !isEmpty() )
		dequeue();

	if ( this->pHead == nullptr && this->pTail == nullptr )
		cout << "Queue cleared." << endl;
}
