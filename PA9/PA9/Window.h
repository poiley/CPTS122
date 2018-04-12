#pragma once

#include "Square.h"
#include "Scoreboard.h"

class Window : public sf::RenderWindow {
	public:
		Window(int x, int y, string title);
		
		void draw(sf::Drawable &d);
		void draw(Square &sq);
		void draw(Scoreboard &sc);
		void draw(Square *squares[10][10]);

		void clear(sf::Color &bg);

	private:
		sf::RectangleShape board;
		sf::Color boardColor = sf::Color(105, 105, 105), 
			borderColor = sf::Color(47, 79, 79);;
		int sizeX, sizeY;
};