#include "GasCloud.h"
#include <SFML\Graphics.hpp>

void GasCloud::addGas(Gas *g){
	gasCloud.push_back(g);
}

void GasCloud::drawCloud(sf::RenderWindow &window){
	for(Cloud::size_type i = 0; i < gasCloud.size(); i++){
		gasCloud[i]->drawGas(window);
	}
}

bool GasCloud::checkIfInsideGas(int x, int y){
	for(Cloud::size_type i = 0; i < gasCloud.size(); i++){
		sf::IntRect rect;
		rect.left = static_cast <int>(gasCloud[i]->getX());
		rect.top = static_cast <int>(gasCloud[i]->getY());
		rect.width = static_cast <int>(gasCloud[i]->getWidth());
		rect.height = static_cast <int>(gasCloud[i]->getHeight());

		if(rect.contains(x,y))
			return true;
	}
	return false;
}