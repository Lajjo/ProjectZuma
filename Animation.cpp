#include "Animation.h"
#include <iostream>
Animation::Animation()
 {

 }
Animation::~Animation()
 {

 }

void Animation::Initialize(float nx, float ny, int frameX, int frameY, float nDelay)
 {
	 frameCounter = 0;
	 active = false;
	 x = nx;
	 y = ny;
	 amountOfFramesX = frameX;
	 amountOfFramesY = frameY;
	 currentFrameX = currentFrameY = 0;
	 float frameWidth =  0;
	 float frameHeight = 0;
	 delay = nDelay;
	 test = 0;
 }

void Animation::Update(sf::RenderWindow &Window, bool moveState)
{
	//hanterar animationens flytt av frameX så rätt bild del av bilden används.
	if(moveState)
	{
		if(Clock.getElapsedTime().asMilliseconds()>delay)
		{
			Clock.restart();
			test = 0;
			currentFrameX += 1;
		}
	}
	else
       currentFrameX = 0;

	//vi vill inte rita ut inkorrekta frames så om currentFrameX är större än antalgen frame i texturen så startar vi om räknaren.
	if(currentFrameX >= amountOfFramesX)
		currentFrameX = 0;
	//skär texturen så vi befinner oss på rätt plats innom texturen.
	spriteImage.setTextureRect(sf::IntRect(currentFrameX * getFrameWidth(), currentFrameY * getFrameHeight(), getFrameWidth(), getFrameHeight() ));
	//Sätter posistionen av spriten.
	spriteImage.setPosition(x, y);
	
}
//utritning av vår sprite.
void Animation::Draw(sf::RenderWindow &Window)
 {
	 Window.draw(spriteImage);
 }

bool Animation::getActive()
 {
    return active;
 }

void Animation::setActive(bool value)
 {
    active = value;
 }

int	Animation::getCurrentFrame(int axis)
 {
    if(axis == 1)
        return currentFrameX;
    else
        return currentFrameY;
 }
void Animation::setCurrentFrame(int axis, int value)
 {
    if(axis == 1)
        currentFrameX = value;
    else
        currentFrameY = value;
 }

float Animation::getPosition(int axis)
 {
	if(axis == 1)
        return x;
    else
        return y;
 }
void Animation::setPosition(int axis, int value)
 {
    if(axis == 1)
        x = static_cast <float>(value);
    else
        y = static_cast <float>(value);
 }
//Init för texturen och spriten och variablerna för varje frames storlek.
void Animation::setImage(sf::Image &tempImage)
 {
	 textureImage.loadFromImage(tempImage);
	 spriteImage.setTexture(textureImage);
	 frameWidth = spriteImage.getGlobalBounds().width/amountOfFramesX;
	 frameHeight = spriteImage.getGlobalBounds().height/amountOfFramesY;
 }

int Animation::getFrameWidth()
 {
	return static_cast <int>(frameWidth);
 }
int Animation::getFrameHeight()
 {
	return static_cast <int>(frameHeight);
 }

void Animation::setDelay(float nDelay){
	delay = nDelay;
}
