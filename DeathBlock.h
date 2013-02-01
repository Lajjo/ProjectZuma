#pragma once
//#define GAS_H
#include <SFML\Graphics.hpp>

class DeathBlock
{
public:
	DeathBlock(int x, int y, int width, int height);
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	void drawDeathBlock(sf::RenderWindow &window);
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape bild;
	sf::IntRect rect;

};