#include "ListNode.h"

// constructor - "constructs" a ListNode; initializes the object
ListNode::ListNode(int newData)
{
	mData = newData;
	mpNext = nullptr;
}

// copy constructor - implicitly invoked copying a ListNode object during construction of 
// another ListNode object, or when a ListNode object is passed-by-value
ListNode::ListNode(const ListNode &copy)
{
	// shallow copy performed!
	mData = copy.mData;
	mpNext = copy.mpNext;
}

// destructor - implicitly invoked when a ListNode object leaves scope
ListNode::~ListNode()
{
	// Yes, these nodes are dynamically allocated, but delete will be invoked invoked by functions in List.
	// Hence, don't need to deallocate the heap memory inside of this destructor!
	cout << "Inside ListNode's destructor!" << endl;
}

int ListNode::getData() const // the const indicates "constant" function; can't modify the object's data members with this function
{
	return mData;
}

ListNode * ListNode::getNextPtr() const // the const indicates "constant" function; can't modify the object's data members with this function
{
	return mpNext;
}

void ListNode::setData(const int newData) // the const in this context ensures newData can't be modified
{
	mData = newData;
}

// the const in this context ensures pNewNext can't be modified;
// remember read as pNewNext is a constant pointer to a ListNode - the ListNode object is not const though!
void ListNode::setNextPtr(ListNode * const pNewNext) 
{
	mpNext = pNewNext;
}