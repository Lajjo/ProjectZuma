#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <sstream>
#include <iostream>
#include "Game.h"
#include "Character.h"
#include "GasCloud.h"
#include "DeathWall.h"
#include "InventoryTubeStack.h"
#include "InventoryKitStack.h"
#include "KitStack.h"
#include "TubeStack.h"
#include "LevelEngine.h"
#include "Inventory.h"
#include "Camera.h"

void Game::run(sf::RenderWindow& Window)
{
  sf::Font font;
	sf::Text life;
	sf::Text O2;
	sf::Image playerImage;
	sf::Image sprites;
	sf::Image UI;
	sf::Image pillarImage;
	sf::Texture hpBar;
	sf::Texture O2Bar;
	sf::Texture castBar;
	sf::Texture healthKit;
	sf::Texture oxygenTube;
	sf::Texture UIHP;
	sf::Texture UIO2;
	sf::Texture empty;
	sf::Sprite hpBarSprite;
	sf::Sprite O2BarSprite;
	sf::Sprite castBarSprite;
	sf::Sprite healthKitSprite;
	sf::Sprite oxygenTubeSprite;
	sf::Sprite UISpriteHP;
	sf::Sprite UISpriteO2;
	sf::Sprite activeItemSprite;
	sf::Clock timer;
	sf::Clock healCast;
	sf::Clock physicsLimit;
	sf::Vector2i mouse;

	float skippedTime;

	castBar.loadFromFile("../Images/Cast_bar.png");
	castBarSprite.setPosition(512-30,500);

	playerImage.loadFromFile("../Images/character_animation.png");
	hpBar.loadFromFile("../Images/HP_bar.png");
	O2Bar.loadFromFile("../Images/Syre_bar.png");
	castBar.loadFromFile("../Images/Cast_bar.png");
	if(!healthKit.loadFromFile("../Images/healthkit.png"))
		std::cout << "fail" << std::endl;


	hpBarSprite.setTexture(hpBar);
	O2BarSprite.setTexture(O2Bar);
	castBarSprite.setTexture(castBar);
	healthKitSprite.setTexture(healthKit);

	Character player(100,100,playerImage);
	GasCloud cloud;
	DeathWall dw;
	InventoryTubeStack its;
	InventoryKitStack iks;
	KitStack ks;
	TubeStack ts;
	LevelEngine level(cloud, castBarSprite);
	Inventory inv;
	int camX, camY;
	Camera cam(Window);


	bool hitDeathBlock = false;

	sprites.loadFromFile("../Images/healthkit.png");
	sprites.createMaskFromColor(sf::Color::White);
	healthKit.loadFromImage(sprites);
	healthKitSprite.setTexture(healthKit);

	sprites.loadFromFile("../Images/empty.png");
	sprites.createMaskFromColor(sf::Color::White);
	empty.loadFromImage(sprites);

	UI.loadFromFile("../Images/UI_Oxygen.png");
	UI.createMaskFromColor(sf::Color::White);
	UIO2.loadFromImage(UI);
	UISpriteO2.setTexture(UIO2);

	UI.loadFromFile("../Images/UI_HP-item.png");
	UI.createMaskFromColor(sf::Color::White);
	UIHP.loadFromImage(UI);
	UISpriteHP.setTexture(UIHP);

	sprites.loadFromFile("../Images/oxygentube.png");
	sprites.createMaskFromColor(sf::Color::White);
	oxygenTube.loadFromImage(sprites);
	oxygenTubeSprite.setTexture(oxygenTube);

	UISpriteHP.setPosition(434,-2);
	UISpriteO2.setPosition(443,740);
	activeItemSprite.setPosition(610,45);
	

	its.addTube(new InventoryOxygenTube());

	iks.addKit(new InventoryHealthKit());

	ks.addHealthKit(new HealthKit(300,300,healthKitSprite));

	ts.addOxygenTube(new OxygenTube(500,300,oxygenTubeSprite));


	timer.restart();
	physicsLimit.restart();
	bool keypressed = false;
	while(Window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{


		sf::Event Event;
		while(Window.pollEvent(Event) )
		{
			if(Event.type == sf::Event::Closed)
				Window.close();

			if(Event.type == sf::Event::KeyPressed){
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
					inv.changeIsOpen();
					player.changeCanMove();
				}
			}
		}
		mouse = sf::Mouse::getPosition(Window) + static_cast <sf::Vector2i>(Window.getView().getCenter()) - sf::Vector2i(Window.getSize().x * 0.5, Window.getSize().y * 0.5);

		if(player.getActiveItem() == 3){
			activeItemSprite.setTexture(healthKit);
		}
		else if(player.getActiveItem() == 4){
			activeItemSprite.setTexture(oxygenTube);
		}
		else
			activeItemSprite.setTexture(empty);

		if(player.getHP() <= 0){
			player.setHP(0);
		}

		if(dw.checkIfHitDeathBlock(player.getIntrect())){
			player.setHP(100);
			player.setPosition(sf::Vector2f(200,200));
		}

		hpBarSprite.setScale(player.getHP()*2.98,.9);
		O2BarSprite.setScale(player.getO2()*14.9,.9);

		

		
		const double elapsedTime = physicsLimit.restart().asMicroseconds() / 1000.;
		skippedTime += elapsedTime;

		while (skippedTime > 80) {
			player.update();
			level.update(player,ks,ts,its,iks,inv,mouse);
			
			inv.update(sf::Vector2f(static_cast<int>(player.getPosition().x+32-630),static_cast<int>(player.getPosition().y+64-394)));
			hpBarSprite.setPosition(static_cast<int>(player.getPosition().x+32-630+475),static_cast<int>(player.getPosition().y+64-394+12));
			O2BarSprite.setPosition(static_cast<int>(player.getPosition().x+32-630+483),static_cast<int>(player.getPosition().y+64-394+763));
			UISpriteHP.setPosition(static_cast<int>(player.getPosition().x+32-630+434),static_cast<int>(player.getPosition().y+64-394-2));
			UISpriteO2.setPosition(static_cast<int>(player.getPosition().x+32-630+443),static_cast<int>(player.getPosition().y+64-394+740));
			activeItemSprite.setPosition(player.getPosition().x+32-630+610,player.getPosition().y+64-394+45);
			skippedTime -= 15;
		}
		camX = static_cast<int>(player.getPosition().x+32);
		camY = static_cast<int>(player.getPosition().y+64);
		cam.setCenter(sf::Vector2f(camX,camY));
		Window.setView(cam.getCamera());
		Window.clear();
		level.draw(Window);
		
		player.DrawPlayer(Window);
		cloud.drawCloud(Window);
		//dw.drawDeathWall(Window);	
		Window.draw(castBarSprite);
		ks.drawStack(Window);
		ts.drawStack(Window);
		inv.drawInventory(Window);
		Window.draw(UISpriteHP);
		Window.draw(UISpriteO2);
		Window.draw(hpBarSprite);
		Window.draw(O2BarSprite);
		Window.draw(activeItemSprite);
		
		Window.display();

	}	
}
