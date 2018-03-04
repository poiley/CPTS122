#include "List.h"

// default constructor; will always set mpHead to NULL or nullptr
List::List()                    
{
	mpHead = nullptr;
}

// copy constructor - implicitly invoked copying a List object during construction of 
// another List object, or when a List object is passed-by-value - must perform a deep copy, 
// which means create new memory for each node copied!
List::List(const List &copyList) {
	ListNode *pTemp = copyList.mpHead;
	mpHead = nullptr;
	
	if (copyList.mpHead != nullptr) {
		ListNode *pMem = new ListNode(pTemp->getData());
		ListNode *pCur = pMem;
		
		mpHead = pMem;
		pTemp = pTemp->getNextPtr();

		while (pTemp != nullptr) {
			pMem  = makeNode(pTemp->getData());
			pCur->setNextPtr(pMem);

			pTemp = pTemp->getNextPtr();
			pCur  = pCur->getNextPtr();
		}
	}
}

List::~List()                   // destructor - implicitly invoked when a List object leaves scope
{
	cout << "Inside List's destructor! Freeing each ListNode in the List!" << endl;
	destroyList();
}

// this function must allocate new memory for each of the nodes in rhs to construct "this" object
List & List::operator= (const List &rhs) { // overloaded assignment operator - must perform a deep copy
	deleteAtFront();

	ListNode *pTemp = rhs.mpHead;
	mpHead = nullptr;

	if (rhs.mpHead != nullptr) {
		ListNode *pMem = new ListNode(pTemp->getData());
		ListNode *pCur = pMem;

		mpHead = pMem;
		pTemp = pTemp->getNextPtr();

		while (pTemp != nullptr) {
			pMem = makeNode(pTemp->getData());
			pCur->setNextPtr(pMem);

			pTemp = pTemp->getNextPtr();
			pCur = pCur->getNextPtr();
		}
	}

	return (*this);
}

// getter
ListNode * List::getHeadPtr() const     // returns a copy of the address stored in mpHead
{
	return mpHead;
}

// setter
void List::setHeadPtr(ListNode * const pNewHead) // modifies mpHead
{
	mpHead = pNewHead;
}

// This function creates a new ListNode on the heap, and uses the ListNode constructor to initialize the node!
bool List::insertAtFront(const int newData)     // inserts newData at the beginning or front of the list
{
	ListNode *pMem = makeNode(newData);
	bool success = false;                   // C++ has built in bool types - false, true

	if (pMem != nullptr)
	{
		success = true; // allocated memory successfully
		// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

// insert newData in ascending order
bool List::insertInOrder(const int newData) {
	if (mpHead == NULL) {
		mpHead = makeNode(newData);
		return true;
	}

	ListNode *pMem = makeNode(newData);
	ListNode *pCur = mpHead;
	ListNode *pPrev = nullptr;

	if (pCur != nullptr) {
		while (pCur != nullptr && pCur->getData() < pMem->getData()) {
			pPrev = pCur;
			pCur  = pCur->getNextPtr();
		}
		
		pMem->setNextPtr(pCur);

		if (pPrev == nullptr)
			mpHead = pMem;
		else
			pPrev->setNextPtr(pMem);
		
		return true;
	}

	return false;
}

// inserts newData at the end of the list
bool List::insertAtEnd(const int newData)       
{
	bool success = false;

	// fill in your code here!

	return success;
}

// determines if the list is empty;  
// returns true if the list is empty; false otherwise
bool List::isEmpty()                           
{
	return (mpHead == nullptr);
}

// deletes the node at the front of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtFront()                       
{
	ListNode *pTemp = mpHead->getNextPtr();
	delete mpHead;
	mpHead = pTemp;

	return pTemp->getData();
}

// deletes the node with data == searchValue;
// returns true if the value was found; false otherwise
// precondition: list must not be empty
bool List::deleteNode(const int searchValue)    
{
	bool success = false;

	// fill in your code here! use the delete operator!

	return success;
}

// deletes the node at the end of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtEnd()                         
{
	int data = 0;

	// fill in your code here! use the delete operator!

	return data;
}

// visits each node, print the node's data
void List::printList()                          
{
	ListNode *pCur = mpHead;

	while (pCur != nullptr)
	{
		cout << pCur->getData() << endl;
		pCur = pCur->getNextPtr();
	}
}


//////////// private member functions! //////////////

// allocates memory for a Listnode; initializes the memory with newData
ListNode * List::makeNode(const int newData)    // will only call within insert functions
{
	ListNode *pMem = new ListNode(newData);  // ListNode constructor is invoked!

	return pMem;
}

// we created this function so that we could use recursion to delete the nodes!
void List::destroyListHelper(ListNode * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}

// deletes each node to free memory; will call in the destructor
void List::destroyList()                        
{
	destroyListHelper(mpHead);
}

