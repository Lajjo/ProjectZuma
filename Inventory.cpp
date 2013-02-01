#include "Inventory.h"


Inventory::Inventory()
{
  int k = 0;
	fRectStack.push_back(sf::FloatRect(0,0,188,188));
	fRectStack.push_back(sf::FloatRect(0,0,188,188));
	fRectStack.push_back(sf::FloatRect(0,0,188,188));
	fRectStack.push_back(sf::FloatRect(0,0,188,188));
	fRectStack.push_back(sf::FloatRect(0,0,188,188));
	fRectStack.push_back(sf::FloatRect(0,0,188,188));
	fRectStack.push_back(sf::FloatRect(0,0,188,188));
	fRectStack.push_back(sf::FloatRect(0,0,188,188));
	




	tabNumber = 0;
	image.loadFromFile("../Images/UI_tools_active.png");
	toolsTexture.loadFromImage(image);
	tools.setTexture(toolsTexture);
	tools.setPosition((1260-1075)/2,(788-500)/2);

	image.loadFromFile("../Images/UI_consumables_active.png");
	consumablesTexture.loadFromImage(image);
	consumables.setTexture(consumablesTexture);
	consumables.setPosition((1260-1075)/2,(788-500)/2);

	image.loadFromFile("../Images/UI_notes_active.png");
	notesTexture.loadFromImage(image);
	notes.setTexture(notesTexture);
	notes.setPosition((1260-1075)/2,(788-500)/2);
	
	
	fRectStack.push_back(sf::FloatRect(0,0,285,74));	
	fRectStack.push_back(sf::FloatRect(0,0,404,74));
	fRectStack.push_back(sf::FloatRect(0,0,285,74));


	/*backFloatRect.left = backRect.getLocalBounds().left;
	backFloatRect.top = backRect.getLocalBounds().top;
	backFloatRect.width = backRect.getLocalBounds().width;
	backFloatRect.height = backRect.getLocalBounds().height;*/

	isOpen = false;
}


Inventory::~Inventory(void)
{
}

void Inventory::openInventory(){

}

void Inventory::drawInventory(sf::RenderWindow &window){
	if(isOpen && tabNumber == 0){
		window.draw(tools);
	}

	if(isOpen && tabNumber == 1){
		window.draw(consumables);
	}

	if(isOpen && tabNumber == 2){
		window.draw(notes);
	}
	if(isOpen){

	}

}

void Inventory::changeIsOpen(){
	isOpen = !isOpen;
}

void Inventory::update(sf::Vector2f position){
	int k = 0;
	
	fRectStack[0].left=position.x+((1260-1075)/2)+97;
	fRectStack[0].top=position.y+((788-560)/2)+145;

	fRectStack[1].left=position.x+((1260-1075)/2)+97;
	fRectStack[1].top=position.y+((788-560)/2)+374;

	fRectStack[2].left=position.x+((1260-1075)/2)+97;
	fRectStack[2].top=position.y+((788-560)/2)+145;

	fRectStack[3].left=position.x+((1260-1075)/2)+97;
	fRectStack[3].top=position.y+((788-560)/2)+374;

	fRectStack[4].left=position.x+((1260-1075)/2)+97;
	fRectStack[4].top=position.y+((788-560)/2)+145;

	fRectStack[5].left=position.x+((1260-1075)/2)+97;
	fRectStack[5].top=position.y+((788-560)/2)+374;

	fRectStack[6].left=position.x+((1260-1075)/2)+334;
	fRectStack[6].top=position.y+((788-560)/2)+145;

	fRectStack[7].left=position.x+((1260-1075)/2)+30;
	fRectStack[7].top=position.y+((788-560)/2)+14;
	
	fRectStack[8].left=position.x+((1260-1075)/2)+332;
	fRectStack[8].top=position.y+((788-560)/2)+14;
	
	fRectStack[9].left=position.x+((1260-1075)/2)+756;
	fRectStack[9].top=position.y+((788-560)/2)+14;

	tools.setPosition(position.x+((1260-1075)/2),position.y+((788-560)/2));
	consumables.setPosition(position.x+((1260-1075)/2),position.y+((788-560)/2));
	notes.setPosition(position.x+((1260-1075)/2),position.y+((788-560)/2));



}

int Inventory::checkIfPressed(float x, float y){

	if(fRectStack[7].contains(x,y)){
		tabNumber = 0;
	}
	if(fRectStack[8].contains(x,y)){
		tabNumber = 1;
	}
	if(fRectStack[9].contains(x,y)){
		tabNumber = 2;
	}
	if(isOpen && tabNumber == 0){
		for(int i = 0; i < 2; i++){
			if(fRectStack[i].contains(x,y)){
				return i+1;
			}
		}
	}
	else if(isOpen && tabNumber == 1){
		for(int i = 2; i < 4; i++){
			if(fRectStack[i].contains(x,y)){
				return i+1;
			}
		}
	}
	else if(isOpen && tabNumber == 2){
		for(int i = 4; i < 7; i++){
			if(fRectStack[i].contains(x,y)){
				return i+1;
			}
		}
	}
	else
		return 0;
}
int Inventory::checkIfPressed(sf::FloatRect position){
	if(isOpen && tabNumber == 0){
		for(int i = 0; i < 2; i++){
			if(fRectStack[i].contains(position.left,position.top)){
				return i+1;
			}
		}
	}
	else if(isOpen && tabNumber == 1){
		for(int i = 2; i < 4; i++){
			if(fRectStack[i].contains(position.left,position.top)){
				return i+1;
			}
		}
	}
	else if(isOpen && tabNumber == 2){
		for(int i = 4; i < 7; i++){
			if(fRectStack[i].contains(position.left,position.top)){
				return i+1;
			}
		}
	}
	else
		return 0;
}
