#pragma once
#include "Entity.h"
#include "Platform.h"
class Player :
	public Entity
{
	int moveLeft, moveRight, moveUp, moveDown;
	float accel, topSpeed, velX, velY, nextX, nextY, speedMultiplier, prevX, prevY;
public:
	Player();
	void Update(sf::RenderWindow &window);
	void CheckKeys();
	void Move();
	void PlatformCollisionCheck(Platform);
};

