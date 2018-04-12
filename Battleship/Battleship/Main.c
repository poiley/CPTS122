#include "Header.h"

int main (void) {
	int menu = -1, turn, x, y;
	char data;
	Stats player1, player2;
	player1.game_results = player2.game_results = 'l';
	player1.hits = player1.misses = player1.shots = player1.accuracy_ratio
		= player2.hits = player2.misses = player2.shots = player2.accuracy_ratio = 0;

	//These boards keep track of where you've placed your ships
	Point player1Board[10][10] = { { NULL } };
	Point player2Board[10][10] = { { NULL } };

	//These boards keep track of where you've guessed ships are
	Point player1OpponentTrack[10][10] = { { NULL } }; 
	Point player2OpponentTrack[10][10] = { { NULL } };

	srand((unsigned int)time(NULL));

	//Display rules and Welcome screen
	welcome_screen();

	/*INITIALIZE PLAYING BOARDS*/
	initialize_game_board(&player1Board);
	initialize_game_board(&player2Board);

	/*INITIALIZE BOARDS THAT KEEP TRACK OF GUESSES*/
	initialize_opponent_board(&player1OpponentTrack);
	initialize_opponent_board(&player2OpponentTrack);

	/*PLACE SHIPS*/
	printf("Player 1, please select from the following menu:\n"
		"\t1. Enter positions of ships manually\n"
		"\t2. Allow the program to randomly select positions of ships\n");
	scanf(" %d", &menu);
	
	if (menu == 1) {
		manually_place_ships_on_board(&player1Board);
	} else {
		randomly_place_ships_on_board(&player1Board);
	}
	
	printf("\nPlayer 2, please select from the following menu:\n"
		"\t1. Enter positions of ships manually\n"
		"\t2. Allow the program to randomly select positions of ships\n");
	scanf(" %d", &menu);

	if (menu == 1) {
		manually_place_ships_on_board(&player2Board);
	} else {
		randomly_place_ships_on_board(&player2Board);
	}

	/*SHIPS NOW PLACED*/
	turn = select_who_starts_first();
	printf("Player %d goes first.\n", turn);

	do { // Main gameplay loop
		if (turn == 1) { // Player 1
			display_board(player1Board, player1OpponentTrack);
			
			printf("Target? ");
			scanf(" %d %d", &y, &x);

			data = check_shot(x, y, &player2Board, &player1OpponentTrack, &player1); //THIS MIGHT NOT WORK 

			output_current_move(1, x, y, data);

			turn++;
		} else { // Player 2
			display_board(player2Board, player2OpponentTrack);

			printf("Target? ");
			scanf(" %d %d", &y, &x);

			data = check_shot(x, y, &player1Board, &player2OpponentTrack, &player2); //THIS MIGHT NOT WORK 

			output_current_move(2, x, y, data);

			turn--;
		}

		printf("Press enter to continue.\n");
		getchar(); 
		getchar();
		system("cls");
	} while (is_winner(player1) == 0 && is_winner(player2) == 0); // While there is no winner

	output_stats(player1, player2); // output winner data to log
}