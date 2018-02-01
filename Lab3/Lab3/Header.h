#include <stdio.h>

typedef struct node {
	struct node *pNext;
	double data;
} Node;

typedef struct stack {
	Node *pTop;
} Stack;

Node *newNode(double newData);
double peek(Stack *s);
double pop(Stack *s);
int push(Stack *s, double newData);
int isEmpty(Stack s);