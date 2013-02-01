#ifndef TILES_H
#define TILES_H

#include "GasCloud.h"
#include <SFML\Graphics.hpp>

//class GasCloud;

class Tiles{
public:
	Tiles();
	~Tiles();
	void initialize(sf::Color color, sf::Vector2f position, GasCloud &gasCloud);
	void draw(sf::Color color, sf::Vector2f position, sf::RenderWindow& window);
private:
	sf::Image tiles;
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif