#ifndef LevelEngine_H
#define LevelEngine_H

#include <SFML\Graphics.hpp>
#include "Tiles.h"
#include "InventoryTubeStack.h"
#include "InventoryKitStack.h"
#include "KitStack.h"
#include "TubeStack.h"
#include "Inventory.h"

class Character;
class GasCloud;


class LevelEngine{
public:
  LevelEngine(GasCloud &cloud,sf::Sprite &castSprite);
	~LevelEngine();
	void update(Character& player, KitStack& ks, TubeStack& ts, InventoryTubeStack& its, InventoryKitStack& iks, Inventory& inv, sf::Vector2i mousePos);
	void draw(sf::RenderWindow& window);
private:
	sf::Image level;
	Tiles tiles;
	GasCloud& gasCloud;
	sf::Clock timer;
	sf::Clock healCast;
	sf::Sprite& castSprite;
};

#endif
