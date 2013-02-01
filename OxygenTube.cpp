#include "OxygenTube.h"
#include <iostream>

OxygenTube::OxygenTube(int x, int y,sf::Sprite nSprite){
	position.x = x;
	position.y = y;
	//sprite.setTexture(texture);

	sprite = nSprite;

	rect.left = x+8;
	rect.top = y+8;
	rect.width = sprite.getLocalBounds().width-16;
	rect.height = sprite.getLocalBounds().height-16;

	sprite.setPosition(position);
	
}

float OxygenTube::getX(){
	return position.x;
}

float OxygenTube::getY(){
	return position.y;
}


float OxygenTube::getWidth(){
	return sprite.getLocalBounds().width;
}


float OxygenTube::getHeight(){
	return sprite.getLocalBounds().height;
}

sf::IntRect OxygenTube::getRect(){
	return rect;
}

void OxygenTube::drawOxygenTube(sf::RenderWindow &window){
	window.draw(sprite);
}