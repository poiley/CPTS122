/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 2
* Date : Jan 24th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include "Header.h"


int displayMenu() {
	int menu = -1, submenu = -1;
	char *query;
	printf("\n(1)\tload\n(2)\tstore\n(3)\tdisplay\n(4)\tinsert\n(5)\tdelete\n(6)\tedit\n(7)\tsort\n(8)\trate\n(9)\tplay\n(10)\tshuffle\n(11)\texit");
	
	while (!(menu >= 1 && menu <= 11)) {
		printf("\n->\t");
		scanf("%d", &menu);
	}

	printf("Success!");

	switch (menu) {
		case 3:
			printf("\n(1)\tLoad all\n(2)\tLoad by Artist\n");
			
			while (!(submenu == 1 || submenu == 2)) {
				printf("\n->\t");
				scanf("%d", &submenu);
			}

			switch (submenu) {
				case 1:
					printList(pList);
					break;
				case 2:
					printf("Artist?\n->\t");
					scanf("%s", &query);
					printList(pList, query);
			}

			break;
		case 8:
			printf("\nSong?\n->\t");
			scanf("%s", &query);
			rate(pList, query);
			break;
		case 11:
			return 11;
	}

}

Node * makeNode(Record newData) {
	Node * pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL) {
		pMem->pNext = NULL;
		pMem->data = newData;
	}

	return pMem;
}

Boolean insertFront(Node **pList, Record newData) {
	Node *pMem = makeNode(newData);

	if (pMem == NULL)
		return (Boolean)FALSE;

	pMem->pNext = *pList;
	*pList = pMem;

	return TRUE;
}

Boolean deleteContact(Node **pList, Record search) {
	Node *pCurrent = *pList;

	if (strcmp(pCurrent->data.song, search.song) == 0) {
		pCurrent->pNext = pCurrent->pNext->pNext;
		free(pCurrent->pNext);
		return TRUE;
	}

	while ((pCurrent->pNext != NULL) && (strcmp(pCurrent->pNext->data.song, search.song) != 0))
		pCurrent = pCurrent->pNext;

	if (pCurrent->pNext != NULL) {
		pCurrent->pNext = pCurrent->pNext->pNext;
		free(pCurrent->pNext);
		return TRUE;
	}

	return FALSE;
}

Boolean rate(Node *pList, char *query) {
	Node *pCurrent = pList;

	if (strcmp(pCurrent->data.song, query) == 0) {
		pCurrent->data.rating = rate_query(); //where are ratings stored, object-wise????
		return TRUE;
	}

	while ((pCurrent->pNext != NULL) && (strcmp(pCurrent->data.song, query) != 0))
		pCurrent = pCurrent->pNext;

	if (pCurrent->pNext != NULL) {
		pCurrent->data.rating = rate_query();
		return TRUE;
	}

	return FALSE;
}

// I wrote this because I'm lazy and I'm calling it twice in `rate()` so it seemed efficient
int rate_query() { 
	int newRating = -1;
	
	while ( !(newRating <= 5 && newRating >= 1) ) {
		printf("Rating?\n->\t");
		scanf("%s", &newRating);
	}
	
	return newRating;
}

void printList(Node *pList) {
	Node *pCurrent = pList;
	
	while (pCurrent->pNext != NULL) {
		printf("\"%s\" \tby %s\n",pCurrent->data.song, pCurrent->data.artist);
		pCurrent = pCurrent->pNext;
	}
}

void printList(Node *pList, char *query) {
	Node *pCurrent = pList;

	printf("Music by %s:\n", query);
	
	while (pCurrent->pNext != NULL) {
		if (strcmp(pCurrent->data.artist, query) == 0)
			printf("\"%s\"", pCurrent->data.song);
		pCurrent = pCurrent->pNext;
	}
}