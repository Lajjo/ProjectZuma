#include "DeathBlock.h"
#include <iostream>

DeathBlock::DeathBlock(int x, int y, int width, int height){
	position.x = static_cast <float>(x);
	position.y = static_cast <float>(y);
	size.x = static_cast <float>(width);
	size.y = static_cast <float>(height);

	rect.left = x;
	rect.top = y;
	rect.width = width;
	rect.height = height;

	bild.setPosition(position);
	bild.setSize(size);
	bild.setFillColor(sf::Color::Red);
}

float DeathBlock::getX(){
	return position.x;
}

float DeathBlock::getY(){
	return position.y;
}


float DeathBlock::getWidth(){
	return size.x;
}


float DeathBlock::getHeight(){
	return size.y;
}

void DeathBlock::drawDeathBlock(sf::RenderWindow &window){
	window.draw(bild);
}