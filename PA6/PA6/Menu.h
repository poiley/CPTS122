/*****************************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 6
 * Date : Mar 20th, 2018
 * Credits : Andrew O'Fallon for instructions, Stack Overflow for date entries
 ******************************************************************************/

/**IMPORTS**/
#include "Functions.h"

/**CLASSES**/
class Menu {
	public:
		/**CONSTRUCTOR/DESTRUCTOR**/
		Menu();
		~Menu() {};

		/**GETTER**/
		int get_menu();

		/**SETTER**/
		void set_menu(int newMenu);

		/**MISC.**/
		void display();
		bool execute(List **pList);

	private:
		/**PRIVATE DATA**/
		int menu_choice;
};

/**NON-MEMBER FUNCTIONS**/
istream& operator >> (istream &in, Menu &menu);