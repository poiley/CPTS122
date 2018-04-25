#include <iostream>

using std::cout;
using std::endl;


class Base {
	public:
		virtual void testFunction();
};

class Derived : public Base {
	public:
		void testFunction();
};