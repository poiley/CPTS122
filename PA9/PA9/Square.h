#pragma once

#include "Resources.h"

class Square : public sf::RectangleShape {
	public:
		Square(int sizeX, int sizeY);
		Square(int sizeX, int sizeY, int posX, int posY);

		sf::Text getLabel();
		int getValue();

		void setValue(int newValue);	
		void update();
		void setPosition(int x, int y);
	private:
		sf::Font font;
		sf::Text label;
		sf::Color bgColor = sf::Color(255, 219, 170), 
				  borderColor = sf::Color(75, 75, 75);
		int value, border = 3;
		string valueStr = to_string(value);

		void setLabel();
};