/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 7
 * Date : Mar 28th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 *			Using code written in lab with Alexa, Jeff, and Brandon.
 **********************************************************************/

/**IMPORTS**/
#include "BSTNode.h"

/**CONSTRUCTORS**/
BSTNode::BSTNode() { this->mpLeft = this->mpRight = nullptr; }

BSTNode::BSTNode(Data &newData) {
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
	this->data = newData;
}

/**GETTERS**/
const Data BSTNode::getData() { return this->data; }

BSTNode *& BSTNode::getLeft() { return this->mpLeft; }

BSTNode *& BSTNode::getRight() { return this->mpRight; }

/**NON MEMBER FUNCTIONS**/
ostream &operator<<(ostream &out, BSTNode &node) {
	node.getData().morse;
	return out;
}
