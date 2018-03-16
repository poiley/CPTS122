/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 5
* Date : Mar 1st, 2018
* Credits : Andrew O'Fallon for instructions and guidance with Queue
*			code
**********************************************************************/

#include "QueueNode.h"

/**CONSTRUCTORS**/
QueueNode::QueueNode() {
	pData = (Data *)malloc(sizeof(Data));
	pData = nullptr;
	pNext = nullptr;
}

QueueNode::QueueNode(const Data &newData) {
	pData = (Data *)malloc(sizeof(Data));
	this->pData = new Data(newData);
	this->pNext = nullptr;
}

QueueNode::QueueNode(const QueueNode &copy) {
	pData = (Data *)malloc(sizeof(Data));
	this->pData = copy.pData;
	this->pNext = copy.pNext;
}

/**GETTERS**/
Data *QueueNode::getData() {
	return this->pData;
}

QueueNode *QueueNode::getNextPtr() {
	return this->pNext;
}

/**SETTERS**/
void QueueNode::setData(Data *newData) {
	this->pData = newData;
}

void QueueNode::setNextPtr(QueueNode *pMem) {
	this->pNext = pMem;
}
