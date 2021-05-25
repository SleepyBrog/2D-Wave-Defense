#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
	int width, height, xPos, yPos;
	sf::Color color;
public:
	sf::RectangleShape shape;
	Entity(int, int, int, int, sf::Color);
};

