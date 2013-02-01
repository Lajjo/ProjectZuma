#include "Gas.h"
#include <iostream>

Gas::Gas(int x, int y,sf::Sprite nSprite){
	position.x = static_cast <float>(x);
	position.y = static_cast <float>(y);
	size.x = 32;
	size.y = 32;

	rect = sf::IntRect(static_cast <sf::Vector2i>(position), size);

	sprite = nSprite;
	sprite.setPosition(position);
}

Gas::Gas(sf::Vector2f nPosition, sf::Sprite nSprite){
	position = nPosition;
	size.x = 32;
	size.y = 32;

	rect = sf::IntRect(static_cast <sf::Vector2i>(position), size);

	sprite = nSprite;
	sprite.setPosition(position);
}

float Gas::getX(){
	return position.x;
}

float Gas::getY(){
	return position.y;
}


float Gas::getWidth(){
	return static_cast <float>(size.x);
}


float Gas::getHeight(){
	return static_cast <float>(size.y);
}

void Gas::drawGas(sf::RenderWindow &window){
	window.draw(sprite);
}
