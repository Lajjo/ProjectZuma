#include "KitStack.h"
#include <SFML\Graphics.hpp>

void KitStack::addHealthKit(HealthKit *k){
	kitStack.push_back(k);
}

void KitStack::drawStack(sf::RenderWindow &window){
	for(Stack::size_type i = 0; i < kitStack.size(); i++){
		kitStack[i]->drawHealthKit(window);
	}
}

bool KitStack::checkIfTouchKit(sf::IntRect playerRect){
	for(Stack::size_type i = 0; i < kitStack.size(); i++){
		if(kitStack[i]->getRect().intersects(playerRect)){
			delete kitStack[i];
			std::swap(kitStack[i],kitStack.back());
			kitStack.pop_back();
			return true;
		}
	}
	return false;
}