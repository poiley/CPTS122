/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 8
 * Date : Apr 9th, 2018
 * Credits: Andrew O'Fallon for instructions. 
 **********************************************************************/

#include "Resources.h";
#include "Node.h"

class TransactionNode : public Node {
	public:
		/**Constructors & Destructors**/
		TransactionNode(string newProduct, int newUnits);
		~TransactionNode() { }

		/**Getters**/
		int getUnits();
		void printData();
		
		/**Setters**/
		void setUnits(int newUnits);
	private:
		/**Private data**/
		int mUnits;
};