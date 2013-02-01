#pragma once
#include <SFML\Graphics.hpp>
#include "Pillar.h"



class PillarStack{
public:
	void addPillar(Pillar*);
	void drawStack(sf::RenderWindow &window);
	void checkIfOnTopPillar(sf::IntRect rect);
	void checkIfExist();
private:
	typedef std::vector<Pillar*> Stack;
	Stack pillarStack;
};