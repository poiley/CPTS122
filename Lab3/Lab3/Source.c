#include "Header.h"

int isEmpty(Stack s) {
	if (s.pTop == NULL)
		return 1;	//empty
	return 0;		//not empty
}

Node *newNode(double newData) {
	Node *n		= (Node *)malloc(sizeof(Node));
	n->pNext	= NULL;
	n->data		= newData;
	return n;
}

double peek(Stack *s) {
	return s->pTop->data;
}

int push(Stack *s, double newData) {
	Node *pMem	= newNode(newData);
	
	if (pMem == NULL)
		return 0;

	pMem->pNext = s->pTop;
	s->pTop		= pMem;

	return 1;
}

double pop(Stack *s) {
	double toReturn = -1.0;
	if (isEmpty(*s) == 0) {
		toReturn	= s->pTop->data;
		Node *pFree = s->pTop;
		s->pTop		= s->pTop->pNext;
		free(pFree);
	}
	return toReturn;
}