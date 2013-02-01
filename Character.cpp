#include "Character.h"
#include "Animation.h"
#include <iostream>

Character::Character(float nX, float nY, sf::Image nSpriteChart){
  position.x = nX;
	position.y = nY;
	spriteChart = nSpriteChart;
	playerAnimation.Initialize(position.x,position.y,8,7, 100.00f);
	playerAnimation.setImage(spriteChart);
	
	armChart.loadFromFile("../Images/character_arms.png");
	fArm.setTexture(armChart);
	fArm.setTextureRect(sf::IntRect(0,0,32,32));
	fArm.setOrigin(10,5);

	bArm.setTexture(armChart);
	bArm.setTextureRect(sf::IntRect(0,64,32,32));
	bArm.setOrigin(10,5);

	velocity.x = 0;
	velocity.y = 0;
	HP = 100;
	O2 = 20;
	jump = true;
	onLadder = false;
	activeFrame.y = 0;
	canMove = true;
	isSprinting = false;
	activeItem = 0;
	faceLeft = false;
	faceRight = true;
	turnState = false;
	arm = false;
}


void Character::DrawPlayer(sf::RenderWindow &window){
	playerAnimation.setPosition(1, static_cast <int>(position.x));
    playerAnimation.setPosition(0, static_cast <int>(position.y));
	playerAnimation.setCurrentFrame(2, activeFrame.y);
	playerAnimation.Update(window,moveState);

	window.draw(bArm);
	playerAnimation.Draw(window);
	window.draw(fArm);
}

void Character::update(ljud& main_ljud){

	if(angle <= -50)
		arm = !arm;
	if(angle >= 50)
		arm = !arm;


	if(canMove){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			isSprinting = true;
			if(velocity.x != 0)
			{
				fArmOffset = sf::Vector2i(15, 80);
				bArmOffset = sf::Vector2i(43, 80);
			}
		}
		else
		{
			isSprinting = false;
			fArmOffset = sf::Vector2i(18, 80);
			bArmOffset = sf::Vector2i(46, 80);			
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&!faceLeft){
			if(!turnState)
				playerAnimation.setCurrentFrame(1,0);

			turnState = true;
			activeFrame.y = 5;
			moveState = true;
			playerAnimation.setDelay(40);
			if(playerAnimation.getCurrentFrame(1) == 7){
				faceLeft = true;
				faceRight = false;
				turnState = false;
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&!faceRight){
			if(!turnState)
				playerAnimation.setCurrentFrame(1,0);

			turnState = true;
			activeFrame.y = 6;
			moveState = true;
			playerAnimation.setDelay(40);
			if(playerAnimation.getCurrentFrame(1) == 7){
				faceRight = true;
				faceLeft = false;
				turnState = false;
			}
		}
		else
			turnState = false;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&faceLeft)
		{
			playerAnimation.setDelay(100);
			if(isSprinting){
				if(arm)
					angle -= 3;
				else
					angle += 3;				
				velocity.x = -3.5f * 1.5;
				activeFrame.y = 4;
				if (playerAnimation.getCurrentFrame(1) == 2 || playerAnimation.getCurrentFrame(1) == 6)
					main_ljud.PlaySound(0);
				
			}
			else{
				if(arm)
					angle -= 2;
				else
					angle += 2;	
				velocity.x = -3.5f;
				activeFrame.y = 1;
				if (playerAnimation.getCurrentFrame(1) == 1 || playerAnimation.getCurrentFrame(1) == 5)
					main_ljud.PlaySound(0);
			}
			moveState = true;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&faceRight)
		{
			playerAnimation.setDelay(100);
			if(isSprinting){
				if(arm)
					angle += 3;
				else
					angle -= 3;	
				velocity.x = 3.5f * 1.5;
				activeFrame.y = 3;
				if (playerAnimation.getCurrentFrame(1) == 2 || playerAnimation.getCurrentFrame(1) == 6)
					main_ljud.PlaySound(0);
			}
			else{
				if(arm)
					angle += 2;
				else		 
					angle -= 2;
				velocity.x = 3.5f;
				activeFrame.y = 0;
				if (playerAnimation.getCurrentFrame(1) == 1 || playerAnimation.getCurrentFrame(1) == 5)
					main_ljud.PlaySound(0);
			}
			moveState = true;
		}
		else
			velocity.x = 0;

		if(faceLeft)
		{
			fArmOffset.x = 64 - fArmOffset.x;
			bArmOffset.x = 64 - bArmOffset.x;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jump && !onLadder)
		{
			velocity.y = -15;
			jump = true;
			inAir = true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && onLadder)
		{
			playerAnimation.setDelay(300);
			velocity.y = -2.5;
			activeFrame.y = 2;
			moveState = true;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && onLadder)
		{
			playerAnimation.setDelay(300);
			velocity.y = 2.5;
			activeFrame.y = 2;
			moveState = true;
		}
		else if(!inAir)
			velocity.y = 0;

		if((velocity == sf::Vector2f(0,0) && !turnState) || jump){
			moveState = false;
			if(faceRight && !onLadder){
				playerAnimation.setCurrentFrame(1,0);
				activeFrame.y = 5;
			}
			else if(faceLeft && !onLadder){
				playerAnimation.setCurrentFrame(1,0);
				activeFrame.y = 6;
			}
		}
		if(inAir)
			velocity.y += 1;
		else
			jump = false;
		position += velocity;
	}
	fArm.setRotation(angle);
	bArm.setRotation(-angle);	
	fArm.setPosition(static_cast <int>(position.x + fArmOffset.x), static_cast <int>(position.y + fArmOffset.y));
	bArm.setPosition(static_cast <int>(position.x + bArmOffset.x), static_cast <int>(position.y + bArmOffset.y));
}

void Character::Interact(){
	
}

void Character::Jump(){

}

void Character::SprintJump(){
	
}


int Character::getClimbSpeed(){
	return climbSpeed;
}

float Character::getHP(){
	return HP;
}

float Character::getO2(){
	return O2;
}

sf::Vector2f Character::getPosition(){
	return position;
}

sf::Vector2f Character::getVelocity(){
	return velocity;
}

sf::IntRect Character::getIntrect(){
	intRect.height = spriteChart.getSize().y / 7;
	intRect.width = spriteChart.getSize().x / 8;
	intRect.left = static_cast <int>(position.x);
	intRect.top = static_cast <int>(position.y);

	return intRect;
}

bool Character::getOnLadder(){
	return onLadder;
}

void Character::setHP(float nHP){
	HP = nHP;
}

void Character::setO2(float nO2){
	O2 = nO2;
}

void Character::setItem(int nItem){
	activeItem = nItem;
}

void Character::setMoveState(bool nMoveState){
	moveState = nMoveState;
}

bool Character::getMoveState(){
	return moveState;
}

void Character::setVelocity(sf::Vector2f nVelocity){
	velocity = nVelocity;
}

void Character::setPosition(sf::Vector2f nPosition){
	position = nPosition;
	intRect.height = spriteChart.getSize().y / 7;
	intRect.width = spriteChart.getSize().x / 8;
	intRect.left = static_cast <int>(position.x);
	intRect.top = static_cast <int>(position.y);
	fArm.setPosition(static_cast <int>(position.x + fArmOffset.x), static_cast <int>(position.y + fArmOffset.y));
	bArm.setPosition(static_cast <int>(position.x + bArmOffset.x), static_cast <int>(position.y + bArmOffset.y));
}

void Character::setPosition(float x, float y){
	position.x = x;
	position.y = y;
}

void Character::setSpriteChart(sf::Image nSpriteChart){
	spriteChart = nSpriteChart;
}

void Character::setActiveItem(int item){
	activeItem = item;
}

void Character::setJump(bool state)
{
	jump = state;
}

void Character::setInAir(bool state)
{
	inAir = state;
}

void Character::setOnLadder(bool state){
	onLadder = state;
}

void Character::changeCanMove(){
	canMove = !canMove;
}

int Character::getActiveItem(){
	return activeItem;
}	

bool Character::getCanMove(){
	return canMove;
}
