#pragma once

#include "InventoryOxygenTube.h"
#include <SFML\Graphics.hpp>

class InventoryTubeStack{
public:
	void addTube(InventoryOxygenTube*);
	void deleteTube();
	float useTube(float currentO2);
	float getCurrentTubeO2();
	int getStackSize();
private:
	typedef std::vector<InventoryOxygenTube*> Tubes;
	Tubes tubeStack;
};
