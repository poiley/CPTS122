/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 2
* Date : Jan 24th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include "Header.h"


int displayMenu() {
	int menu = -1;
	printf("\n(1)\tload\n(2)\tstore\n(3)\tdisplay\n(4)\tinsert\n(5)\tdelete\n(6)\tedit\n(7)\tsort\n(8)\trate\n(9)\tplay\n(10)\tshuffle\n(11)\texit");
	
	while (!(menu >= 1 && menu <= 11)) {
		printf("\n->\t");
		scanf("%d", &menu);
	}

	printf("Success!");

	if (menu == 11)
		return 11;
}

