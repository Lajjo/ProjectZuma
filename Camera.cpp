#include "Camera.h"

Camera::Camera(sf::RenderWindow& window) :_window(window)
{
	camera.setSize(window.getSize().x,window.getSize().y);
	camera.setCenter(window.getSize().x/2,window.getSize().y/2);
}

Camera::~Camera()
{

}

void Camera::setPosition(sf::Vector2f position)
{
	vPosition = position;
}

sf::Vector2f Camera::getPosition()
{
	return vPosition;
}

void Camera::setCamera()
{
	_window.setView(camera);
}

sf::View Camera::getCamera()
{
	return camera;
}

void Camera::setCenter(sf::Vector2f center)
{
	camera.setCenter(center);
}
