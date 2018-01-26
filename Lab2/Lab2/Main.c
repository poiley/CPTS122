#include "Header.h"

int main(void) {
	// Stack: Manually Allocated Memory upon runtime. Stuff you've specified and objects you've manually created.
	// Heap:  Dyamically Allocated Memory. Things stored in memory after runtime with malloc()

	// Head: The first Node in a List 
	Node *pHead;

	Node *pList; 
}

/*
Once you create things in the stack and don't assign it to a pointer in the heap, you have a memory leak.


INSTERT AT FRONT FUNCTION:
	Node *pMem, *pNext, *pHead;

	

	//Set the address of pNext that pMem stores to be the address of pHead
	pMem -> pNext = pHead; //Make pMem point in memory to pHead 

	pHead = pMem; //Set the address of pMem to be the new head. pHead is not overwritten but already shifted up in the list

RANDOM NOTES:
	// pMem is a temporary pointer to keep track of things
	// "pMem ->" == "(*pMem)."
	// Essentially, POINT_IN_MEMORY->ATTRIBUTE_OF_NODE_AT_POINT_IN_MEMORY

	//given the pointer to a node, find the value at that address
	pHead->data;

	Node **pHead is a pointer to the pointer of the Node.
*/