#pragma once

#include "Mammal.h"

class Horse : public Mammal {
	public:
		Horse(void);
		~Horse(void);

		void Move() const;
		void Speak() const;
	protected:
			int itsAge;
};
