#include "Resources.h"
#include "Node.h"

class List {
	public:
		List();

		/**GETTERS**/
		Node * getHead() const;
		bool isEmpty();

		/**SETTERS**/
		void setHead(Node * const newData);
		void insertFront(Node *newNode);
	
		//int deleteAtFront();
	private:
		Node *pHead;
};