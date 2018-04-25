#include "Mammal.h"

Mammal::Mammal(void) :itsAge(1) {
	cout << "Mammal constructor..." << endl;
}

Mammal::~Mammal(void) {
	cout << "Mammal destructor..." << endl;
}

void Mammal::Move() const {
	cout << "Mammal moves a step!" << endl;
}

void Mammal::Speak() const {
	cout << "??? ???, bitch." << endl;
}