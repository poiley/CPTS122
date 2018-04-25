#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Mammal {
	public:
		Mammal(void);
		~Mammal(void);

		virtual void Move() const;
		virtual void Speak() const;

	protected:
		int itsAge;
};