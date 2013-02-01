#pragma once
#include <SFML\Graphics.hpp>

#include "Animation.h"

class Pillar
{
public:
	Pillar(int x, int y,sf::Image image);
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	bool getExist();
	bool getBreaking();
	void setBreaking(bool breaking);
	void setY(int y);
	sf::IntRect getRect();
	void drawPillar(sf::RenderWindow &window);
	void breakPillar();
	void startClock();
private:
	Animation pillarAnimation;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape bild;
	sf::IntRect rect;
	sf::Clock clock;
	bool exist;
	bool breaking;
	sf::Color ferg;
};