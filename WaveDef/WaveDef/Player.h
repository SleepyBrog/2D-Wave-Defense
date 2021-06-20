#pragma once
#include "Entity.h"

class Platform;
class Enemy;

class Player :
	public Entity
{
	int moveLeft, moveRight, moveUp, moveDown;
	float accel, topSpeed, velX, velY, nextX, nextY, speedMultiplier, prevX, prevY, maxHealth, currentHealth, hitInvulnerable, invulStartTime;
public:
	Player();
	void Update(sf::RenderWindow &window);
	void CheckKeys();
	void Move();
	void PlatformCollisionCheck(std::vector<Platform> &plats);
	void EnemyCollisionCheck(std::vector<Enemy> &enemies);
	void NeedsToDie(void);
	void CheckInvul(void);
};

