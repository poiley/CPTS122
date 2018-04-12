#include "Square.h"

Square::Square(int sizeX, int sizeY) {
	this->font.loadFromFile("helvetica.ttf");
	
	this->setValue(0);

	this->label.setFont(this->font);
	this->label.setCharacterSize(24);
	this->label.setColor(sf::Color::Black);
	this->label.setString(valueStr);
	
	this->setFillColor(this->bgColor);
	this->setSize(sf::Vector2f(75 - this->border, 75 - this->border));
	
	this->setOutlineColor(this->borderColor);
	this->setOutlineThickness(this->border);

	int x = ( this->getSize().x / 2 ) - (this->label.getLocalBounds().width  / 2);
	int y = ( this->getSize().y / 2 ) - (this->label.getLocalBounds().height / 1.5);
	this->label.setPosition(sf::Vector2f(x, y));

	this->update();
}

Square::Square(int sizeX, int sizeY, int posX, int posY) : Square(sizeX, sizeY) {
	this->setPosition(posX, posY);
}

sf::Text Square::getLabel() { return this->label; }

int Square::getValue() { return this->value; }

void Square::setValue(int newValue) {
	this->value = newValue;
	this->update();
}

void Square::setLabel() {
	this->valueStr = "";
	if (this->value != 0)
		valueStr = to_string(this->value);
	this->label.setString(valueStr);
}

void Square::update() {
	this->setLabel();
	this->setFillColor(this->bgColor);
	if (this->value == 0)
		this->setFillColor(sf::Color::Transparent);
	this->setPosition(this->getGlobalBounds().top, this->getGlobalBounds().left);
}

void Square::setPosition(int x, int y) {
	this->sf::RectangleShape::setPosition(x + this->border, y + this->border);

	x = x + (this->getSize().x / 2) - (this->label.getLocalBounds().width  / 2);
	y = y + (this->getSize().y / 2) - (this->label.getLocalBounds().height / 2) - 5;
	this->label.setPosition(sf::Vector2f(x, y));
}