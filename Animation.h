#pragma once
#include <SFML\Graphics.hpp>

class Animation
{
public:
		 Animation();
        ~Animation();

        void Initialize(float x, float y, int FrameX, int FrameY,float delay);
        void Update(sf::RenderWindow &Window, bool moveState);
        void Draw(sf::RenderWindow &Window);

        bool getActive();
        void setActive(bool active);

        int getCurrentFrame(int axis);
        void setCurrentFrame(int axis, int value);

        float getPosition(int axis);
        void setPosition(int axis, int value);

        void setImage(sf::Image &tempImage);

        int getFrameWidth();
        int getFrameHeight();

		void setDelay(float delay);
private:
        sf::Sprite spriteImage;
		sf::Sprite sprite;
		sf::Texture textureImage;
        int currentFrameX, currentFrameY;
        float x, y;
        float frameCounter, switchFrame;
		float frameWidth, frameHeight;
        int amountOfFramesX, amountOfFramesY;
        bool active;
        sf::Clock Clock;
		sf::Time Time;
		float dt;
		float test;
		float delay;
};