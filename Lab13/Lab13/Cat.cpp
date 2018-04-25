#include "Cat.h"

Cat::Cat(void) {
	cout << "Cat constructor..." << endl;
}

Cat::~Cat(void) {
	cout << "Cat destructor..." << endl;
}

void Cat::Move() const {
	cout << "Cat moves a step!" << endl;
}

void Cat::Speak() const {
	cout << "Meow, bitch." << endl;
}