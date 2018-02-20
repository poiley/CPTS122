#include "Main.h"
#include "Complex.h"

int main(void) {
	Complex original(4, 5.4);
	Complex toAdd(5, 6.5);

	toAdd = add(original, toAdd);

	cout << "String" << 8 << endl;
	
	return 0;
}
