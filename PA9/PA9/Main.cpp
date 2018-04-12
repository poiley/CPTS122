#include <SFML/Graphics.hpp>
#include "Square.h"

int main(void) {
	int SQUARE_X = 75, SQUARE_Y = 75;

	sf::RenderWindow window(sf::VideoMode(300, 300), "2048");
	
	Square *squares[10][10];
	for (int y = 0, i = 0; i < 4; i++, y += 75)
		for (int x = 0, j = 0; j < 4;j++, x += 75)
			squares[i][j] = new Square(SQUARE_X, SQUARE_Y, x, y);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) { // event loop
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(170, 122, 57));

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				window.draw(*squares[i][j]);
				window.draw(squares[i][j]->getLabel());
			}
		}

		window.display();
	}

	return 0;
}