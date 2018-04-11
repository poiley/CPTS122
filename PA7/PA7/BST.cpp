/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 7
 * Date : Mar 28th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 *			Using code written in lab with Alexa, Jeff, and Brandon.
 **********************************************************************/

/**IMPORTS**/
#include "BST.h"

/**CONSTRUCTORS & DESTRUCTORS**/
BST::BST() { 
	Data unsortedMorse[39];
	string line, lineData;
	int index = 0, size = sizeof(unsortedMorse) / sizeof(*unsortedMorse);
	ifstream morseData("MorseTable.txt");

	while (getline(morseData, line, '\n')) {
		istringstream morseStream(line);

		getline(morseStream, lineData, ' ');
		unsortedMorse[index].letter = lineData.c_str()[0];

		getline(morseStream, lineData, ' ');
		unsortedMorse[index].morse = lineData;

		index++;
	}

	sort(unsortedMorse, unsortedMorse + size, compareAscii);
	
	this->mpRoot = (BSTNode *)malloc(sizeof(BSTNode));
	this->mpRoot = new BSTNode();
	
	insertR(unsortedMorse, 0, size / 2, size - 1);
	insert(unsortedMorse[38]);
}

BST::BST(BSTNode *&copy) { this->mpRoot = copy; }

BST::~BST() { destroyBST(this->mpRoot); }

void BST::destroyBST(BSTNode *pTree) {
	if (pTree != NULL) {
		destroyBST(pTree->getLeft());
		destroyBST(pTree->getRight());
		delete pTree;
	}
}

/**SETTERS**/
void BST::insertR(Data arr[], int startIndex, int middleIndex, int endIndex) {
	int firstHalfLen  = middleIndex - startIndex + 1;
	int secondHalfLen = endIndex - middleIndex;
	
	if (endIndex > 39 || startIndex < 0 || endIndex - startIndex <= 1) {
		if (endIndex - startIndex == 1)
			insert(arr[startIndex]);
		return;
	}
	
	Data *firstHalf  = new Data[firstHalfLen],
		 *secondHalf = new Data[secondHalfLen];

	for (int i = 0; i < firstHalfLen; i++)
 		firstHalf[i] = arr[startIndex + i];
	
	for (int i = 0; i < secondHalfLen; i++)
		secondHalf[i] = arr[middleIndex + i + 1];

	insert(arr[middleIndex]);

	insertR(firstHalf, 0, firstHalfLen / 2, firstHalfLen - 1);
	insertR(secondHalf, 0, secondHalfLen / 2, secondHalfLen - 1);
}

void BST::insert(Data &newData) { insertHelper(mpRoot, newData); }

void BST::insertHelper(BSTNode *&pTree, Data &newData) {
	if (pTree == nullptr)
		pTree = new BSTNode(newData);
	else if (newData.letter < pTree->getData().letter)
		insertHelper(pTree->getLeft(), newData);
	else
		insertHelper(pTree->getRight(), newData);
}

/**GETTERS**/
bool BST::isEmpty() { return (this->mpRoot == nullptr); }

void BST::print() const { printHelper(this->mpRoot, 0); }

void BST::printHelper(BSTNode *pTree, int indent) const {
	if (pTree != nullptr) {
		printHelper(pTree->getLeft(), indent + 4);

		if(indent)
			cout << std::setw(indent) << " ";
		cout << pTree->getData().letter << endl << " ";

		printHelper(pTree->getRight(), indent + 4);
	}
	cout << endl;
}

string BST::search(char query) { return searchHelper(this->mpRoot, toupper(query)); }

string BST::searchHelper(BSTNode *pTree, char query) {
	if (pTree != nullptr)
		if (pTree->getData().letter == query)
			return pTree->getData().morse;
		else if (query < pTree->getData().letter)
			return searchHelper(pTree->getLeft(), query);
		else
			return searchHelper(pTree->getRight(), query);
}