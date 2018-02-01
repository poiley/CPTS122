#include "testStack.h"

int main(void) {
	testPeek();
	testPop();
	testPush();
	testEmpty();
	testNotEmpty();
}

void testPeek() {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	push(&*s, 4.0);
	push(&*s, 5.0);

	double peekDouble = peek(s);

	if (s->pTop != NULL && peekDouble == 5.0)
		printf("[PASS] test: testPeek\n");
	else
		printf("[FAIL] test: testPeek\n");
}

void testPop() {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	
	push(&*s, 4.0);
	push(&*s, 5.0);

	double popped = pop(&*s);

	if (s->pTop != NULL && popped == 5.0)
	 	printf("[PASS] test: testPop\n");
	else
		printf("[FAIL] test: testPop\n");
}

void testPush() {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	
	push(&*s, 4.0);

	if(s->pTop != NULL && s->pTop->data == 4.0)
		printf("[PASS] test: testPush\n");
	else
		printf("[FAIL] test: testPush\n");
}

void testEmpty() {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->pTop = NULL;

	if (isEmpty(*s) == 1)
		printf("[PASS] test: testEmpty\n");
	else 
		printf("[FAIL] test: testEmpty\n");
}

void testNotEmpty() {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	push(&*s, 4.0);

	if (isEmpty(*s) == 0)
		printf("[PASS] test: testNotEmpty\n");
	else
		printf("[FAIL] test: testNotEmpty\n");
}

