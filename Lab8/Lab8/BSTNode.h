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


bool &operator==(Recipe r1, Reipe r2) {
	int r1ISize = sizeof(r1.getIngredients())/sizeof(*r1.getIngredients());
	int r1DSize = sizeof(r1.getDirections())/sizeof(*r1.getDirections());
	int r2ISize = sizeof(r2.getIngredients())/sizeof(*r2.getIngredients());
	int r2DSize = sizeof(r2.getDirections())/sizeof(*r2.getDirections());

	if(r1.getName() == r2.getName &&
	   r1.getYield() == r2.getYield() &&
	   r1.getnumIngretients() == r2.getnumIngredients()) {
		if(r1ISize != r2ISize)
			return false;

		if(r1DSize != R2Size) 
			return false;s

		for(int i = 0; i < r1ISize; i++)
			if (r1.getIngredients()[i] != r2.getIngredients()[i])
				return false;

		for(int i = 0; i < r2DSize; i++)
			if (r1.getDirections()[i] != r2.getDirections()[i])
				return false;
		return true;

	} else {
		return false;
	}
}

bool searchFor(Recipe *pCurr, Recipe search) {
	if(pCurr == NULL) {
	}
}