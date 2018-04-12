#pragma once

#include "Scoreboard.h"

Scoreboard::Scoreboard(int posX, int posY) {
	this->font.loadFromFile("helvetica.ttf");

	this->setValue(0);

	this->setFont(this->font);
	this->setCharacterSize(24);
	this->setColor(sf::Color::White);

	this->background.setFillColor(sf::Color::Black);
	this->background.setSize(sf::Vector2f(200, 50));
	this->background.setPosition(posX, posY);
	
	this->setPosition(sf::Vector2f(
		this->background.getPosition().x + 10,
		this->background.getPosition().y + 10));
	
	this->update();
}

string Scoreboard::getLabel() { return this->getString(); }

int Scoreboard::getValue() { return this->value; }

sf::RectangleShape Scoreboard::getBackground() {
	return this->background;
}

void Scoreboard::setValue(int newValue) {
	this->value += newValue;
	this->update();
}

void Scoreboard::setLabel() { this->setString("Score: " + to_string(this->value)); }

void Scoreboard::update() {	this->setLabel(); }
