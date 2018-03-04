#include "ListApp.h"

int main(void) {
	// Start with debugging this project! "Step Into" each statement to answer the questions!
	// Question 1:	what function is called in the statement below?
	// Answer 1:	ListNode's default constructor, which takes an integer, making the n1 object's data NULL.
	ListNode n1;
	// Question 2:	what function is called in the statement below?
	// Answer 2:	ListNode's default constructor, taking in the integer 42, making n2's object data 42.
	ListNode n2(42); // Shallow Copy
	// Question 3:	what function is called in the statement below?
	// Answer 3:	ListNode's copy constructor. 
	ListNode n3(n2); // Shallow Copy
	// Question 4:	what function is called in the statement below?
	// Answer 4:	Replacing n4 with n3.
	ListNode n4 = n3; // Deep Copy
	
	ListNode n5;
	// Question 5:	what function/operator is called in the statement below?
	// Answer 5:	The default equals operator.
	n5 = n4; // did we explicitly implement this function/operator? No.

	// Question 6: what function is called in the statement below?
	List l1;
	// make sure that you finish implementing the copy constructor for the List object before you try to 
	// execute the next statement!
	// Question 7: what function is called in the statement below? What would happen if we did not 
	//             explicitly implement the function? Would the compiler generated one be good enough?
	// List l2 = l1; // shallow or deep copy?
	// Question 8: what would happen if a shallow copy constructor is used, instead of a deep copy constructor, 
	//             when the destructor for each list object is implicily invoked? l2 and l1 would have the same
	//             address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//             out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!


	List l3;
	// make sure that you finish implementing the overloaded assignment for the List object before you try to 
	// execute the next statement!
	// Question 9: what function is called in the statement below? What would happen if we did not 
	//             explicitly implement the function? Would the compiler generated one be good enough?
	// l3 = l2; // shallow or deep copy? 
	// Question 10: what would happen if a shallow copy assignment is used, instead of a deep copy assignment, 
	//              when the destructor for each list object is implicily invoked? l3 and l2 would have the same
	//              address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//              out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!

	// Question 11: how does the List destructor free up the nodes? You will need to visit "List.cpp" to answer this question!

	ListApp app;

	app.runApp();

	return 0;
}