/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 7
 * Date : Mar 28th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 *			Using code written in lab with Alexa, Jeff, and Brandon.
 **********************************************************************/

/**IMPORTS**/
#include "Resources.h"
#include "BSTNode.h"

#include <iomanip>

class BST {
	public:
		/**CONSTRUCTORS & DESTRUCTORS**/
		BST();
		BST(BSTNode *&copy);
		~BST();
		
		/**SETTERS**/
		void insert(Data &newData);

		/**GETTERS**/
		bool isEmpty();
		void print() const; // some print code borrowed from StackOverflow
		string search(char query);
	private:
		BSTNode *mpRoot;

		/**DESTRUCTOR**/
		void destroyBST(BSTNode *pTree);
		
		/**SETTERS**/
		void insertHelper(BSTNode *&pTree, Data &newData);
		void insertR(Data arr[], int startIndex, int middleIndex, int endIndex);
		
		/**GETTERS**/
		string searchHelper(BSTNode *pTree, char query);
		void printHelper(BSTNode *pTree, int indent) const;
};

/**NON MEMBER FUNCTIONS**/
bool compareAscii(Data lhs, Data rhs); // for sorting before inserting