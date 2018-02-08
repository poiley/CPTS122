/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 3
* Date : Feb 4th, 2018
* Credits : Andrew O'Fallon for instructions, guidance, printList()
*			and struct code.
**********************************************************************/

#include "Header.h"

int main() {
	Node *pList = (Node *)malloc(sizeof(Node)); // Allocate the memory for the linked list.
	int option = -1;							// Initialize the main menu selector.

	while (option != 11)						// As long as the user hasn't input an 11 (meaing quit), loop.
		option = displayMenu(&pList);			// Display the menu in `Functions.c` and edit the Linked List 
												// according to the user's selected menu choice.

	printf("Quitting!\n");						// If the user has decided to quite, display the quit option.
	return 0;									// Quit/return.
}