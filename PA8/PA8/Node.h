/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 8
 * Date : Apr 9th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 **********************************************************************/

#include "Resources.h"

class Node {
	public:
		/**Constructors & Destructors**/
		Node();
		Node(string &newData);
		virtual ~Node() {}

		/**Getters**/
		const string getData();
		Node *&getLeft();
		Node *&getRight();
		
		// Pure Virtual function makes class `BSTNode` abstract
		virtual void printData() = 0; 
	protected:
		/**Private data**/
		string mData;
		Node *mpLeft;
		Node *mpRight;
};

/**Non-Member Functions**/
ostream &operator<<(ostream &out, Node &node);
