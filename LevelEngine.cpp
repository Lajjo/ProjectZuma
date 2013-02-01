#include "LevelEngine.h"
#include "Color.h"
#include "Character.h"
#include "GasCloud.h"
#include <iostream>


LevelEngine::LevelEngine(GasCloud &cloud,sf::Sprite &nCastSprite) : gasCloud(cloud) , castSprite(nCastSprite)
{
  level.loadFromFile("../Levels/feest.png");
	timer.restart();
	healCast.restart();
	for(unsigned i = 0; i < level.getSize().x; i++)
	{
		for(unsigned j = 0; j < level.getSize().y; j++)
			tiles.initialize(level.getPixel(i, j), sf::Vector2f(static_cast <float>(i * 32), static_cast <float>(j * 32)), cloud);
	}
}

LevelEngine::~LevelEngine(){}

void LevelEngine::update(Character& player, KitStack& ks, TubeStack& ts, InventoryTubeStack& its, InventoryKitStack& iks, Inventory& inv, sf::Vector2i mousePos)
{
	sf::IntRect area;
	sf::IntRect rectplayer = player.getIntrect();
	for(unsigned i = (player.getPosition().x / 32) - 1; i < (player.getPosition().x / 32) + 5; i++)
	{
		for(unsigned j = (player.getPosition().y / 32) - 1; j < (player.getPosition().y / 32) + 5; j++)
		{
			if(rectplayer.intersects(sf::IntRect(i * 32, j * 32, 32, 32), area) && level.getPixel(i, j) != My::Color::Space && level.getPixel(i, j) != My::Color::Poison && level.getPixel(i, j) != My::Color::Gas && level.getPixel(i, j) != My::Color::Ladder)
			{
				if(area.width < area.height)
				{
					if(player.getVelocity().x > 0)
					{
						player.setPosition(player.getPosition() - sf::Vector2f(static_cast <float>(area.width), 0));
					}
					if(player.getVelocity().x < 0)
					{
						player.setPosition(player.getPosition() + sf::Vector2f(static_cast <float>(area.width), 0)); 
					}
					player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
				}
				if(area.width > area.height)
				{
					if(player.getVelocity().y > 0)
						player.setPosition(player.getPosition() - sf::Vector2f(0, static_cast <float>(area.height)));
					if(player.getVelocity().y < 0)
						player.setPosition(player.getPosition() + sf::Vector2f(0, static_cast <float>(area.height)));
					player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
				}
				if(area.width == area.height)
				{
					if((player.getVelocity().x || player.getVelocity().x * -1) > (player.getVelocity().y || player.getVelocity().y * -1))
					{
						if(player.getVelocity().x > 0)
							player.setPosition(player.getPosition() - sf::Vector2f(static_cast <float>(area.width), 0));
						if(player.getVelocity().x < 0)
							player.setPosition(player.getPosition() + sf::Vector2f(static_cast <float>(area.width), 0)); 
					}
					if((player.getVelocity().x || player.getVelocity().x * -1) < (player.getVelocity().y || player.getVelocity().y * -1))
					{
						if(player.getVelocity().y > 0)
							player.setPosition(player.getPosition() - sf::Vector2f(0, static_cast <float>(area.height)));
						if(player.getVelocity().y < 0)
							player.setPosition(player.getPosition() + sf::Vector2f(0, static_cast <float>(area.height)));
					}
					if((player.getVelocity().x || player.getVelocity().x * -1) == (player.getVelocity().y || player.getVelocity().y * -1))
					{
						if(player.getVelocity().x > 0 && player.getVelocity().y > 0)
							player.setPosition(player.getPosition() - sf::Vector2f(static_cast <float>(area.width), static_cast <float>(area.height)));
						if(player.getVelocity().x > 0 && player.getVelocity().y < 0)
							player.setPosition(player.getPosition() - sf::Vector2f(static_cast <float>(area.width), static_cast <float>(area.height * -1)));
						if(player.getVelocity().x < 0 && player.getVelocity().y > 0)
							player.setPosition(player.getPosition() + sf::Vector2f(static_cast <float>(area.width), static_cast <float>(area.height * -1)));
						if(player.getVelocity().x < 0 && player.getVelocity().y < 0)
							player.setPosition(player.getPosition() + sf::Vector2f(static_cast <float>(area.width), static_cast <float>(area.height)));
					}
				}
			}
			
			if(sf::IntRect(i * 32, j * 32, 32, 32).contains(sf::Vector2i(rectplayer.left + 32, rectplayer.top + rectplayer.height + 2)) && (level.getPixel(i, j) == My::Color::Space || level.getPixel(i, j) == My::Color::Poison || level.getPixel(i, j) == My::Color::Gas))
				player.setInAir(true);
			else if(sf::IntRect(i * 32, j * 32, 32, 32).contains(sf::Vector2i(rectplayer.left + 32, rectplayer.top + rectplayer.height + 2)) && (level.getPixel(i, j) != My::Color::Space || level.getPixel(i, j) != My::Color::Poison || level.getPixel(i, j) != My::Color::Gas))
			{
				player.setInAir(false);
				player.changeJump();
			}
			if(player.getIntrect().contains(sf::Vector2i(i * 32 + 16, j * 32)) && level.getPixel(i,j) == My::Color::Ladder){
				player.setOnLadder(true);
				player.setInAir(false);

			}
			else if(player.getIntrect().contains(sf::Vector2i(i * 32 + 16, j * 32)) && level.getPixel(i,j) != My::Color::Ladder)
				player.setOnLadder(false);
		}
	}
	if(player.getO2() <= 0){
		player.setO2(0);
	}
	if(player.getHP() <= 0){
		player.setHP(0);
	}

	if(timer.getElapsedTime().asMilliseconds() > 50){
		timer.restart();

		if(gasCloud.checkIfInsideGas(static_cast <int>(player.getPosition().x+24), static_cast <int>(player.getPosition().y+35)) && sf::Mouse::isButtonPressed(sf::Mouse::Right) && static_cast <int>(player.getO2()) > 0 && player.getMoveState())
			player.setO2(player.getO2()-0.15f);
		else if(gasCloud.checkIfInsideGas(static_cast <int>(player.getPosition().x+24), static_cast <int>(player.getPosition().y+35)) && sf::Mouse::isButtonPressed(sf::Mouse::Right) && static_cast <int>(player.getO2()) > 0)
			player.setO2(player.getO2()-0.05f);
		else if(gasCloud.checkIfInsideGas(static_cast <int>(player.getPosition().x+24), static_cast <int>(player.getPosition().y+35)))
			player.setHP(player.getHP()-0.2f);
	}
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if(inv.checkIfPressed(mousePos.x,mousePos.y)>0){
			player.setActiveItem(inv.checkIfPressed(mousePos.x,mousePos.y));
		}
	}

	//std::cout << player.getActiveItem() << std::endl;


	if(player.getHP()<100 && iks.getStackSize()>0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)&&player.getCanMove()&&player.getActiveItem() == 3){

		castSprite.setScale(healCast.getElapsedTime().asMilliseconds()/16.5f, 2.f);
		if(healCast.getElapsedTime().asSeconds() > 2){
			healCast.restart();
			player.setHP(iks.useKit(player.getHP()));
			iks.deleteKit();
			castSprite.setScale(0,2);
		}
	}
	else{
		healCast.restart();
		castSprite.setScale(0,2);
	}

	if(player.getO2()<20 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && player.getCanMove() && player.getActiveItem() == 4){
		player.setO2(its.useTube(player.getO2()));
		if(its.getCurrentTubeO2()<=0)
			its.deleteTube();			
	}

	if(ks.checkIfTouchKit(player.getIntrect())){
		iks.addKit(new InventoryHealthKit());
	}
	if(ts.checkIfTouchTube(player.getIntrect())){
		its.addTube(new InventoryOxygenTube());
	}
}

void LevelEngine::draw(sf::RenderWindow& window)
{

	for(unsigned i = 0; i < level.getSize().x; i++)
	{
		for(unsigned j = 0; j < level.getSize().y; j++)
			tiles.draw(level.getPixel(i,j), sf::Vector2f(static_cast <float>(i * 32), static_cast <float>(j * 32)), window);
	}
}
