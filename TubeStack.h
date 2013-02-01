#pragma once
#include <SFML\Graphics.hpp>
#include "OxygenTube.h"


class TubeStack{
public:
	void addOxygenTube(OxygenTube*);
	void drawStack(sf::RenderWindow &window);
	bool checkIfTouchTube(sf::IntRect playerRect);
private:
	typedef std::vector<OxygenTube*> Stack;
	Stack tubeStack;
};