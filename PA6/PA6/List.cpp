/*****************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS**/
#include "List.h"

/**CONSTRUCTOR**/
List::List() { pHead = (Node *)malloc(sizeof(Node)); }

/**DESTRUCTOR**/
List::~List() {
	delete pHead;
}

/**GETTERS**/
Node * List::getHead() const { return pHead; }

bool List::isEmpty() { return pHead == nullptr; }

/**SETTTERS**/
void List::setHead(Node * const newData) { pHead = newData; }

void List::insertFront(Node *newNode) {
	if (newNode != nullptr) {
		newNode->setNext(pHead);
		pHead = newNode;
	}
}
