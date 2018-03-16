#include "Stack.h"

Stack::Stack() {
	index = -1;
}

void Stack::push(string newData) {
	index++;
	data[index] = newData;
}

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