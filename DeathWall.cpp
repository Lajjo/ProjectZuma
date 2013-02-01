#include "DeathWall.h"
#include <SFML\Graphics.hpp>

void DeathWall::addDeathBlock(DeathBlock *d){
	deathWall.push_back(d);
}

void DeathWall::drawDeathWall(sf::RenderWindow &window){
	for(Wall::size_type i = 0; i < deathWall.size(); i++){
		deathWall[i]->drawDeathBlock(window);
	}
}

bool DeathWall::checkIfHitDeathBlock(sf::IntRect playerRect){
	for(Wall::size_type i = 0; i < deathWall.size(); i++){
		sf::IntRect rect;
		rect.left = static_cast <int>(deathWall[i]->getX());
		rect.top = static_cast <int>(deathWall[i]->getY());
		rect.width = static_cast <int>(deathWall[i]->getWidth());
		rect.height = static_cast <int>(deathWall[i]->getHeight());

		if(playerRect.intersects(rect))
			return true;
	}
	return false;
}