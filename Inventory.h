#pragma once

#include <SFML\Graphics.hpp>
#include "InventoryTubeStack.h"
#include "InventoryKitStack.h"

class Inventory
{
public:
  Inventory();
	~Inventory(void);
	void openInventory();
	void drawInventory(sf::RenderWindow& window);
	void changeIsOpen();
	void update(sf::Vector2f position);
	int checkIfPressed(float x, float y);
	int checkIfPressed(sf::FloatRect position);
private:
	bool isOpen;
	sf::Image image;
	sf::Texture toolsTexture;
	sf::Texture consumablesTexture;
	sf::Texture notesTexture;
	sf::Sprite tools;
	sf::Sprite consumables;
	sf::Sprite notes;
	sf::FloatRect backFloatRect;
	sf::IntRect gridIntRectHealth;
	sf::IntRect gridIntRectOxygen;
	typedef std::vector<sf::FloatRect> fRStack;
	fRStack fRectStack;
	int tabNumber;
};
