#pragma once
#include "Entity.h"
#include "Platform.h"
#include "Player.h"

class Enemy :
	public Entity
{
	float accel, topSpeed, velX, velY, nextX, nextY, speedMultiplier, prevX, prevY, topXSpeed, topXAccel, topYSpeed, topYAccel;
	Entity * focus;
public:
	Enemy(int, int, float, float, float, float, Player *target);
	void Update(sf::RenderWindow &window);
	void Move();
	void PlatformCollisionCheck(Platform);
	void PlayerCollisionCheck(Player &player);
};

