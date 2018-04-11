/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 8
 * Date : Apr 9th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 **********************************************************************/

#include "DataAnalysis.h"

/**Constructors & Destructors**/
DataAnalysis::DataAnalysis() { openStream(); }

/**Misc**/
void DataAnalysis::runAnalysis() {
	readAndDisplayFile(); // calls `parseLineFromStream()` and `insertInTrees()`
	displayTrends();
}

/**Setters**/
void DataAnalysis::openStream() { mCsvStream.open("data.csv"); }

bool DataAnalysis::parseLineFromStream(string *transactionField, int *unitField, string *typeField) {
	string lineData, fieldData;

	// Get a line from the file, and if it's NULL/EOF, return false
	if (!getline(mCsvStream, lineData, '\n'))
		return false;

	// After reading from file, skip the first line and assign data
	if (lineData[0] != *"U") { // skip first line ("U" being the first letter of the first line)
		istringstream lineStream(lineData);

		getline(lineStream, fieldData, ',');
		*unitField = stoi(fieldData);

		getline(lineStream, fieldData, ',');
		*typeField = fieldData;

		getline(lineStream, fieldData, ',');
		*transactionField = fieldData;
	}

	return true;
}

void DataAnalysis::insertInTrees(string transaction, int unit, string type) {
	if (transaction == "Purchased")
		mTreePurchased.insert(type, unit);
	else if (transaction == "Sold")
		mTreeSold.insert(type, unit);
}

void DataAnalysis::readAndDisplayFile() { // calls `parseLineFromStream()` and `insertInTrees()`
	string transaction, type;
	int unit;

	// Read file and insert into Trees
	while (parseLineFromStream(&transaction, &unit, &type))
		insertInTrees(transaction, unit, type);

	// Output Trees to screen
	cout << endl << "PURCHASED: " << endl;
	mTreePurchased.inOrderTraversal();

	cout << endl << "SOLD: " << endl;
	mTreeSold.inOrderTraversal();
}

/**Getter**/
void DataAnalysis::displayTrends() {
	cout << "Most  sold:\t\t";
	mTreeSold.findLargest().printData();
	cout << endl;

	cout << "Most  purchased:\t";
	mTreePurchased.findLargest().printData();
	cout << endl << endl;

	cout << "Least sold:\t\t";
	mTreeSold.findSmallest().printData();
	cout << endl;

	cout << "Least purchased:\t";
	mTreePurchased.findSmallest().printData();
	cout << endl;
}
