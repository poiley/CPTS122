#include "Board.h"

Board::Board(int x, int y, string title) : RenderWindow(sf::VideoMode(x, y), title) {
	this->sizeX = x;
	this->sizeY = y;
}

void Board::draw(sf::Drawable &sq) {
	sf::RenderWindow::draw(sq);
}