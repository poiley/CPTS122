/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 8
 * Date : Apr 9th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 **********************************************************************/

#include "TransactionNode.h"

class BST {
	public:
		/**Constructors & Destructors**/
		BST();
		~BST();
		
		/**Setters**/
		void setRoot(Node *newNode);
		void insert(string &newProductData, int &newUnitData);

		/**Getters**/
		bool isEmpty();
		Node *getRoot();
		void inOrderTraversal() const; // some print code borrowed from StackOverflow
		TransactionNode &findSmallest();
		TransactionNode &findLargest();

	private:
		Node *mpRoot;

		/**Destructor**/
		void destroyTree(Node *&pTree);
		
		/**Setters**/
		void insertHelper(Node *&pTree, string &newProductData, int &newUnitData);

		/**Getters**/
		void inOrderTraversalHelper(Node *pTree, int indent) const;
};