/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 3
* Date : Feb 4th, 2018
* Credits : Andrew O'Fallon for instructions, guidance, printList()
*			and struct code.
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * NOTE: I used code I wrote in lab with my group as well as some 
 * code borrowed from Andy's examples. Similarities in my Linked 
 * List or struct code may be seen because of that.
 */
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

/*==========PA2==========*/

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Goes through the motions of prompting the user for a menu
 * selection and running the functions based on the user's choice. At the
 * end of the function, changes due to user's choices are written to the
 * Linked List that's passed as in as a parameter through pointers.
 */
int displayMenu(Node **pList);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: For building Linked Lists. Creates a new node, allocates the 
 * memory needed and then assigns the data to the object before returinging.
 */
Node * makeNode(Record newData);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Adds a new Node with new data from a new record in the object 
 * `newData` to the front of the LinkedList `pList`. Returns TRUE if successful.
 */
Boolean insertFront(Node **pList, Record newData);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: After taking in a search term, the list is searched for a song 
 * matching the title and then offers to re-rate the song.
 */
Boolean rate(Node **pList, char *query);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Considering this prompt is done a few times throughout the program, 
 * I figured I'd just write it it's own method for simplicity and efficiency. All 
 * it does is prompt the user for a rating.
 */
int rate_query();

/*
 * AUTHOR: Andrew O'Fallon
 * DESCRIPTION: Recursively print the song and artist in the LinkedList.
 */
void printList(Node *pList);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: List all the music by an artist, who's name is stored in the object `query`.
 */
void printListQuery(Node *pList, char *query);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Read from the file `musicPlayList.csv` and parse the data into
 * a LinkedList.
 */
void load(Node **pList);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: As specifified by TA, this function, when called, will write to 
 * the same file as we read from. It writes all data from the LinkedList to the
 * file `musicPlayList.csv`.
 */
void store(Node *pList);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Prompt the user for a song to play from, skip to that song in the 
 * LinkedList and 'play' every song from there on after. 'Playing' is essentially 
 * printing it out in the ASCII MP3 player for a few seconds and clearing the 
 * screen before skipping to the next song.
 */
void play(Node *pList);


/*==========PA3==========*/

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Takes data from the user, fills it into a record object and
 * adds it to the front of the list.
 */
void insert(Node **pList);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Asks for a song to remove from the Linked List, deletes
 * Node from linked list if it matches song name.
 */
void delete(Node **pList);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Based on the user's input, the list is either sorted 
 * alphabetically by album title, artist name, or numerically by rating
 * or number of plays.
 */
void sort(Node **pList);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: Take the regular order of songs, shuffle them, and 'play' them.
 */
void shuffle(Node *pList);

/*
 * AUTHOR: Benjamin Poile
 * DESCRIPTION: A misc. function that just prints the iPod as ASCII. Called in `play` and `shuffle`.
 */
void printIPod(char *song, char *artist);