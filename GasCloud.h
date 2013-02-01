#pragma once
#include <SFML\Graphics.hpp>
#include "Gas.h"


class GasCloud{
public:
	void addGas(Gas*);
	void drawCloud(sf::RenderWindow &window);
	bool checkIfInsideGas(int x, int y);
private:
	typedef std::vector<Gas*> Cloud;
	Cloud gasCloud;
};