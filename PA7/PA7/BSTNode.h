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

class BSTNode {
	public:
		/**CONSTRUCTORS**/
		BSTNode();
		BSTNode(Data &newData);

		/**GETTERS**/
		const Data getData();
		BSTNode *&getLeft();
		BSTNode *&getRight();
	private:
		Data data;
		BSTNode *mpLeft;
		BSTNode *mpRight;
};

/**NON MEMBER FUNCTIONS**/
ostream &operator<<(ostream &out, BSTNode &node);
