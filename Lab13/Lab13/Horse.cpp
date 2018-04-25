#include "Horse.h"

Horse::Horse(void) {
	cout << "Horse constructor..." << endl;
}

Horse::~Horse(void) {
	cout << "Horse destructor..." << endl;
}

void Horse::Move() const {
	cout << "Horse moves a step!" << endl;
}

void Horse::Speak() const {
	cout << "Neigh, bitch." << endl;
}