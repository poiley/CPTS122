#include "Resources.h"
#include "BSTNode.h"

class BST {
public:
	BST(BSTNode *&copy);
	~BST();

	bool isEmpty();
	
	void insertNode(string &newData);
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();
private:
	BSTNode *mpRoot;
	
	void destroyBST(BSTNode *pTree);

	void insertNode(BSTNode *&pTree, string &newData);
	void inOrderTraversal(BSTNode *pTree);
	void preOrderTraversal(BSTNode *pTree);
	void postOrderTraversal(BSTNode *pTree);
};