/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 8
 * Date : Apr 9th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 **********************************************************************/

#include "BST.h"

class DataAnalysis {
	public:
		/**Constructors & Destructors**/
		DataAnalysis();
		~DataAnalysis() {}

		/**Misc**/
		void runAnalysis();
	private:
		/**Private data**/
		BST mTreeSold;
		BST mTreePurchased;
		ifstream mCsvStream;

		/**Setters**/
		void openStream();
		bool parseLineFromStream(string *transactionField, int *unitField, string *typeField);
		void insertInTrees(string transaction, int unit, string type);
		void readAndDisplayFile(); // calls parseLineFromStream and insertInTrees
		
		/**Getter**/
		void displayTrends();
};