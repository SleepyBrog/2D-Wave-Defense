#pragma once
#include "Entity.h"

class Player;
class Enemy;

class Platform :
	public Entity
{
public:
	int passthrough;
	Platform(int, int, float, float, int);
};

