/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 5
* Date : Mar 1st, 2018
* Credits : Andrew O'Fallon for instructions and guidance with Queue
*			code
**********************************************************************/

#include "Resources.h"
#include "Data.h"

class QueueNode {
	public: // Member Functions
		QueueNode();
		QueueNode(const Data &newData);
		QueueNode(const QueueNode &copy);
		void setNextPtr(QueueNode *pMem);
		void setData(Data *newData);

		QueueNode *getNextPtr();
		Data *getData();
	private:
		Data *pData; // The memory for Data will need to be allocated on the heap as well
		QueueNode *pNext;
};