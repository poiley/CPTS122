#include "Header.h"

Node * makeNode(Contact newData) {
	Node * pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL) {
		pMem->pNext = NULL;
		pMem->data = newData;
	}

	return pMem;
}

Boolean insertContactInOrder(Node **pList, Contact newData) {
	Node *pMem = makeNode(newData);

	if (pMem == NULL)
		return FALSE;

	pMem->pNext = *pList;
	*pList = pMem;

	return TRUE;
}

Boolean deleteContact(Node **pList, Contact searchContact) {
	Node *pCurrent = *pList;

	if (strcmp(pCurrent->data.name, searchContact.name) == 0) {
		pCurrent->pNext = pCurrent->pNext->pNext;
		free(pCurrent->pNext);
		return TRUE;
	}
	
	while (	(pCurrent->pNext != NULL) && 
			(strcmp(pCurrent->pNext->data.name, searchContact.name) != 0))
		pCurrent = pCurrent->pNext;

	if (pCurrent->pNext != NULL) {
		pCurrent->pNext = pCurrent->pNext->pNext;
		free(pCurrent->pNext);
		return TRUE;
	}

	return FALSE;
}

Boolean editContact(Node *pList, Contact searchContact) {
	Node *pCurrent = pList;
	char *phone = NULL;

	printf("\nWhat would you like to change %s's phone number to?\n-> ", searchContact.name);
	scanf("%s", &phone);

	if (strcmp(pCurrent->data.name, searchContact.name) == 0) {
		strcpy(pCurrent->pNext->data.name, phone);
		return TRUE;
	}

	while ((pCurrent->pNext != NULL) &&
		   (strcmp(pCurrent->pNext->data.name, searchContact.name) != 0))
		pCurrent = pCurrent->pNext;

	if (pCurrent->pNext != NULL) {
		strcpy(pCurrent->pNext->data.name, phone);
		return TRUE;
	}

	return FALSE;
}

Boolean loadContacts(FILE *infile, Node **pList) { //not finished
	int i = 0, num_contacts = 0;

	if (i == num_contacts)
		return TRUE;
	return FALSE;
}

Boolean storeContacts(FILE *infile, Node *pList) {

}

void printList(Node *pList) {

}

/*
Node * makeNode(int newData) {

}

void insertAtFront(Node **pHead, int data) {
	Node *pMem = makeNode(data);
	pMem->pNext = *pHead;
	*pHead = pMem;
}
*/