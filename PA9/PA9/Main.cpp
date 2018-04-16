#include "Header.h"

int main(void) {
	srand(time(NULL));

	int SQUARE_X = 75, SQUARE_Y = 75, BORDER_SIZE = 3;

	Window	   *display = new Window(300 + BORDER_SIZE, 400, "2048");
	Scoreboard *score   = new Scoreboard(20, 325);
	sf::Color   bgColor = sf::Color(170, 122, 57);

	Square *squares[4][4];
	for (int y = 0, i = 0; i < 4; i++, y += 75)
		for (int x = 0, j = 0; j < 4; j++, x += 75)
			squares[i][j] = new Square(SQUARE_X, SQUARE_Y, x, y);

	while (display->isOpen()) {
		sf::Event event;
		while (display->pollEvent(event)) { // Controls / Event loop
			if (event.type == sf::Event::Closed)
				display->close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Left)
					moveLeft(squares);
				else if (event.key.code == sf::Keyboard::Up)
					moveUp(squares);
				else if (event.key.code == sf::Keyboard::Right)
					moveRight(squares);
				else if (event.key.code == sf::Keyboard::Down)
					moveDown(squares);
				insertRandom(squares);
			}
				
		}


		display->clear(bgColor); // Clear screen with Background color
	
		display->draw(*score); // Scoreboard
		display->draw(squares); // Squares

		display->display();

		if (boardFull(squares))
			break;
	}

	return 0;
}

void insertRandom(Square *squares[4][4]) {
	int randX = rand() % 4, randY = rand() % 4, newValue = (rand() % 4) + 1;
	if (squares[randX][randY]->isEmpty())
		if (newValue == 3 || newValue == 1)
			squares[randX][randY]->setValue(++newValue);
		else
			squares[randX][randY]->setValue(newValue);
	else
		insertRandom(squares);
}

void moveLeft(Square *squares[4][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (!squares[y][x]->isEmpty() && x != 0) { // Is not empty, and is not far left
				if (squares[y][x -1]->isEmpty()) { // if cell on left is empty
					squares[y][x -1]->setValue(squares[y][x]->getValue());
					squares[y][x]->setValue(1);
				} else if (squares[y][x -1]->getValue() == squares[y][x]->getValue()) {
					squares[y][x -1]->setValue(squares[y][x -1]->getValue() * 2);
					squares[y][x]->setValue(1);
				} 
			}
		}
	}
}

void moveUp(Square *squares[4][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (!squares[x][y]->isEmpty() && x != 0) { // Is not empty and not top
				if (squares[x - 1][y]->isEmpty()) { 
					squares[x - 1][y]->setValue(squares[x][y]->getValue());
					squares[x][y]->setValue(1);
				} else if (squares[x - 1][y]->getValue() == squares[x][y]->getValue()) {
					squares[x - 1][y]->setValue(squares[x - 1][y]->getValue() * 2);
					squares[x][y]->setValue(1);
				}
			}
		}
	}
}

void moveRight(Square *squares[4][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (!squares[y][x]->isEmpty() && x != 3) { // Is not empty, and is not far Right
				if (squares[y][x + 1]->isEmpty()) { // if cell on left is empty
					squares[y][x + 1]->setValue(squares[y][x]->getValue());
					squares[y][x]->setValue(1);
				} else if (squares[y][x + 1]->getValue() == squares[y][x]->getValue()) {
					squares[y][x + 1]->setValue(squares[y][x + 1]->getValue() * 2);
					squares[y][x]->setValue(1);
				}
			}
		}
	}
}

void moveDown(Square *squares[4][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (!squares[x][y]->isEmpty() && y != 3) { // Is not empty and not bottom
				if (squares[x + 1][y]->isEmpty()) {
					squares[x + 1][y]->setValue(squares[x][y]->getValue());
					squares[x][y]->setValue(1);
				} else if (squares[x + 1][y]->getValue() == squares[x][y]->getValue()) {
					squares[x + 1][y]->setValue(squares[x + 1][y]->getValue() * 2);
					squares[x][y]->setValue(1);
				}
			}
		}
	}
}


bool boardFull(Square *squares[4][4]) {
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (squares[x][y]->isEmpty())
				return false;
	return true;
}