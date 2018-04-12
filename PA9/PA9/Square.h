#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class Square : public sf::RectangleShape {
	public:
		Square(int sizeX, int sizeY);
		Square(int sizeX, int sizeY, int posX, int posY);

		sf::Text getLabel();
		int getValue();

		void setValue(int newValue);	
		void setPosition(int x, int y);
	private:
		sf::Font font;
		sf::Text label;
		int value = 0, border = 3;
		string valueStr = to_string(value);

		void setLabel();
};