#include "Node.h"

Node::Node(const string &newPrintJob)
{
	this->mPrintJob = newPrintJob;
	this->mpNext = nullptr;
}
Node::Node(const Node &newNode)
{
	// to be filled in later
}

Node::~Node()
{
	cout << "Inside destructor for Node!" << endl;
	//delete this;
}

string Node::getPrintJob() const
{
	return this->mPrintJob;
}

Node * Node::getNextPtr() const
{
	return this->mpNext;
}

void Node::setPrintJob(const string &newPrintJob)
{
	this->mPrintJob = newPrintJob;
}

void Node::setNextPtr(Node * const newNextPtr)
{
	this->mpNext = newNextPtr;
}