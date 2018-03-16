#include "BSTNode.h"

BSTNode::BSTNode() {
	this->mpLeft = this->mpRight = nullptr;
	this->data = "";
}

BSTNode::BSTNode(string &newData) {
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
	this->data = newData;
}

/**GETTERS**/
const string BSTNode::getData() { return this->data; }

BSTNode *& BSTNode::getLeft() { return this->mpLeft; }

BSTNode *& BSTNode::getRight() { return this->mpRight; }

/**NON MEMBER FUNCTIONS**/
ostream &operator<<(ostream &lhs, BSTNode &rhs) {
	lhs << "'" << rhs.getData() << "'";
	return lhs;
}
