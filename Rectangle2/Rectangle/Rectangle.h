#pragma once

#include <iostream>

using std::cout; // allow for us to now use cout << instead of std::cout << 
using std::cin;
using std::endl;

//using namespace std; - don't do this!

class Rectangle
{
public:

	// all functions here are considered member functions

	// constructor
	Rectangle(); // default constructor
	// copy constructor
	Rectangle(Rectangle &copy);
	// destructor
	~Rectangle(); // clean up resources, i.e. heap memory, streams

	// getters/setters - accessors/mutators
	double getLength();
	double getWidth();

	void setLength(double newLength);
	void setWidth(double newWidth);

	double computeArea();

private:
	double mLength; // data members
	double mWidth;
};