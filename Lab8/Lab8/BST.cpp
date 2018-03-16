#include "BST.h"

BST::BST(BSTNode *&copy) {
	this->mpRoot = copy;
}

BST::~BST() {
	destroyBST(this->mpRoot);
}

void BST::destroyBST(BSTNode *pTree) {
	if (pTree != NULL) {
		destroyBST(pTree->getLeft());
		destroyBST(pTree->getRight());
		delete pTree;
	}
}

bool BST::isEmpty() {
	return (this->mpRoot == nullptr);
}

void BST::insertNode(string &newData) {
	insertNode(mpRoot, newData);
}

void BST::insertNode(BSTNode *&pTree, string &newData) {
	if ( pTree == nullptr ) {
		BSTNode *pMem = new BSTNode(newData);
		pTree = pMem;
	} else if (newData < pTree->getData()) {
		insertNode(pTree->getLeft(), newData);
	} else {
		insertNode(pTree->getRight(), newData);
	}
}

void BST::inOrderTraversal() {
	inOrderTraversal(this->mpRoot);
}

void BST::inOrderTraversal(BSTNode *pTree) {
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeft());
		cout << pTree << " ";
		inOrderTraversal(pTree->getRight());
	}
	cout << endl;
}

void BST::preOrderTraversal() {
	preOrderTraversal(this->mpRoot);
}

void BST::preOrderTraversal(BSTNode *pTree) {
	if (pTree != nullptr) {
		cout << pTree << " ";
		preOrderTraversal(pTree->getLeft());
		preOrderTraversal(pTree->getRight());
	}
	cout << endl;
}

void BST::postOrderTraversal() {
	postOrderTraversal(this->mpRoot);
}

void BST::postOrderTraversal(BSTNode *pTree) {
	if (pTree != nullptr) {
		postOrderTraversal(pTree->getLeft());
		postOrderTraversal(pTree->getRight());
		cout << pTree << " ";
	}
	cout << endl;
}
