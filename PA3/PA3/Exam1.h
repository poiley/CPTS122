#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *findMax(Node *pList1, Node *pList2, Node *pMax); //11
void copyList(Node *pList, Node **pMem); //12
void insertInOrder(Node **pList, char *myData); //13

typedef struct node {
	int data;
	char *myData;
	struct Node *pNext;
} Node;