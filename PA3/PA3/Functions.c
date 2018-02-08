/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 3
* Date : Feb 4th, 2018
* Credits : Andrew O'Fallon for instructions, guidance, printList() 
*			and struct code.
**********************************************************************/

#include "Header.h"

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: Goes through the motions of prompting the user for a menu 
 * selection and running the functions based on the user's choice. At the 
 * end of the function, changes due to user's choices are written to the 
 * Linked List that's passed as in as a parameter through pointers.
 */
int displayMenu(Node **pList) {
	Node *pMem = *pList;			// Create a temporary linked list that duplicates the data in the linked list that already exists.
	int menu = -1, submenu = -1;	// Initiallize data.
	char query[100] = "";
	printf(	"\n(1)\tload\n(2)\tstore\n(3)\tdisplay\n(4)"			// Display Main Menu prompt.
			"\tinsert\n(5)\tdelete\n(6)\tedit\n(7)\tsort"
			"\n(8)\trate\n(9)\tplay\n(10)\tshuffle\n(11)\texit"); 
	
	// Check if the user has input a valid selection and loop if they haven't.
	while (!(menu >= 1 && menu <= 11)) {
		printf("\n->\t");
		scanf("%d", &menu);
	}

	printf("Success!\n"); // If the user has input a valid selection, return a success message.

	switch (menu) {
		case 1:		// Load.
			load(&pMem);
			break;
		case 2:		// Store.
			store(pMem);
			break;
		case 3:		// Display.
			printf("\n(1)\tLoad all\n(2)\tLoad by Artist\n");			
			while (!(submenu == 1 || submenu == 2)) {
				printf("\n->\t");
				scanf("%d", &submenu);
			}

			switch (submenu) {
				case 1:
					printList(pMem);
					break;
				case 2:
					printf("Artist?\n->\t");
					scanf(" %[^\n]s", &query);
					printListQuery(pMem, query);
			}
			break;

		case 4:		// Insert.
			insert(&pMem);
			break;
		case 5:		// Delete. 
			delete(&pMem);
			break;
		case 6:		// Edit.
			break;
		case 7:		// Sort.
			sort(&pMem);
			break;
		case 8:		// Rate.
			printf("\nSong?\n->\t");
			scanf(" %[^\n]s", &query);
			rate(&pMem, query);
			break;
		case 9:		// Play.
			play(pMem);
			break;
		case 10:	// Shuffle.
			shuffle(pMem);
			break;
		case 11:	// Exit.
			return 11;
	}

	*pList = pMem; // After running whatever command the user selected, write changes.
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: Read from the file `musicPlayList.csv` and parse the data into
 * a LinkedList.
 */
void load(Node **pList) {
	*pList = NULL;										// Initialize data and objects.
	FILE *infile = fopen("musicPlayList.csv", "r");
	Record r = { "", "", "", "",{ -1, -1 }, -1, -1 };
	char line[256] = "";

	if (infile != NULL) { // If the file exists and isn't empty.
		while (fgets(line, 256, infile) != NULL) { // Read through `csv`, line-by-line.

			r.artist = strtok(line, ",");						//Artist
			
			//In the `.csv` file there's some Artist entries that are formatted
			//as "Last, First", which not only throws off `strtok` but also looks
			//strange when printing and saving the data. This if statement formats
			//`"Last, First"` to `First Last`.
			if (strstr(r.artist, "\"")) {
				char *first = strtok(NULL, ","), arr[20] = " ";

				first[strlen(first) - 1] = 0;

				strcat(++first, " ");

				strcpy(arr, first);
				strcat(arr, ++r.artist);

				r.artist = arr;
			}

			r.album = strtok(NULL, ",");			//Album
			r.song = strtok(NULL, ",");			//Song
			r.genre = strtok(NULL, ",");			//Genre

			char *duration = strtok(NULL, ",");			//Duration

			r.plays = atoi(strtok(NULL, ","));		//Plays
			r.rating = atoi(strtok(NULL, ","));		//Rating

			r.length.minutes = atoi(strtok(duration, ":"));	//Minutes
			r.length.seconds = atoi(strtok(NULL, ":"));		//Seconds

			//Start building the LinkedList
			insertFront(&*pList, r);
		}
	}
	fclose(infile);
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: As specifified by TA, this function, when called, will write to
 * the same file as we read from. It writes all data from the LinkedList to the
 * file `musicPlayList.csv`.
 */
void store(Node *pList) {
	FILE *infile = fopen("musicPlayList.csv", "w+");
	while (pList != NULL) {
		char *artist = pList->data.artist;
		if (strstr(artist, " ")) {
			char artistUnformatted[20] = "", artistFormatted[20] = "\"";

			strcpy(artistUnformatted, pList->data.artist);
			char *first = strtok(artistUnformatted, " ");
			char *last = strtok(NULL, " ");

			//build string to be formatted "Last, First"
			strcat(artistFormatted, last);
			strcat(artistFormatted, ", ");
			strcat(artistFormatted, first);
			strcat(artistFormatted, "\"\0");

			//Write formatted changes
			strcpy(artist, artistFormatted);
		}
		fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", artist, pList->data.album, pList->data.song, pList->data.genre, pList->data.length.minutes, pList->data.length.seconds, pList->data.plays, pList->data.rating);
		pList = pList->pNext;
	}

	fclose(infile);
	printf("Data written to file!\n");
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: For building Linked Lists. Creates a new node, allocates the
 * memory needed and then assigns the data to the object before returinging.
 */
Node * makeNode(Record newData) {
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL) {
		pMem->pPrev = NULL; //doubly link lists keep track of previous nodes too! 
		pMem->pNext = NULL;

		//STRINGS REQUIRE MALLOC
		pMem->data.song = malloc(strlen(newData.song) * sizeof(char *) + 1);
		strcpy(pMem->data.song, newData.song);

		pMem->data.artist = malloc(strlen(newData.artist) * sizeof(char *) + 1);
		strcpy(pMem->data.artist, newData.artist);

		pMem->data.album = malloc(strlen(newData.album) * sizeof(char *) + 1);
		strcpy(pMem->data.album, newData.album);

		pMem->data.genre = malloc(strlen(newData.genre) * sizeof(char *) + 1);
		strcpy(pMem->data.genre, newData.genre);

		//NON-STRINGS TAKE LESS COMPLEX DATA ASSIGNMENTS 
		pMem->data.length = newData.length;
		pMem->data.plays = newData.plays;
		pMem->data.rating = newData.rating;
	}

	return pMem;
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 3
 * DESCRIPTION: Asks for a song to remove from the Linked List, deletes
 * Node from linked list if it matches song name.
 */
void delete(Node **pList) {
	Node *pMem = *pList;
	char query[50] = "";
	printf("\nWhich song would you like to remove?\n->\t");
	scanf(" %[^\n]s", &query);
	printf("%s", query);

	while (pMem != NULL) {
		if (strcmp(pMem->data.song, query) == 0) {
			printf("\nENTRY:\t%s\n", pMem->data.song);

			pMem->pPrev->pNext = pMem->pNext;
			pMem->pNext->pPrev = pMem->pPrev;

			free(pMem);
			break;
		}
		pMem = pMem->pNext;
	}
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: Adds a new Node with new data from a new record in the object 
 * `newData` to the front of the LinkedList `pList`. Returns TRUE if successful.
 */
Boolean insertFront(Node **pList, Record newData) {
	Node *pMem = makeNode(newData);

	if (pMem == NULL || pMem->data.artist == NULL) //if not memory not properly allocated
		return FALSE;

	if (*pList != NULL) { //if the list is not empty
		pMem->pNext = *pList; 
		(*pList)->pPrev = pMem;
	}

	*pList = pMem;

	return TRUE;
}


/*
 * AUTHOR: Benjamin Poile
 * PA: 3
 * DESCRIPTION: Takes data from the user, fills it into a record object and 
 * adds it to the front of the list.
 */
void insert(Node **pList) {
	char strInput[50] = "";
	Record r = { "", "", "", "",{ -1, -1 }, -1, -1 };

	printf("\nInsert Record:\nSong?\n->\t");
	scanf(" %[^\n]s ", &strInput);
	r.song = (char *)malloc(sizeof(char)*strlen(strInput));
	strcpy(r.song, strInput);

	printf("\nArtist?\n->\t");
	scanf(" %[^\n]s ", &strInput);
	r.artist = (char *)malloc(sizeof(char)*strlen(strInput));
	strcpy(r.artist, strInput);

	printf("\nAlbum?\n->\t");
	scanf(" %[^\n]s ", &strInput);
	r.album = (char *)malloc(sizeof(char)*strlen(strInput));
	strcpy(r.album, strInput);
	
	printf("\nGenre?\n->\t");
	scanf(" %[^\n]s ", &strInput);
	r.genre = (char *)malloc(sizeof(char)*strlen(strInput));
	strcpy(r.genre, strInput);
	
	printf("\nMinutes:Seconds?\n->\t");
	scanf(" %d:%d", &r.length.minutes, &r.length.seconds);
	
	printf("\nPlays?\n->\t");
	scanf(" %d", &r.plays);
	
	printf("\nRating out of 5?\n->\t");
	scanf(" %d", &r.rating);
	
	printf("\n%s,%s,%s,%s,%d:%d,%d,%d\n", r.artist, r.album, r.song, r.genre, r.length.minutes, r.length.seconds, r.plays, r.rating);

	insertFront(&*pList, r);
	printf("\nSong \"%s\" added.\n", (*pList)->data.song);
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: After taking in a search term, the list is searched for a song 
 * matching the title and then offers to re-rate the song.
 */
Boolean rate(Node **pList, char *query) {
	Node *pMem = *pList;

	while (pMem != NULL) {
		if (strcmp(pMem->data.song, query) == 0) {
			pMem->data.rating = rate_query();
			printf("New rating for song '%s': %d\n", pMem->data.song, pMem->data.rating);

			break;
		}

		pMem = pMem->pNext;
	}

	return FALSE;
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: Considering this prompt is done a few times throughout the program, 
 * I figured I'd just write it it's own method for simplicity and efficiency. All 
 * it does is prompt the user for a rating.
 */
int rate_query() { 
	int newRating = -1;
	
	printf("Rating?\n->\t");
	scanf("%d", &newRating);
	
	return newRating;
}

/*
 * AUTHOR: Andrew O'Fallon
 * PA: 2
 * DESCRIPTION: Recursively print the song and artist in the LinkedList.
 */
void printList(Node *pList) {
	if (pList != NULL) {
		printf("Song:\t%s\t\t\tby %s. Album:\t\t\t%s\n", pList->data.song, pList->data.artist, pList->data.album);
		printList(pList->pNext);
	}
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: List all the music by an artist, who's name is stored in the object `query`.
 */
void printListQuery(Node *pList, char *query) {
	printf("Music by %s:\n", query);
	
	int i = 1;
	while (pList != NULL) {
		if (strcmp(pList->data.artist, query) == 0) {
			printf("(%d)\t\"%s\"\n", i, pList->data.song);
			i++;
		}
		pList = pList->pNext;
	}

	if (i == 1)
		printf("No music found by %s\n", query);
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 2
 * DESCRIPTION: Prompt the user for a song to play from, skip to that song in the 
 * LinkedList and 'play' every song from there on after. 'Playing' is essentially 
 * printing it out in the ASCII MP3 player for a few seconds and clearing the 
 * screen before skipping to the next song.
 */
void play(Node *pList) {
	char song[15] = "";
	printf("Song?\n->\t");
	scanf(" %[^\n]s", &song);
	
	while ( pList != NULL && strcmp(pList->data.song, song) != 0 )
		pList = pList->pNext;
	

	if (pList == NULL) //if the song is not in the library, exit
		return;

	while (pList != NULL) {
		printIPod(pList->data.song, pList->data.artist);

		system("sleep 5");
		system("cls");

		pList = pList->pPrev;
	}
}


/*
 * AUTHOR: Benjamin Poile
 * PA: 3
 * DESCRIPTION: Based on the user's input, the list is either sorted
 * alphabetically by album title, artist name, or numerically by rating
 * or number of plays.
 */
void sort(Node **pList) {
	int item = -1, sortType = -1;

	printf("\nHow would you like to sort?\n");
	printf("\t1.)  Sort based on artist (A-Z)\n\t2.)  Sort based on album title(A - Z)\n\t3.)  Sort based on rating(1 - 5)\n\t4.)  Sort based on times played(largest - smallest)\n->\t");
	scanf("%d", &sortType);
	
	item = sortType - 1;
	Boolean done = FALSE;

	while (done == FALSE) {
		Node *pCur = *pList;
		Node **pCurPtr	= pList;       
		Node *pNextTemp = pCur->pNext; 
		done = TRUE;
		
		char *pNextTempStr;
		char *pCurStr;
		int pNextTempInt;
		int pCurInt;
		
		while (pNextTemp != NULL) {
			switch (item) {
				case 0:
					pNextTempStr = (char *)malloc(sizeof(char *) * strlen(pNextTemp->data.artist));
					pNextTempStr = pNextTemp->data.artist;

					pCurStr = (char *)malloc(sizeof(char *) * strlen(pCur->data.artist));
					pCurStr = pCur->data.artist;
					break;
				case 1:
					pNextTempStr = (char *)malloc(sizeof(char *) * strlen(pNextTemp->data.album));
					pNextTempStr = pNextTemp->data.album;

					pCurStr = (char *)malloc(sizeof(char *) * strlen(pCur->data.album));
					pCurStr = pCur->data.album;
					break;
				case 2:
					pNextTempInt = pNextTemp->data.rating;
					pCurInt = pCur->data.rating;
					break;
				case 3:
					pNextTempInt = pNextTemp->data.plays;
					pCurInt = pCur->data.plays;
					break;
			}
			
			if ( (item <= 1) && ( strcmp(pNextTempStr, pCurStr) == -1 ) ) {
				pCur->pNext		 = pNextTemp->pNext;
				pNextTemp->pNext = pCur;
				*pCurPtr		 = pNextTemp;

				done = FALSE;
			} else if ( ( item >= 2 ) && ( pNextTempInt > pCurInt ) ) {
				pCur->pNext = pNextTemp->pNext;
				pNextTemp->pNext = pCur;
				*pCurPtr = pNextTemp;

				done = FALSE;
			}

			pCurPtr		= &pCur->pNext;
			pCur		= pNextTemp;
			pNextTemp	= pNextTemp->pNext;
		}
	}
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 3
 * DESCRIPTION: Take the regular order of songs, shuffle them, and 'play' them.
 */
void shuffle(Node *pList) {
	srand(time(NULL));
	Node *pHead = pList, *pMem = pList;
	int length = 0, currentIndex = 0, *indexToPlay = NULL;
	
	for (length = 0; pHead != NULL; length++)
		pHead = pHead->pNext;
	
	indexToPlay = malloc(sizeof(int) * length);
	
	for (int i = 0; i < length; i++)
		indexToPlay[i] = i;
	
	for (int i = 0; i < length; i++) {
		int temp = indexToPlay[i], j = rand() % (i + 1);
		indexToPlay[i] = indexToPlay[j];
		indexToPlay[j] = temp;
	}

	for (int i = 0; i < length; i++) {
		while(currentIndex != indexToPlay[i] ) {
			if (currentIndex < indexToPlay[i]) {
				currentIndex++;
				pMem = pMem->pNext;
			} else {
				currentIndex--;
				pMem = pMem->pPrev;
			}
		}

		printIPod(pMem->data.song, pMem->data.artist);

		system("sleep 5");
		system("cls");
	}
}

/*
 * AUTHOR: Benjamin Poile
 * PA: 3
 * DESCRIPTION: A misc. function that just prints the iPod as ASCII. Called in `play` and `shuffle`.
 */
void printIPod(char *song, char *artist) {
	printf("\n\n ________________________________\n");
	printf("| \\___===____________________()_\\\n");
	printf("| |                              |\n");
	printf("| |   _________________________  |\n");
	printf("| |  |                        |  |\n");
	printf("| |  |                        |  |\n");
	printf("| |  |  _______               |  |\n");
	printf("| |  | | ___   |  %.10s           \n", song);
	printf("| |  | | \\o \\o |  %.10s         \n", artist);
	printf("| |  | |_______|              |  |\n");
	printf("| |  |                        |  |\n");
	printf("| |  |                        |  |\n");
	printf("| |  |                        |  |\n");
	printf("| |  |                        |  |\n");
	printf("| |  |________________________|  |\n");
	printf("| |                              |\n");
	printf("| |                              |\n");
	printf("| |              @@@@            |\n");
	printf("| |           @@@Menu@@@         |\n");
	printf("| |          @@@@@@@@@@@@        |\n");
	printf("| |         @<<@@@()@@@>>@       |\n");
	printf("| |          @@@@@@@@@@@@        |\n");
	printf("| |           @@@ ||>@@@         |\n");
	printf("| |              @@@@            |\n");
	printf("| |                              |\n");
	printf("| |                              |\n");
	printf("| |                              |\n");
	printf("| |                              |\n");
	printf(" \\|______________________________|\n");
}