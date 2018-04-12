#include "Square.h"

Square::Square(int sizeX, int sizeY) {
	this->font.loadFromFile("helvetica.ttf");
	
	this->label.setFont(this->font);
	this->label.setCharacterSize(24);
	this->label.setColor(sf::Color::Black);
	this->label.setString(valueStr);
	
	this->setFillColor(sf::Color(255, 219, 170));
	this->setSize(sf::Vector2f(75 - this->border, 75 - this->border));
	
	this->setOutlineColor(sf::Color(215, 171, 110));
	this->setOutlineThickness(this->border);

	cout << this->getGlobalBounds().left << endl;

	int x = ( this->getSize().x / 2 ) - (this->label.getLocalBounds().width  / 2);
	int y = ( this->getSize().y / 2 ) - (this->label.getLocalBounds().height / 1.5);
	this->label.setPosition(sf::Vector2f(x, y));
}

Square::Square(int sizeX, int sizeY, int posX, int posY) : Square(sizeX, sizeY) {
	this->setPosition(posX, posY);
}

sf::Text Square::getLabel() { return this->label; }

int Square::getValue() { return this->value; }

void Square::setValue(int newValue) {
	this->value = newValue;
	this->setLabel();
}

void Square::setLabel() { this->valueStr = to_string(this->value); }

void Square::setPosition(int x, int y) {
	this->sf::RectangleShape::setPosition(x + this->border, y + this->border);

	x = (x + (this->getSize().x / 2)) - (this->label.getLocalBounds().width  / 2);
	y = (y + (this->getSize().y / 2)) - (this->label.getLocalBounds().height / 2);
	this->label.setPosition(sf::Vector2f(x, y));
}