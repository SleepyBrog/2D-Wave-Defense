#pragma once
#include <SFML/Graphics.hpp>

class Platform;
class Player;
class Enemy;

#define GRID_SIZE 32

class Entity
{
	sf::Color color;
public:
	float width, height, xPos, yPos;
	int isAlive;
	sf::RectangleShape shape;
	Entity(int, int, float, float, sf::Color);
	void AlignPos(void);
};

