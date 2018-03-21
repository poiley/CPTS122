#include "Functions.h"

class Menu {
public:
	Menu();
	~Menu() {};

	void display();
	bool execute(List **pList);

	int  get_menu();
	void set_menu(int newMenu);
	
private:
	int menu_choice;
};

istream& operator >> (istream &in, Menu &menu);