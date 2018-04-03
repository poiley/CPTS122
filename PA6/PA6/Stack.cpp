/******************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS**/
#include "Stack.h"

/**CONSTRUCTOR**/
Stack::Stack() { index = -1; }

/**DESTRUCTOR**/
Stack::~Stack() { // I don't think this is ever called, but keeping it in to be safe.
	while (!isEmpty())
		pop();
}

/**GETTER**/
void Stack::push(string newData) {
	index++;
	data[index] = newData;
}

/**SETTERS**/
string Stack::pop() {
	string temp = peek();
	
	data[index] = "";
	index--;
	
	return temp;
}

string Stack::peek() {
	return data[index];
}

bool Stack::isEmpty() {
	if (index == -1)
		return true;
	return false;
}