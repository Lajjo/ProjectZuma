#include "TubeStack.h"
#include <SFML\Graphics.hpp>

void TubeStack::addOxygenTube(OxygenTube *o){
	tubeStack.push_back(o);
}

void TubeStack::drawStack(sf::RenderWindow &window){
	for(Stack::size_type i = 0; i < tubeStack.size(); i++){
		tubeStack[i]->drawOxygenTube(window);
	}
}

bool TubeStack::checkIfTouchTube(sf::IntRect playerRect){
	for(Stack::size_type i = 0; i < tubeStack.size(); i++){
		if(tubeStack[i]->getRect().intersects(playerRect)){
			delete tubeStack[i];
			std::swap(tubeStack[i],tubeStack.back());
			tubeStack.pop_back();
			return true;
		}
	}
	return false;
}