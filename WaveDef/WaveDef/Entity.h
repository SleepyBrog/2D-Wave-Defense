#pragma once
#include <SFML/Graphics.hpp>
#define GRID_SIZE 32

class Entity
{
	sf::Color color;
public:
	float width, height, xPos, yPos;
	int needsToDie;
	sf::RectangleShape shape;
	Entity(int, int, float, float, sf::Color);
	void AlignPos(void);
};

