#include "GameMenu.h"
#include <iostream>


GameMenu::GameMenu()
{
  image.loadFromFile("../Images/menu_start.png");
	startTexture.loadFromImage(image);
	start.setTexture(startTexture);
	start.setPosition(630-128,400);
	startRect.left = 630-128;
	startRect.top = 400;
	startRect.height = 92;
	startRect.width = 256;
	
	image.loadFromFile("../Images/menu_highscore.png");
	highscoreTexture.loadFromImage(image);
	highscore.setTexture(highscoreTexture);
	highscore.setPosition(630-128,510);
	highscoreRect.left = 630-128;
	highscoreRect.top = 510;
	highscoreRect.height = 92;
	highscoreRect.width = 256;

	image.loadFromFile("../Images/menu_exit.png");
	exitTexture.loadFromImage(image);
	exit.setTexture(exitTexture);
	exit.setPosition(630-128,620);
	exitRect.left = 630-128;
	exitRect.top = 620;
	exitRect.height = 92;
	exitRect.width = 256;

	image.loadFromFile("../Images/projectZuma_small.png");
	headTexture.loadFromImage(image);
	head.setTexture(headTexture);
	head.setPosition(400,50);
	
}


GameMenu::~GameMenu()
{
}

void GameMenu::run(){
	//Lolzlorz
	
	sf::RenderWindow window(sf::VideoMode(1260,788),"Test");
	sf::Vector2i mouse;
	window.setFramerateLimit(60);
	bool quit = false;

	while(window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !quit)
	{
		mouse = sf::Mouse::getPosition(window);
		if(startRect.contains(mouse) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			game.run(window);
		if(highscoreRect.contains(mouse) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			
		if(exitRect.contains(mouse) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			quit = true;

		window.clear();
		window.draw(start);
		window.draw(highscore);
		window.draw(exit);
		window.draw(head);
		window.display();
	}
}
