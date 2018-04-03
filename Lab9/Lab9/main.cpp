// This example illustrates how to define a Stack class template.

#include "TestStack.h"
#include <vector>
using std::vector;
int sort(string input);

int main(void) {
	int item1 = -89, item2 = 104;

	sort("Hello");
	//	vector<int> my_vector; // vector<> is from the Standard Template Library (STL)

	TestStack<int> tester; // STACK IS LIFO

	tester.Test(item1, item2);

	return 0;
}

int sort(string input) {
	Stack<int> test;
	vector<char> split(input.begin(), input.end());

	for (int i = 0; i < input.length(); i++) {
		if (split[i] == '+' || split[i] == '-' || split[i] == '*' || split[i] == '/') {
			int n1, n2, result;
			test.pop(n1);
			test.pop(n2);
			switch (split[i]) {
				case '+':
					result = n1 + n2;
					break;
				case '-':
					result = n1 - n2;
					break;
				case '*':
					result = n1 * n2;
					break;
				case '/':
					result = n1 / n2;
			}
			test.push(result);
		} else {
			int toPush = split[i];
			test.push(toPush);
		}
	}

	return 0;
}