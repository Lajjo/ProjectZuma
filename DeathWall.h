#pragma once
#include <SFML\Graphics.hpp>
#include "DeathBlock.h"


class DeathWall{
public:
	void addDeathBlock(DeathBlock*);
	void drawDeathWall(sf::RenderWindow &window);
	bool checkIfHitDeathBlock(sf::IntRect rect);
private:
	typedef std::vector<DeathBlock*> Wall;
	Wall deathWall;
};