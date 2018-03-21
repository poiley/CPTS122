/*****************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS/NAMESPACE IMPORTS**/
#include <string> // It seemed uneccessary to import all of Resoures.h in here.
using std::string;

/**CLASSES**/
class Stack {
	public: 
		/**CONSTRUCTOR/DESTRUCTOR**/
		Stack();
		~Stack();
		
		/**SETTER**/
		void push(string newData);

		/**GETTERS**/
		string pop();
		string peek();
		bool isEmpty();
	private:
		/**PRIVATE DATA**/
		int index;
		string data[100];
};