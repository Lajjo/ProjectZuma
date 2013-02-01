#pragma once

#include <SFML\Graphics.hpp>
#include "Game.h"

class GameMenu
{
public:
  GameMenu(void);
	~GameMenu(void);
	void run();
private:
	Game game;
	sf::Image image;
	sf::Texture headTexture;
	sf::Texture startTexture;
	sf::Texture highscoreTexture;
	sf::Texture exitTexture;
	sf::Sprite head;
	sf::Sprite start;
	sf::Sprite highscore;	
	sf::Sprite exit;
	sf::IntRect startRect;
	sf::IntRect highscoreRect;	
	sf::IntRect exitRect;

};
