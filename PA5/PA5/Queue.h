/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 5
* Date : Mar 1st, 2018
* Credits : Andrew O'Fallon for instructions and guidance with Queue
*			code
**********************************************************************/

#include "QueueNode.h"

class Queue {
	public: // Member functions
		Queue();
		~Queue();

		bool isEmpty();

		bool enqueue(const Data &newData); //insert
		Data dequeue(); // delete
		void printQueue(); //print
	private:
		void destroy();

		QueueNode *pHead;
		QueueNode *pTail;
};