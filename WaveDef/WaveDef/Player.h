#pragma once
#include "Entity.h"
class Player :
	public Entity
{
	int moveLeft, moveRight, moveUp, moveDown, moveSpeed;
public:
	Player();
	void Update();
	void CheckKeys();
	void Move();
};

