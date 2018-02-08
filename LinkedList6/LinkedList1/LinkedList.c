#include "LinkedList.h"

Node *makeNode(Student newStudent) // place the value inside the container
{
	Node *pMem = NULL;

	pMem = (Node *) malloc(sizeof (Node));

	if (pMem != NULL) // space was allocated
	{
		pMem->pPrev = NULL; // for doubly linked list
		pMem->pNext = NULL;
		pMem->s = newStudent; // we want to make a copy!
	}

	return pMem;
}

int insertAtFront(Node **pList, Student newStudent) // list operation
{
	Node *pMem = NULL;
	int success = 0;

	pMem = makeNode(newStudent);

	if (pMem != NULL) // we allocated space for a Node and initialized it
	{
		// connect the new Node/container to the list
		if (*pList != NULL) // not empty list
		{
			pMem->pNext = *pList;
			(*pList)->pPrev = pMem; // doubly linked list
			*pList = pMem;
			success = 1;
		}
		else // empty list
		{
			//pMem->pNext = *pList;
			//*pList)->pPrev = pMem;
			*pList = pMem;
			success = 1;
		}
	}

	return success;
}

// we need to discuss how to test this function!
// precondition: list must not be empty!
Student *deleteAtFront(Node **pList)
{
	// think state of list?
	Student *pStudent = NULL;
	Node *pTemp = NULL;

	pStudent = &((*pList)->s); // heap we can do this!

	pTemp = (*pList)->pNext;
	//free((Node *) &((*pList)->pNext));

	(*pList) = pTemp;

	return pStudent;

	//free(*pList);
}

// prints all data in the list recursively
void printListRec(Node *pList)
{
	// base case? - implied
	if (pList != NULL) // recursive step
	{
		printf("ID: %d, %s-->\n", pList->s.id, pList->s.name);
		printListRec(pList->pNext);
	}
	
}

// a - z based on name
int insertInOrder(Node **pList, Student newStudent)
{
	Node *pMem = NULL, *pCur = NULL, *pPrev = NULL;
	int success = 0;

	pMem = makeNode(newStudent);

	if (pMem != NULL) // malloc () returned a valid address
	{
		success = 1;
		pCur = *pList;

		// short-circuit!
		while ((pCur != NULL) &&
			(strcmp(newStudent.name, pCur->s.name) > 0)) // to search for place to insert new student
		{
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		// Found where to insert node/student
		if (pPrev != NULL) // not inserting at front or empty list
		{
			pPrev->pNext = pMem;
			pMem->pNext = pCur;
		}
		else // inserting at front or empty list
		{
			*pList = pMem;
			pMem->pNext = pCur;
		}
	} // end if

	return success;
}

// removes a student from the list
int deleteStudent(Node **pList, Student searchKey)
{
	Node *pCur = NULL, *pPrev = NULL;
	int success = 0;

	pCur = *pList;
	while (pCur != NULL && 
		strcmp(searchKey.name, pCur->s.name) != 0)
	{
		pPrev = pCur;
		pCur = pCur->pNext;
	}

	// need to finish!!!
	if (pPrev != NULL && pCur != NULL) // removing a student that is not at the front of list
	{
		success = 1;
		pPrev->pNext = pCur->pNext;
		free(pCur);
	}
	else if (pPrev == NULL && pCur != NULL) // removing student at front
	{
		success = 1;
		*pList = pCur->pNext;
		free(pCur);
	}
	else // didn't find student in list
	{
		printf("Student not in list\n");
	}

	return success;
}
