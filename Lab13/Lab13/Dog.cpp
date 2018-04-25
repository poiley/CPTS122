#include "Dog.h"

Dog::Dog(void) {
	cout << "Dog constructor..." << endl;
}

Dog::~Dog(void) {
	cout << "Dog destructor..." << endl;
}

void Dog::Move() const {
	cout << "Dog moves a step!" << endl;
}

void Dog::Speak() const {
	cout << "Bark bark, bitch." << endl;
}