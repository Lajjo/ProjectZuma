#include "InventoryTubeStack.h"

void InventoryTubeStack::addTube(InventoryOxygenTube*t){
	tubeStack.push_back(t);
}

void InventoryTubeStack::deleteTube(){
	delete tubeStack[0];
	tubeStack.erase(tubeStack.begin());
}

float InventoryTubeStack::useTube(float currentO2){
	return tubeStack[0]->useOxygen(currentO2);
}

float InventoryTubeStack::getCurrentTubeO2(){
	return tubeStack[0]->getOxygen();
}

int InventoryTubeStack::getStackSize(){
	return tubeStack.size();
}