/*****************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS**/
#include "Resources.h"

class Node {
	public:
		/**CONSTRUCTORS/DESTRUCTOR**/
		Node();
		Node(Data newData);
		Node(const Node &copy);
		~Node() { delete this->pNext; };

		/**GETTERS**/
		int getAbsences() const;
		int getRecordNumber() const;
		int getID() const;
		int getUnits() const;
		string getName() const;
		string getEmail() const;
		string getMajor() const;
		string getLevel() const;
		string getRecentAbsence();
		data getData() const;
		Node *getNext() const;
		Stack getAbsencesList() const;

		/**SETTERS**/
		void setAbsences(int newData);
		void setRecordNumber(int newData);
		void setID(int newData);
		void setUnits(int newData);
		void setName(string newData);
		void setEmail(string newData);
		void setMajor(string newData);
		void setLevel(string newData);
		void setNext(Node * const newData);
		void setAbsencesStack(Stack newData);
		void setAbsencesDate();

	private:
		/**PRIVATE DATA**/
		Data studentData;
		Node *pNext = (Node *)malloc(sizeof(Node));
};