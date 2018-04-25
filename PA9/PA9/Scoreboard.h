#pragma once

#include "Square.h"

class Scoreboard : public sf::Text {
	public:
		Scoreboard(int posX, int posY);

		string getLabel();
		int getValue();
		sf::RectangleShape getBackground();

		void setValue(int newValue);
		void addValue(int newValue);

		void clearBackground();
	private:
		sf::Font font;
		sf::Color bgColor = sf::Color(255, 219, 170),
				  borderColor = sf::Color(75, 75, 75);
		sf::RectangleShape background;
		int value = 0;

		void update();
		void setLabel();
};