#include "Pillar.h"
#include <iostream>

Pillar::Pillar(int x, int y,sf::Image image){
	position.x = x;
	position.y = y;
	size.x = 32;
	size.y = 32;

	rect.left = x;
	rect.top = y;
	rect.width = 32;
	rect.height = 32;

	ferg.r = 102;
	ferg.g = 102;
	ferg.b = 114;

	bild.setPosition(position);
	bild.setSize(size);
	bild.setFillColor(ferg);

	exist = true;
	breaking = false;

	pillarAnimation.Initialize(position.x,position.y,5,1,500.00f);
	pillarAnimation.setImage(image);
}


float Pillar::getX(){
	return position.x;
}

float Pillar::getY(){
	return position.y;
}


float Pillar::getWidth(){
	return size.x;
}


float Pillar::getHeight(){
	return size.y;
}

bool Pillar::getExist(){
	return exist;
}

bool Pillar::getBreaking(){
	return breaking;
}

void Pillar::setBreaking(bool nBreaking){
	breaking = nBreaking;
}

sf::IntRect Pillar::getRect(){
	return rect;
}

void Pillar::setY(int nY){
	rect.top = nY;
}

void Pillar::drawPillar(sf::RenderWindow &window){
	window.draw(bild);
	pillarAnimation.Update(window,breaking);
	pillarAnimation.Draw(window);
	breakPillar();
}

void Pillar::breakPillar(){
	if(clock.getElapsedTime().asMilliseconds()> 2000 && breaking)
		exist = false;
}

void Pillar::startClock(){
	clock.restart();
}