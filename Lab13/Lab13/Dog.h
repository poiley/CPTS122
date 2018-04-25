#pragma once

#include "Mammal.h"

class Dog : public Mammal {
	public:
		Dog(void);
		~Dog(void);

		void Move() const;
		void Speak() const;

	protected:
			int itsAge;
};
