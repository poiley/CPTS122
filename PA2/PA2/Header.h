/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 2
* Date : Jan 24th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NOTE: I used code I wrote in lab with my group. Similarities in my Linked List code may be seen because of that.
typedef enum boolean {
	FALSE, TRUE
} Boolean;

typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct record {
	char *artist;
	char *album;
	char *song;
	char *genre;
	Duration length;
	int plays;
	int rating;
} Record;

typedef struct node {
	Record data;	
	struct node *pNext;
	struct node *pPrev;
} Node;

int displayMenu();
Node * makeNode(Record newData);
Boolean insertFront(Node **pList, Record newData);
Record *deleteRecord(Node **pList, Record search);
Boolean rate(Node **pList, char *query);
void printList(Node *pList);
void printListQuery(Node *pList, char *query);
void load(Node **pList);
void store(Node *pList);
void play(Node *pList);