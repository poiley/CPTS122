/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 8
 * Date : Apr 9th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 **********************************************************************/

#include "TransactionNode.h"

 /**Constructors & Destructors**/
TransactionNode::TransactionNode(string newProduct, int newUnits) : Node(newProduct) {
	this->mUnits = newUnits;
}

/**Getters**/
int TransactionNode::getUnits() { return this->mUnits; }

void TransactionNode::printData() { cout << this->mData << ", " << this->mUnits; }

/**Setters**/
void TransactionNode::setUnits(int newUnits) { this->mUnits = newUnits; }


