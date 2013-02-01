#include "PillarStack.h"
#include <SFML\Graphics.hpp>

void PillarStack::addPillar(Pillar *p){
	pillarStack.push_back(p);
}

void PillarStack::drawStack(sf::RenderWindow &window){
	for(Stack::size_type i = 0; i < pillarStack.size(); i++){
		pillarStack[i]->drawPillar(window);
	}
}

void PillarStack::checkIfOnTopPillar(sf::IntRect rect){
	for(Stack::size_type i = 0; i < pillarStack.size(); i++){
		pillarStack[i]->setY(pillarStack[i]->getY()-2);

		if(pillarStack[i]->getRect().intersects(rect) && !pillarStack[i]->getBreaking()){
			pillarStack[i]->setY(pillarStack[i]->getY()+2);
			pillarStack[i]->breakPillar();
			pillarStack[i]->setBreaking(true);
			pillarStack[i]->startClock();
		}
		pillarStack[i]->setY(pillarStack[i]->getY()+2);
	}
}

void PillarStack::checkIfExist(){
	for(Stack::size_type i = 0; i < pillarStack.size(); i++){
		if(!pillarStack[i]->getExist()){
			delete pillarStack[i];
			std::swap(pillarStack[i],pillarStack.back());
			pillarStack.pop_back();
		}
	}
}