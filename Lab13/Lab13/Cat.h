#pragma once

#include "Mammal.h"

class Cat : public Mammal {
	public:
		Cat(void);
		~Cat(void);

		void Move() const;
		void Speak() const;
	protected:
			int itsAge;
};
