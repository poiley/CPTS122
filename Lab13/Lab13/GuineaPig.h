#pragma once

#include "Mammal.h"

class GuineaPig : public Mammal {
	public:
		GuineaPig(void);
		~GuineaPig(void);

		void Move() const;
		void Speak() const;
	protected:
			int itsAge;
};
