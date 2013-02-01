#pragma once
//#define GAS_H
#include <SFML\Graphics.hpp>

class Gas
{
public:
	Gas(int x, int y, sf::Sprite sprite);
	Gas(sf::Vector2f position, sf::Sprite sprite);
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	void drawGas(sf::RenderWindow &window);
private:
	sf::Vector2f position;
	sf::Vector2i size;
	sf::Sprite sprite;
	sf::IntRect rect;

};




//#endif