#include "Window.h"
#include "Scoreboard.h"

int main(void) {
	int SQUARE_X = 75, SQUARE_Y = 75, BORDER_SIZE = 3;

	Window	   *display = new Window(300 + BORDER_SIZE, 400, "2048");
	Scoreboard *score   = new Scoreboard(20, 325);
	sf::Color   bgColor = sf::Color(170, 122, 57);

	Square *squares[10][10];
	for (int y = 0, i = 0; i < 4; i++, y += 75)
		for (int x = 0, j = 0; j < 4;j++, x += 75)
			squares[i][j] = new Square(SQUARE_X, SQUARE_Y, x, y);

	while (display->isOpen()) {
		sf::Event event;
		while (display->pollEvent(event)) { // Controls / Event loop
			if (event.type == sf::Event::Closed)
				display->close();
		}

		display->clear(bgColor); // Clear screen with Background color
		
		display->draw(*score); // Scoreboard
		display->draw(squares); // Squares

		display->display();
	}

	return 0;
}