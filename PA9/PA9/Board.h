#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Square.h"

class Board : public sf::RenderWindow {
	public:
		Board(int x, int y, string title);
		void draw(sf::Drawable &sq);

	private:
		int sizeX, sizeY;
}