#include "Exam1.h"

Node *findMax(Node *pList1, Node *pList2, Node *pMax) {
	if (pList1 == NULL || pList2 == NULL)
		return pMax;

	if (pList1->data > pList2->data && pList1->data >= pMax->data)
		pMax = pList1;
	else if (pList1->data < pList2->data && pList2->data >= pMax->data)
		pMax = pList2;
	else if (pList1->data == pList2->data && pList1->data >= pMax->data)
		pMax = pList1;

	return findMax(pList1->pNext, pList2->pNext, pMax);
}

void copyList(Node *pList, Node **pMem) {
	Node *pNewList = NULL;
	
	while (pList != NULL) {
		pNewList = (Node *)malloc(sizeof(Node));
		pNewList = pList;
		
		pList = pList->pNext;
		pNewList = pList->pNext;
	}

	*pMem = pNewList;
}

void insertInOrder(Node **pList, char *myData) {
	Node *pNewList = NULL, *pMem = NULL;
	pNewList = (Node *)malloc(sizeof(Node));

	while (pList != NULL) {
		if( strcmp((*pList)->myData, myData) == 1 && (*pList)->pNext == NULL)
			(*pList)->pNext = pNewList;
		if (strcmp((*pList)->myData, myData) == 1 && strcmp((*pList)->pNext->myData, myData) == -1) {
			pNewList->pNext = (*pList)->pNext->pNext;
			(*pList)->pNext = pNewList;
		}	
		*pList = (*pList)->pNext;
	}
}