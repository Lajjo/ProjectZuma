#pragma once

#include "InventoryHealthKit.h"
#include <SFML\Graphics.hpp>

class InventoryKitStack{
public:
	void addKit(InventoryHealthKit*);
	void deleteKit();
	float useKit(float currentHP);
	int getStackSize();
private:
	typedef std::vector<InventoryHealthKit*> Kits;
	Kits kitStack;
};