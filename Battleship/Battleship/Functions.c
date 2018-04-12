#include "Header.h"

void welcome_screen() {
	printf("Welcome to Andrew Galland's Battleship PA!"
		"Rules of the Game:\n\t"
		"1. This is a two player game.\n\t"
		"2. Player1 is you and Player2 is the computer.\n\t"
		"3. For more information on how Battleship works, refer to the rules online.\n\n"
		"Press Enter to start\n");
	getchar();
	system("cls");
}

void initialize_game_board(Point board[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j].x = i;
			board[i][j].y = j;
			board[i][j].val = '~';
		}
	}
}

void initialize_opponent_board(Point board[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j].x = i;
			board[i][j].y = j;
			board[i][j].val = '-';
		}
	}
}

int select_who_starts_first() {
	return rand() % 2 + 1;
}

int manually_place_ships_on_board(Point board[10][10]) {
	int x1, y1, x2, y2;
	
	printf("Please enter the starting coordinate for the Carrier (ie: 0 0 to start in the top left).");
	scanf(" %d %d", &x1, &y1);
	printf("Please enter the ending coordinate for the Carrier.");
	scanf(" %d %d", &x2, &y2);

	if (x1 == x2 && x1 < 10 && x2 < 10) { // ship is horizontal
		for (int i = 0; i < 5; i++) {
			board[x1][y1 + i].val = 'c';
		}
	} else if (y1 == y2 && y1 < 10 && y2 < 10) { // ship is vertical
		for (int i = 0; i < 5; i++) {
			board[x1 + i][y1].val = 'c';
		}
	} else {
		return 0;
	}

	printf("Please enter the starting coordinate for the Battleship.");
	scanf(" %d %d", &x1, &y1);
	printf("Please enter the ending coordinate for the Battleship.");
	scanf(" %d %d", &x2, &y2);

	if (x1 == x2 && x1 < 10 && x2 < 10) { // ship is horizontal
		for (int i = 0; i < 4; i++) {
			board[x1][y1 + i].val = 'b';
		}
	} else if (y1 == y2 && y1 < 10 && y2 < 10) { // ship is vertical
		for (int i = 0; i < 4; i++) {
			board[x1 + i][y1].val = 'b';
		}
	} else {
		return 0;
	}

	printf("Please enter the starting coordinate for the Cruiser.");
	scanf(" %d %d", &x1, &y1);
	printf("Please enter the ending coordinate for the Cruiser.");
	scanf(" %d %d", &x2, &y2);

	if (x1 == x2 && x1 < 10 && x2 < 10) { // ship is horizontal
		for (int i = 0; i < 3; i++) {
			board[x1][y1 + i].val = 'r';
		}
	} else if (y1 == y2 && y1 < 10 && y2 < 10) { // ship is vertical
		for (int i = 0; i < 3; i++) {
			board[x1 + i][y1].val = 'r';
		}
	} else {
		return 0;
	}

	printf("Please enter the starting coordinate for the Submarine.");
	scanf(" %d %d", &x1, &y1);
	printf("Please enter the ending coordinate for the Submarine.");
	scanf(" %d %d", &x2, &y2);

	if (x1 == x2 && x1 < 10 && x2 < 10) { // ship is horizontal
		for (int i = 0; i < 3; i++) {
			board[x1][y1 + i].val = 's';
		}
	} else if (y1 == y2 && y1 < 10 && y2 < 10) { // ship is vertical
		for (int i = 0; i < 3; i++) {
			board[x1 + i][y1].val = 's';
		}
	} else {
		return 0;
	}

	printf("Please enter the starting coordinate for the Destroyer.");
	scanf(" %d %d", &x1, &y1);
	printf("Please enter the ending coordinate for the Destroyer.");
	scanf(" %d %d", &x2, &y2);

	if (x1 == x2 && x1 < 10 && x2 < 10) { // ship is horizontal
		for (int i = 0; i < 2; i++) {
			board[x1][y1 + i].val = 'd';
		}
	} else if (y1 == y2 && y1 < 10 && y2 < 10) { // ship is vertical
		for (int i = 0; i < 2; i++) {
			board[x1 + i][y1].val = 'd';
		}
	} else {
		return 0;
	}


	if (check_collision(board) == 1)
		return 0;

	return 1;
}

void randomly_place_ships_on_board(Point board[10][10]) {
	Point backup[10][10] = { {NULL} };
	initialize_game_board(&backup);
	
	int x1, y1;

	do {
		x1 = rand() % 10;
		y1 = rand() % 5;

		for (int i = 0; i < 5; i++) {
			board[x1][y1 + i].val = 'c';
		}

		x1 = rand() % 10;
		y1 = rand() % 5;

		for (int i = 0; i < 4; i++) {
			board[x1][9 - y1 - i].val = 'b';
		}

		x1 = rand() % 10;
		y1 = rand() % 5;

		for (int i = 0; i < 3; i++) {
			board[x1][y1 + i].val = 'r';
		}

		x1 = rand() % 10;
		y1 = rand() % 5;

		for (int i = 0; i < 3; i++) {
			board[x1][9 - y1 - i].val = 's';
		}

		x1 = rand() % 8;
		y1 = rand() % 8;

		for (int i = 0; i < 2; i++) {
			board[x1 + i][y1].val = 'd';
		}
		
		if (check_collision(board) == 0) {
			break;
		} else {
			initialize_game_board(board);
		}
	} while (check_collision(board) == 1);
}

char check_shot(int x, int y, Point board[10][10], Point opponentTrack[10][10], Stats *player) {
	(*player).shots++;
	if (board[x][y].val != '~') {
		printf("It's a hit!\n");
		
		(*player).hits++;
		char hit = board[x][y].val;
		board[x][y].val = 'x';
		opponentTrack[x][y].val = '*';

		update_board(x, y, &opponentTrack, 1);
		
		if (check_if_sunk_ship(board, hit) == 1) {
			printf("Ship sunk!\n");
			return 's';
		}
		return 'h';
	} else {
		printf("It's a miss!\n");
		(*player).misses++;
		opponentTrack[x][y].val = 'm';
		
		update_board(x, y, &opponentTrack, 0);
		
		return 'm';
	}
}

int is_winner(Stats player) {
	if (player.hits == 17) {
		player.game_results = 'w';
		return 1;
	} else {
		return 0;
	}
}

void update_board(int x, int y, Point board[10][10], int shot) { //shot = 1 = hit; shot = 0 = miss;
	if (shot == 1) {
		board[x][y].val = 'f';
	} else {
		board[x][y].val = 'f';
	}
}

void display_board(Point board[][10], Point opponentTrack[][10]) {
	printf("Personal Board:\n");

	printf("+ 0 1 2 3 4 5 6 7 8 9 x\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", i);

		for (int j = 0; j < 10; j++) {
			printf("%c ", board[i][j].val);
		}
		printf("\n");
	}
	printf("y\n\n");

	printf("Guesses:\n");
	printf("+ 0 1 2 3 4 5 6 7 8 9 x\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", i);

		for (int j = 0; j < 10; j++) {
			printf("%c ", opponentTrack[i][j].val);
		}
		printf("\n");
	}
	printf("y\n\n");

}

void output_current_move(int player, int x, int y, char status) {
	char line[10] = { 'P' };
	FILE *infile = fopen("Battleship.log", "a+");

	line[1] = player + 48;
	line[2] = ' ';
	line[3] = x + 48;
	line[4] = ',';
	line[5] = y + 48;
	line[6] = ' ';
	line[7] = status;
	line[8] = '\n';
	line[9] = '\0';

	fprintf(infile, line);	
	fclose(infile);
}

int check_if_sunk_ship(Point board[10][10], char ship) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j].val == ship) {
				return 0;
			}
		}
	}
	return 1;
}

void output_stats(Stats player1, Stats player2) {
	FILE *infile = fopen("PlayerStats.log", "w+");
	player1.accuracy_ratio = player1.hits / player1.misses * 100;
	player2.accuracy_ratio = player2.hits / player2.misses * 100;

	fprintf(infile, buildStat(player1));
	fprintf(infile, buildStat(player2));
	fclose(infile);
}

char *buildStat(Stats player) {
	char *toReturn;
	sprintf(&toReturn, "Status: %c, Hits: %d, Misses: %d, Ratio: %lf, Shots: %d\n", player.game_results, player.hits, player.misses, player.accuracy_ratio, player.shots);
	return toReturn;
}

int check_collision(Point board[10][10]) {
	int water_count = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j].val == '~')
				water_count++;
		}
	}

	if (water_count == 83) {
		return 0; // No collision
	} else {
		return 1;
	}
}