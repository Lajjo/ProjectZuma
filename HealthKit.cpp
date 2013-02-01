#include "HealthKit.h"
#include <iostream>

HealthKit::HealthKit(int x, int y,sf::Sprite nSprite){
	position.x = x;
	position.y = y;

	sprite = nSprite;

	rect.left = x+8;
	rect.top = y+8;
	rect.width = sprite.getLocalBounds().width-16;
	rect.height = sprite.getLocalBounds().height-16;

	sprite.setPosition(position);
	
}

float HealthKit::getX(){
	return position.x;
}

float HealthKit::getY(){
	return position.y;
}


float HealthKit::getWidth(){
	return sprite.getLocalBounds().width;
}


float HealthKit::getHeight(){
	return sprite.getLocalBounds().height;
}

sf::IntRect HealthKit::getRect(){
	return rect;
}

void HealthKit::drawHealthKit(sf::RenderWindow &window){
	window.draw(sprite);
}