#include "Main.h"
#include "Student.h"

int main(void) {
	//user input:
	//	cin >> num;

	Student st1(18, 3.2, "Benjamin");

	cout << "Name:\t" << st1.getName() << endl;
	cout << "Age:\t"  << st1.getAge()  << endl;
	cout << "GPA:\t"  << st1.getGPA()  << endl;

	return 0;
}