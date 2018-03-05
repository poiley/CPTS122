#include "QueueNode.h"

QueueNode::QueueNode() {
	Data *pData = (Data *)malloc(sizeof(Data));
	pData = nullptr;
	pNext = nullptr;
}

QueueNode::QueueNode(Data *newData) {
	Data *pData = (Data *)malloc(sizeof(Data));
	this->pData = newData;
	this->pNext = nullptr;
}

void QueueNode::setNextPtr(QueueNode *pMem) {
	this->pNext = pMem;
}

QueueNode *QueueNode::getNextPtr() {
	return this->pNext;
}

void QueueNode::setData(Data *newData) {
	this->pData = newData;
}

Data *QueueNode::getData() {
	return this->pData;
}