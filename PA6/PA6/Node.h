#include "Resources.h"

class Node {
	public:
		Node();
		Node(Data newData);
		Node(const Node &copy);
		~Node() {};

		// For Testing Purposes Only
		void printData();

		/**GETTERS**/
		int getAbsences() const;
		int getRecordNumber() const;
		int getID() const;
		int getUnits() const;
		string getName() const;
		string getEmail() const;
		string getMajor() const;
		string getLevel() const;
		data getData() const;
		Node *getNext() const;
		string getRecentAbsence();
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
		void setAbsencesDate();

	private:
		Data studentData;
		Node *pNext = (Node *)malloc(sizeof(Node));
};