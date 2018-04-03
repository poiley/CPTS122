/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 7
 * Date : Mar 28th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 *			Using code written in lab with Alexa, Jeff, and Brandon.
 **********************************************************************/

#include "BST.h";

int main(void) {
	BST *pTree = new BST(); // Master Tree
	
	string toConvert; // Input, unconverted string
	ifstream infile("Convert.txt"); // Plaintext

	// Convert, line by line, the plaintext file
	while (getline(infile, toConvert, '\n')) { 
		for (int i = 0; i < toConvert.length(); i++) {
			if (toConvert[i] == *" ")
				cout << " ";
			else
				cout << pTree->search(toConvert[i]) << " ";
		}
		cout << endl;
	}

	return 0;
}