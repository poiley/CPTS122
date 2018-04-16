#include "Window.h"

Window::Window(int x, int y, string title) : RenderWindow(sf::VideoMode(x, y), title) {
	this->sizeX = x;
	this->sizeY = y;
	
	int BORDER_SIZE = 3;

	this->board.setPosition(sf::Vector2f(BORDER_SIZE, BORDER_SIZE));
	this->board.setFillColor(this->boardColor);
	this->board.setSize(sf::Vector2f(sizeX - (2 * BORDER_SIZE), sizeX - (2 * BORDER_SIZE)));
	this->board.setOutlineThickness(BORDER_SIZE);
	this->board.setOutlineColor(borderColor);

	this->draw(this->board);
}

void Window::clear(sf::Color &bg) {
	sf::RenderWindow::clear(bg);
	this->draw(this->board);
}

void Window::draw(sf::Drawable &d) {
	sf::RenderWindow::draw(d);
}

void Window::draw(Square &sq) {
	sq.update();
	sf::RenderWindow::draw(sq);
	sf::RenderWindow::draw(sq.getLabel());
}

void Window::draw(Scoreboard &sc) {
	sf::RenderWindow::draw(sc.getBackground());
	sf::RenderWindow::draw(sc);
}

void Window::draw(Square *squares[4][4]) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			this->draw(*squares[i][j]);
}

