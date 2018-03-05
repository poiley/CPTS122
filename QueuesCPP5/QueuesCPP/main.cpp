// History: 2/23 - Implemented destructor for Queue and destroyQueue ()
//          2/21 - Implemented dequeue () and isEmpty () functions
//          2/16 - Implemented an enqueue ()/insert function for
//                 a queue. Introduced some basic file processing
//                 with std::fstream objects.

#include "Queue.h"


int main(void)
{
	Node n1, n2("printjob1");
	Queue q1;
	Queue *pQ2 = new Queue();
	string s1 = "printjob1";

	fstream input("printjobs.txt");

	q1.enqueue(s1);
	q1.enqueue("pj2");
	q1.enqueue("pj3");
	q1.enqueue("pj4");


	bool success = q1.isEmpty();
	if (!success)
	{
		cout << "removed: " << q1.dequeue() << endl;
	}

	//input.open()

	/*string s1 = "";
	input >> s1;
	cout << s1 << endl;
	input >> s1;
	cout << s1 << endl;
	char s2[100] = "";
	input.getline(s2, 100);
	cout << s2 << endl;*/

	// nonmember - getline()

	input.close();

	return 0;
}