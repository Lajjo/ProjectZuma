#include "InventoryKitStack.h"

void InventoryKitStack::addKit(InventoryHealthKit*k){
	kitStack.push_back(k);
}

void InventoryKitStack::deleteKit(){
	delete kitStack[0];
	kitStack.erase(kitStack.begin());
}

float InventoryKitStack::useKit(float currentHP){
	return kitStack[0]->useKit(currentHP);
}

int InventoryKitStack::getStackSize(){
	return kitStack.size();
}