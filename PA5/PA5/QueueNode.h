#include "Resources.h"
#include "Data.h"

class QueueNode {
	public: // Member Functions
		QueueNode();
		QueueNode(Data *newData);
		void setNextPtr(QueueNode *pMem);
		void setData(Data *newData);

		QueueNode *getNextPtr();
		Data *getData();
	private:
		Data *pData; // The memory for Data will need to be allocated on the heap as well
		QueueNode *pNext;
};