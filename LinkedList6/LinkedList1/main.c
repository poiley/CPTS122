#include "LinkedList.h"

// History: 1/26/18 - Implemented the rest of deleteStudent ()
//                    and started discussing doubly linked lists.
//                    We modified the struct node, makeNode (),
//                    and insertAtFront () to work with doubly
//                    linked lists.
//          1/24/18 - Implemented InsertInOrder (), started
//                    deleteStudent ()
//          1/22/18 - Implemented deleteAtFront (), 
//                    which we'll use as a function to learn
//                    how to test. Also, implemented printListRec ()
//          1/19/18 - Defined struct node, implemented
//                    makeNode (), insertAtFront (),
//                    and executed 1 case for insertAtFront ()
//
//          1/17/18 - Defined struct student, discussed
//                    operations and behavior of lists

int main(int argc, char *argv[])
{
	Student list[200]; // We could implement a list data structure
	                   // with an array. However, we're going to use
                       // links/pointers.

	Node *pList = NULL; // this is a pointer to the first
	                    // node in our singly linked list
	Student s1 = {111111, "Alexa"}, s2 = { 111111, "Zak" },
		s3 = { 111111, "Betty" },
		*pStudent = NULL;
	int success = 0;


	success = insertInOrder(&pList, s3);
	success = insertInOrder(&pList, s2);
	success = insertInOrder(&pList, s1);
	printListRec(pList);

	putchar('\n');
	success = deleteStudent(&pList, s3);
	printListRec(pList);
	/*success = insertAtFront(&pList, s1);
	success = insertAtFront(&pList, s1);
	success = insertAtFront(&pList, s1);
	success = insertAtFront(&pList, s1);

	printf("%d %s\n", pList->s.id, pList->s.name);

	pStudent = deleteAtFront(&pList);

	printf("%d %s\n", pStudent->id, pStudent->name);
	printf("%d\n", pList);*/

	

	return 0;
}