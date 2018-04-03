/*****************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS**/
#include "Resources.h"
#include "Node.h"

/**CLASSES**/
class List {
	public:
		/**CONSTRUCTOR/DESTRUCTOR**/
		List();
		~List();
		
		/**GETTERS**/
		Node * getHead() const;
		bool isEmpty();

		/**SETTERS**/
		void setHead(Node * const newData);
		void insertFront(Node *newNode);
	private:
		/**PRIVATE DATA**/
		Node *pHead;
};