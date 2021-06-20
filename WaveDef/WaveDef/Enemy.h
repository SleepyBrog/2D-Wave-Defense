#pragma once
#include "Entity.h"
#include "Platform.h"
class Player;

class Enemy :
	public Entity
{
	float accel, topSpeed, nextX, nextY, speedMultiplier, prevX, prevY, topXSpeed, topYSpeed, maxHealth, currentHealth;
	Player * focus;
public:
	float velX, velY, attackDamage;
	Enemy(int, int, float, float, float, float, Player *target);
	void Update(sf::RenderWindow &window);
	void Move();
	void PlatformCollisionCheck(std::vector<Platform> &plats);
};

