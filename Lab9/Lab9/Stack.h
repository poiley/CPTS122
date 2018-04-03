// This file contains a stack class template. The underlying data structure for the 
// stack is an array allocated from the heap.

#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack {
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T &newItem); 
	bool pop(T &poppedItem);
	bool peek(T &item);

	bool isEmpty();

private:
	int mSize; // represents the current number of items in the stack
	int mMaxSize; // must not exceed the max size of our allocated array
	T *mTop; // will point to contigous memory on the heap (an array)
};

template <class T>
Stack<T>::Stack(int newSize) {
	mSize = newSize; // this can also be used as the index to the top of the stack
	mMaxSize = 100;
	mTop = new T[100]; // allocating an array of 100 items of type T on the heap
}

template <class T>
Stack<T>::~Stack() {
	delete[] mTop; // this is how we free up an array on the heap in C++
}

// Places the newItem at the top of the stack
template <class T>
bool Stack<T>::push(T &newItem) {
	if (mSize == mMaxSize)
		return false;
	mTop[mSize++] = newItem;
	return true;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you pop. Places the popped item in 
// the parameter referred to as "poppedItem". Returns true if the item was popped; false
// otherwise.
template <class T>
bool Stack<T>::pop(T &poppedItem) {
	if (this->isEmpty())
		return false;
	poppedItem = mTop[--mSize];
	return true;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you peek. Places the item at the top of the
// stack in the parameter referred to as "item". Returns true if there
// is an item at the top; false otherwise.
template <class T>
bool Stack<T>::peek(T &item) {
	if (this->isEmpty()) 
		return false;
	item = this->mTop[this->mSize - 1];
	return true;
}

// Returns true if the stack is empty; false otherwise
template <class T>
bool Stack<T>::isEmpty() { return !mSize; }