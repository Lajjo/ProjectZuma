#pragma once

#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>



class InventoryHealthKit{
public:
	InventoryHealthKit();
	float useKit(float currentHP);
private:
	float HP;
};