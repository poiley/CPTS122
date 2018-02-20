// In this example we are working with our first class called Rectangle.

// History: 2/9 - Declared destructor, copy constructor, and
//                computeArea ().
//          2/7 - Declared class Rectangle. Implemented setters/getters,
//                and the default constructor.

#include "Rectangle.h"

int main(void)
{
	// r1 is an object
	Rectangle r1;// constructor is called implicitly!
	r1.setWidth(5.0);
	r1.setLength(7.0);
	std::cout << "width: " << r1.getWidth() << std::endl;

	Rectangle r2 = r1; // copy constructor is called implicitly!
	cout << "area r2: " << r2.computeArea() << std::endl;

	return 0;
}