#pragma once

#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>



class InventoryOxygenTube{
public:
	InventoryOxygenTube();
	float useOxygen(float currentO2);
	float getOxygen();
private:
	float O2;
};