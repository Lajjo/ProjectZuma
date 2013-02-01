#include "InventoryOxygenTube.h"


InventoryOxygenTube::InventoryOxygenTube(){
	O2 = 20;
}

float InventoryOxygenTube::useOxygen(float currentO2){
	if(O2 > 0){
		O2 -= 0.1f;
		currentO2 += 0.1f;
	}
	return currentO2;
}

float InventoryOxygenTube::getOxygen(){
	return O2;
}