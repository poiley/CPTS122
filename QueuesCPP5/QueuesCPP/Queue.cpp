#include "Queue.h"

bool Queue::enqueue(const string &newPrintJob)
{
	// inserting at the end of the linked list
	Node *pMem = nullptr;
	
	pMem = new Node(newPrintJob);

	bool success = false;

	if (this->mpHead == nullptr)
	{
		// empty queue
		this->mpHead = this->mpTail = pMem;
	}
	else
	{
		// queue is not empty
		this->mpTail->setNextPtr(pMem);
		this->mpTail = pMem;
	}

	success = true;

	return success;
}

// precondition: queue is not empty
string Queue::dequeue()
{
	string s1 = "";

	// one node in queue
	if (this->mpHead == this->mpTail)
	{
		s1 = this->mpHead->getPrintJob();
		delete this->mpHead; // this->mpTail is a dangling pointer right now!
		this->mpHead = this->mpTail = nullptr;
	}
	else // more than 1 node in queue
	{
		Node *pTemp = nullptr;
		pTemp = this->mpHead;
		s1 = this->mpHead->getPrintJob();
		//delete pTemp;
		this->mpHead = this->mpHead->getNextPtr();
		delete pTemp;
	}

	return s1;
}

bool Queue::isEmpty()
{
	return (this->mpHead == nullptr);
}

Queue::~Queue ()
{
	destroyQueue();
}

void Queue::destroyQueue()
{
	while (!isEmpty())
	{
		dequeue();
	}
	// head and tail?
	if (this->mpTail == nullptr && this->mpHead == nullptr)
	{
		cout << "Deleted all nodes" << endl;
	}
}


Queue::Queue()
{
	this->mpHead = this->mpTail = nullptr;
}