#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "ljud.h"

class Character /*: public ActiveEntity*/ {

public:
  Character(float x, float y,sf::Image spriteChart);
	void DrawPlayer(sf::RenderWindow &window);
	void Jump();
	void SprintJump();
	void UseItem();
	void Interact();
	void update(ljud& main_ljud);
	int getClimbSpeed();
	float getHP();
	float getO2();
	bool getOnLadder();
	bool getMoveState();
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	sf::IntRect getIntrect();
	void setVelocity(sf::Vector2f Velocity);
	void setPosition(sf::Vector2f Position);
	void setPosition(float x, float y);
	void setHP(float HP);
	void setO2(float O2);
	void setItem(int item);
	void setMoveState(bool state);
	void setSpriteChart(sf::Image Spritechart);
	void setActiveItem(int item);
	void setJump(bool state);
	void setInAir(bool state);
	void setOnLadder(bool state);
	void changeCanMove();
	int getActiveItem();
	bool getCanMove();

private:
	sf::Vector2f velocity;
	sf::Vector2i activeFrame;
	sf::Image spriteChart;
	sf::Texture armChart;
	sf::Sprite fArm;
	sf::Sprite bArm;
	sf::Vector2f position; 
	sf::IntRect intRect;
	sf::Clock turnTimer;
	float HP;
	float O2;
	float angle;
	sf::Vector2i fArmOffset;
	sf::Vector2i bArmOffset;
	int activeItem;
	int climbSpeed;
	bool arm;
	bool moveState;
	bool isSprinting;
	bool jump;
	bool inAir;
	bool onLadder;
	bool canMove;
	bool faceLeft;
	bool faceRight;
	bool turnState;
	Animation playerAnimation;
	
};


#endif
