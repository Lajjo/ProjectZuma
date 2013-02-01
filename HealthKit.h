#pragma once
#include <SFML\Graphics.hpp>

class HealthKit{
public:
	HealthKit(int x, int y, sf::Sprite sprite);
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	sf::IntRect getRect();
	void drawHealthKit(sf::RenderWindow &window);
private:
	sf::Vector2f position;
	sf::IntRect rect;
	sf::Sprite sprite;
};