#include "Menu.h"

int main(void) {
	Menu menu = Menu();

	List *pList = (List *) malloc(sizeof(List));
	pList->setHead(NULL);
	
	cin >> menu;
	while (menu.execute(&pList)) {
		cin >> menu;
	}
}