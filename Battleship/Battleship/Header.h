#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Point {
	int x, y;
	char val;
} Point;

/* Stats struct stores information on player. Includes:
	- total number of hits
	- total number of misses
	- total number of shots 
	- hits to misses ratio (as a percentage)
	- won or lost the game. */
typedef struct stats {
	int hits, misses, shots;
	double accuracy_ratio;
	char game_results; // 'w' or 'l'
} Stats;

void welcome_screen();

void initialize_game_board(Point board[10][10]);

void initialize_opponent_board(Point board[10][10]);

int select_who_starts_first();

int manually_place_ships_on_board(Point board[10][10]);

void randomly_place_ships_on_board(Point board[10][10]);

char check_shot(int x, int y, Point board[10][10], Point opponentTrack[10][10], Stats *player);

int is_winner(Stats player);

void update_board(int x, int y, Point board[10][10], int shot);

void display_board(Point board[][10], Point opponentTrack[][10]);

void output_current_move(int player, int x, int y, char status);

int check_if_sunk_ship(Point board[10][10], char ship);

void output_stats(Stats player1, Stats player2);

char *buildStat(Stats player);

int check_collision(Point board[10][10]);