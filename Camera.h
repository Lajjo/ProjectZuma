#ifndef CAMERA_H
#define CAMERA_H

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

class Camera{
public:
	Camera(sf::RenderWindow& window);
	~Camera();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setCamera();
	void setCenter(sf::Vector2f position);
	sf::View getCamera();
private:
	sf::View camera;
	sf::RenderWindow& _window;
	sf::Vector2f vPosition;
};

#endif