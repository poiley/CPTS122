/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 2
* Date : Jan 24th, 2018
* Credits : Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include "Header.h"


int displayMenu() {
	Node *pList = (Node *) malloc(sizeof(Node));
	pList = NULL;
	int menu = -1, submenu = -1;
	char query[100] = "";
	printf("\n(1)\tload\n(2)\tstore\n(3)\tdisplay\n(4)\tinsert\n(5)\tdelete\n(6)\tedit\n(7)\tsort\n(8)\trate\n(9)\tplay\n(10)\tshuffle\n(11)\texit");
	
	while (!(menu >= 1 && menu <= 11)) {
		printf("\n->\t");
		scanf("%d", &menu);
	}

	printf("Success!\n");

	switch (menu) {
		case 1:
			//load
			load(&pList);
			break;
		case 2:
			//store
			load(&pList);
			store(pList);
			break;
		case 3:
			//display
			load(&pList);

			printf("\n(1)\tLoad all\n(2)\tLoad by Artist\n");			
			while (!(submenu == 1 || submenu == 2)) {
				printf("\n->\t");
				scanf("%d", &submenu);
			}

			switch (submenu) {
				case 1:
					printList(pList);
					break;
				case 2:
					printf("Artist?\n->\t");
					scanf("%s", &query);
					printListQuery(pList, query);
			}
			break;

		case 4:
			//insert
			break;
		case 5:
			//delete
			break;
		case 6:
			//edit
			break;
		case 7:
			//sort
			break;
		case 8:
			//rate
			load(&pList);
			printf("\nSong?\n->\t");
			scanf("%s", &query);
			rate(&pList, query);
			break;
		case 9: 
			//play
			load(&pList);
			play(pList);
			break;
		case 10:
			//shuffle
			break;
		case 11:
			//exit
			return 11;
	}
}

void load(Node **pList) {
	FILE *infile = fopen("musicPlayList.csv", "r");
	Record r = { "", "", "", "",{ -1, -1 }, -1, -1 };
	char line[256] = "";

	if (infile != NULL) {
		while (fgets(line, 256, infile) != NULL) {

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

			r.album				= strtok(NULL, ",");			//Album
			r.song				= strtok(NULL, ",");			//Song
			r.genre				= strtok(NULL, ",");			//Genre

			char *duration		= strtok(NULL, ",");			//Duration

			r.plays				= atoi(strtok(NULL, ","));		//Plays
			r.rating			= atoi(strtok(NULL, ","));		//Rating

			r.length.minutes	= atoi(strtok(duration, ":"));	//Minutes
			r.length.seconds	= atoi(strtok(NULL, ":"));		//Seconds
			
			//Start building the LinkedList
			insertFront(&*pList, r);
		}
	}

	fclose(infile);
}

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

Node * makeNode(Record newData) {
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL) {
		pMem->pPrev = NULL; //doubly link lists keep track of previous nodes too! 
		pMem->pNext = NULL;

		//STRINGS REQUIRE MALLOC
		pMem->data.song		= malloc(strlen(newData.song)	* sizeof(char *) + 1);
		strcpy(pMem->data.song, newData.song);

		pMem->data.artist	= malloc(strlen(newData.artist)	* sizeof(char *) + 1);
		strcpy(pMem->data.artist, newData.artist);

		pMem->data.album	= malloc(strlen(newData.album)	* sizeof(char *) + 1);
		strcpy(pMem->data.album, newData.album);

		pMem->data.genre	= malloc(strlen(newData.genre)	* sizeof(char *) + 1);
		strcpy(pMem->data.genre, newData.genre);

		//NON-STRINGS TAKE LESS COMPLEX DATA ASSIGNMENTS 
		pMem->data.length	= newData.length;
		pMem->data.plays	= newData.plays;
		pMem->data.rating	= newData.rating;
	}

	return pMem;
}

Boolean insertFront(Node **pList, Record newData) {
	Node *pMem = makeNode(newData);

	if (pMem == NULL) //if not memory not properly allocated
		return FALSE;

	if (*pList != NULL) { //if the list is not empty
		pMem->pNext = *pList; 
		(*pList)->pPrev = pMem;
	}

	*pList = pMem;

	return TRUE;
}

Record *deleteRecord(Node **pList, Record search) {
	Node *pCurrent = *pList;

	if (strcmp(pCurrent->data.song, search.song) == 0) {
		pCurrent->pNext = pCurrent->pNext->pNext;
		free(pCurrent->pNext);
		return TRUE;
	}

	while ((pCurrent->pNext != NULL) && (strcmp(pCurrent->pNext->data.song, search.song) != 0))
		pCurrent = pCurrent->pNext;

	if (pCurrent->pNext != NULL) {
		pCurrent->pNext = pCurrent->pNext->pNext;
		free(pCurrent->pNext);
		return TRUE;
	}

	return FALSE;
}

Boolean rate(Node **pList, char *query) {
	while (*pList != NULL) {
		if (strcmp((*pList)->data.song, query) == 0) {
			(*pList)->data.rating = rate_query();
			printf("New rating for song '%s': %d\n", (*pList)->data.song, (*pList)->data.rating);

			return TRUE;
		}

		(*pList) = (*pList)->pNext;
	}
	return FALSE;
}

// I wrote this because I'm lazy and I'm calling it twice in `rate()` so it seemed efficient
int rate_query() { 
	int newRating = -1;
	
	printf("Rating?\n->\t");
	scanf("%d", &newRating);
	
	return newRating;
}

//Code credit: Andrew O'Fallon
void printList(Node *pList) {
	if (pList != NULL) {
		printf("Song:\t%s\t\t\tby %s\n", pList->data.song, pList->data.artist);
		printList(pList->pNext);
	}
}

void printListQuery(Node *pList, char *query) {
	printf("Music by %s:\n", query);
	
	int i = 1;
	while (pList->pNext != NULL) {
		if (strcmp(pList->data.artist, query) == 0) {
			printf("(%d)\t\"%s\"\n", i, pList->data.song);
			i++;
		}
		pList = pList->pNext;
	}

	if (i == 1)
		printf("No music found by %s\n", query);
}


void play(Node *pList) {
	char song[15] = "";
	printf("Song?\n->\t");
	scanf("%s", &song);
	
	while ( pList != NULL && strcmp(pList->data.song, song) != 0 )
		pList = pList->pNext;
	

	if (pList == NULL) //if the song is not in the library, exit
		return;

	while (pList != NULL) {
		printf("\n\n ________________________________\n");
		printf("| \\___===____________________()_\\\n");
		printf("| |                              |\n");
		printf("| |   _________________________  |\n");
		printf("| |  |                        |  |\n");
		printf("| |  |                        |  |\n");
		printf("| |  |  _______               |  |\n");
		printf("| |  | | ___   |  %.10s       |  |\n",pList->data.song);
		printf("| |  | | \\o \\o |  %.10s       |  |\n",pList->data.artist);
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

		system("sleep 2");
		system("cls");

		pList = pList->pPrev;
	}
}