#pragma once
#include <SFML\Graphics.hpp>
#include "HealthKit.h"


class KitStack{
public:
	void addHealthKit(HealthKit*);
	void drawStack(sf::RenderWindow &window);
	bool checkIfTouchKit(sf::IntRect playerRect);
private:
	typedef std::vector<HealthKit*> Stack;
	Stack kitStack;
};