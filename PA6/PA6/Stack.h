#include <string>
using std::string;

class Stack {
	public: 
		Stack();
		void push(string newData);
		string pop();
		string peek();
		bool isEmpty();
	private:
		int index;
		string data[100];
};