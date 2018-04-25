#include "Gameplay.h"

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
				switch (event.key.code) {
					case sf::Keyboard::Left:
						moveLeft(squares, score);
						insertRandom(squares);
						break;
					case sf::Keyboard::Up:
						moveUp(squares, score);
						insertRandom(squares);
						break;
					case sf::Keyboard::Right:
						moveRight(squares, score);
						insertRandom(squares);
						break;
					case sf::Keyboard::Down:
						moveDown(squares, score);
						insertRandom(squares);
						break;
				}
			}		
		}


		display->clear(bgColor); // Clear screen with Background color
	
		display->draw(*score); // Scoreboard
		display->draw(squares); // Squares

		display->display();

		if (boardFull(squares)) { // end game code
			display->clear(bgColor);

			sf::Font font;
			sf::Text label;
			font.loadFromFile("helvetica.ttf");
			
			label.setFont(font);
			label.setCharacterSize(24);
			label.setColor(sf::Color::Black);
			label.setString("Game Over!");
			label.setPosition(sf::Vector2f(15 + (label.getLocalBounds().width / 2), 130));

			score->setPosition(sf::Vector2f(15 + (label.getLocalBounds().width / 2),
				   label.getGlobalBounds().top + (label.getLocalBounds().height / 2) + 10));
			score->setColor(sf::Color::Black);
			score->clearBackground();

			display->draw(*score);
			display->draw(label);

			display->display();
			while (display->pollEvent(event)) { // Controls / Event loop
				if (event.type == sf::Event::Closed)
					display->close();
				if (event.type == sf::Event::KeyPressed) {
				}
			}
		}
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

void moveLeft(Square *squares[4][4], Scoreboard *score) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (!squares[y][x]->isEmpty() && x != 0) { // Is not empty, and is not far left
				if (squares[y][x - 1]->isEmpty()) {    // if cell on left is empty
					squares[y][x - 1]->setValue(squares[y][x]->getValue());
					squares[y][x]->setValue(1);
				} else if (squares[y][x - 1]->getValue() == squares[y][x]->getValue()) {
					squares[y][x - 1]->setValue(squares[y][x - 1]->getValue() * 2);
					squares[y][x]->setValue(1);
					score->addValue(squares[y][x - 1]->getValue() / 2);
				} 
			}
		}
	}
}

void moveUp(Square *squares[4][4], Scoreboard *score) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (!squares[y][x]->isEmpty() && y != 0) { // Is not empty and not top
				if (squares[y - 1][x]->isEmpty()) { 
					squares[y - 1][x]->setValue(squares[y][x]->getValue());
					squares[y][x]->setValue(1);
				} else if (squares[y - 1][x]->getValue() == squares[y][x]->getValue()) {
					squares[y - 1][x]->setValue(squares[y - 1][x]->getValue() * 2);
					squares[y][x]->setValue(1);
					score->addValue(squares[y - 1][x]->getValue() / 2);
				}
			}
		}
	}
}

void moveRight(Square *squares[4][4], Scoreboard *score) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (!squares[y][x]->isEmpty() && x != 3) { // Is not empty, and is not far Right
				if (squares[y][x + 1]->isEmpty()) { // if cell on left is empty
					squares[y][x + 1]->setValue(squares[y][x]->getValue());
					squares[y][x]->setValue(1);
				} else if (squares[y][x + 1]->getValue() == squares[y][x]->getValue()) {
					squares[y][x + 1]->setValue(squares[y][x + 1]->getValue() * 2);
					squares[y][x]->setValue(1);
					score->addValue(squares[y][x + 1]->getValue() / 2);
				}
			}
		}
	}
}

void moveDown(Square *squares[4][4], Scoreboard *score) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (!squares[y][x]->isEmpty() && y != 3) { // Is not empty and not bottom
				if (squares[y + 1][x]->isEmpty()) {
					squares[y + 1][x]->setValue(squares[y][x]->getValue());
					squares[y][x]->setValue(1);
				} else if (squares[y + 1][x]->getValue() == squares[y][x]->getValue()) {
					squares[y + 1][x]->setValue(squares[y + 1][x]->getValue() * 2);
					squares[y][x]->setValue(1);
					score->addValue(squares[y + 1][x]->getValue() / 2);
				}
			}
		}
	}
}

bool boardFull(Square *squares[4][4]) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (squares[y][x]->isEmpty())
				return false;
			if (y != 0)
				if (squares[y][x]->getValue() == squares[y - 1][x]->getValue())
					return false;

			if (x != 0)
				if (squares[y][x]->getValue() == squares[y][x - 1]->getValue())
					return false;
		}
	}
	return true;
}