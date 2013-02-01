#pragma once
#include <SFML\Graphics.hpp>

class OxygenTube{
public:
	OxygenTube(int x, int y, sf::Sprite sprite);
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	sf::IntRect getRect();
	void drawOxygenTube(sf::RenderWindow &window);
private:
	sf::Vector2f position;
	sf::IntRect rect;
	sf::Sprite sprite;
};