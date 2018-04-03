/*********************************************************************
 * Programmer: Benjamin Poile
 * Class : CptS 122, Spring 2018
 * Programming Assignment : PA 7
 * Date : Mar 28th, 2018
 * Credits : Andrew O'Fallon for instructions. 
 *			Using code written in lab with Alexa, Jeff, and Brandon.
 **********************************************************************/

#pragma once

/**IMPORTS**/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

/**NAMESPACE USES**/
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::getline;
using std::sort;

using std::istringstream;
using std::ifstream;

/**GLOBAL DATA**/
typedef struct data {
	string morse;
	char letter;
} Data;