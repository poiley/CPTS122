#include "Resources.h"

class BSTNode {
public:
	BSTNode();
	BSTNode(string &newData);
	
	const string getData();
	BSTNode *&getLeft();
	BSTNode *&getRight();

private:
	string data;
	BSTNode *mpLeft;
	BSTNode *mpRight;
};

/**NON MEMBER FUNCTIONS**/
ostream &operator<<(ostream &lhs, BSTNode &rhs);
