#include "InventoryHealthKit.h"


InventoryHealthKit::InventoryHealthKit(){
	HP = 25;
}

float InventoryHealthKit::useKit(float currentHP){
	
	currentHP += HP; 
	if(currentHP > 100)
		currentHP = 100;

	return currentHP;
}

