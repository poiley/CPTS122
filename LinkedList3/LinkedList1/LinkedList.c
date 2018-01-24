#include "LinkedList.h"

Node *makeNode(Student newStudent) { // place the value inside the container
	Node *pMem = NULL;

	pMem = (Node *) malloc(sizeof (Node));

	if (pMem != NULL) { // space was allocated
		pMem -> pNext = NULL;
		pMem -> s = newStudent; // we want to make a copy!
	}

	return pMem;
}

int insertAtFront(Node **pList, Student newStudent) { // list operation
	Node *pMem = NULL;
	int success = 0;

	pMem = makeNode(newStudent);

	if (pMem != NULL) { // we allocated space for a Node and initialized it
		// connect the new Node/container to the list
		pMem -> pNext = *pList;
		*pList = pMem;
		success = 1;
	}

	return success;
}


//precondition: list must not be empty
Student *deleteAtFront(Node **pList) {
	
	//think state of list?
	Student *pStudent = NULL;

	pStudent = &(*pList) -> s; // SIDE NOTE: "->" means points at
	//pList is a ** pointer, which means points to an address
	//You go to the address of **pList and find the address of the Node
	//Cuz it's an address of a node (struct), the address gives us the object
	//the object stores the next nodes location and Student data
	
	(*pList) = (*pList) -> pNext; //shift pList's address onwards

	//find the next node in memory and free it from memory
	free( &(*pList) -> pNext );
	
	return pStudent;
}

void printListRec(Node *pList) {

	// base case ? - implied
	if ( pList != NULL ) { //recursive step
		printf("ID: %d, %s\n", pList -> s.id, pList -> s.name);
		printListRec(pList -> pNext);
	}
	printf("-->");
}