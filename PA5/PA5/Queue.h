#include "QueueNode.h"

class Queue {
	public: // Member functions
		Queue();
		~Queue();

		void destroy();
		bool isEmpty();

		bool enqueue(Data &data); //insert
		Data dequeue(); // delete
		void printQueue(); //print
	private:
		QueueNode *pHead;
		QueueNode *pTail;
};