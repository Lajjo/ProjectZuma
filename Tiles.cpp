#include "Tiles.h"
#include "Color.h"
#include <iostream>
#include "GasCloud.h"

Tiles::Tiles()
{
	tiles.loadFromFile("../Images/tilechart_wip_update.png");
	tiles.createMaskFromColor(sf::Color::White);
	texture.loadFromImage(tiles);
	sprite.setTexture(texture);
}

Tiles::~Tiles(){}

void Tiles::initialize(sf::Color color, sf::Vector2f position, GasCloud &gasCloud)
{
	if(color == My::Color::Gas)
	{
		sprite.setTextureRect(sf::IntRect(128, 160, 32, 32));
		gasCloud.addGas(new Gas(position, sprite));
	}
	if(color == My::Color::Poison)
	{
		sprite.setTextureRect(sf::IntRect(128, 160, 32, 32));
		gasCloud.addGas(new Gas(position, sprite));
	}
}

void Tiles::draw(sf::Color color, sf::Vector2f position, sf::RenderWindow& window)
{
	sprite.setPosition(position);
	
	if(color == My::Color::DirtUpLeftCorner)
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	else if(color == My::Color::DirtUpEdge)
		sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
	else if(color == My::Color::DirtUpRightCorner)
		sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
	else if(color == My::Color::DirtLeftEdge)
		sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
	else if(color == My::Color::Dirt)
		sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
	else if(color == My::Color::DirtRightEdge)
		sprite.setTextureRect(sf::IntRect(64, 32, 32, 32));
	else if(color == My::Color::DirtLowLeftCorner)
		sprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
	else if(color == My::Color::DirtDownEdge)
		sprite.setTextureRect(sf::IntRect(32, 64, 32, 32));
	else if(color == My::Color::DirtLowRightCorner)
		sprite.setTextureRect(sf::IntRect(64, 64, 32, 32));

	else if(color == My::Color::RockUpLeftCorner)
		sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
	else if(color == My::Color::RockUpEdge)
		sprite.setTextureRect(sf::IntRect(128, 0, 32, 32));
	else if(color == My::Color::RockUpRightCorner)
		sprite.setTextureRect(sf::IntRect(160, 0, 32, 32));
	else if(color == My::Color::RockLeftEdge)
		sprite.setTextureRect(sf::IntRect(96, 32, 32, 32));
	else if(color == My::Color::Rock)
		sprite.setTextureRect(sf::IntRect(128, 32, 32, 32));
	else if(color == My::Color::RockRightEdge)
		sprite.setTextureRect(sf::IntRect(160, 32, 32, 32));
	else if(color == My::Color::RockLowLeftCorner)
		sprite.setTextureRect(sf::IntRect(96, 64, 32, 32));
	else if(color == My::Color::RockDownEdge)
		sprite.setTextureRect(sf::IntRect(128, 64, 32, 32));
	else if(color == My::Color::RockLowRightCorner)
		sprite.setTextureRect(sf::IntRect(160, 64, 32, 32));

	else if(color == My::Color::WeakRockUpLeftCorner)
		sprite.setTextureRect(sf::IntRect(0, 96, 32, 32));
	else if(color == My::Color::WeakRockUpEdge)
		sprite.setTextureRect(sf::IntRect(32, 96, 32, 32));
	else if(color == My::Color::WeakRockUpRightCorner)
		sprite.setTextureRect(sf::IntRect(64, 96, 32, 32));
	else if(color == My::Color::WeakRockLeftEdge)
		sprite.setTextureRect(sf::IntRect(0, 128, 32, 32));
	else if(color == My::Color::WeakRock)
		sprite.setTextureRect(sf::IntRect(32, 128, 32, 32));
	else if(color == My::Color::WeakRockRightEdge)
		sprite.setTextureRect(sf::IntRect(64, 128, 32, 32));
	else if(color == My::Color::WeakRockLowLeftCorner)
		sprite.setTextureRect(sf::IntRect(0, 160, 32, 32));
	else if(color == My::Color::WeakRockDownEdge)
		sprite.setTextureRect(sf::IntRect(32, 160, 32, 32));
	else if(color == My::Color::WeakRockLowRightCorner)
		sprite.setTextureRect(sf::IntRect(64, 160, 32, 32));

	else if(color == My::Color::Ladder)
		sprite.setTextureRect(sf::IntRect(96, 96, 32, 32));
	else if(color == My::Color::Pillar)
		sprite.setTextureRect(sf::IntRect(128, 96, 32, 32));
	else if(color == My::Color::RopeBlock)
		sprite.setTextureRect(sf::IntRect(160, 96, 32, 32));
	else if(color == My::Color::Chest)
		sprite.setTextureRect(sf::IntRect(96, 128, 32, 32));
	else if(color == My::Color::DeathBlock)
		sprite.setTextureRect(sf::IntRect(128, 128, 32, 32));
	else if(color == My::Color::Door)
		sprite.setTextureRect(sf::IntRect(160, 128, 32, 32));
	else if(color == My::Color::Poison)
		sprite.setTextureRect(sf::IntRect(96, 160, 32, 32));
	else if(color == My::Color::Gas)
		sprite.setTextureRect(sf::IntRect(128, 160, 32, 32));
	if(color != My::Color::Space)
		window.draw(sprite);
}