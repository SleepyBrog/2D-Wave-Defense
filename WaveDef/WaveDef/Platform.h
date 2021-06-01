#pragma once
#include "Entity.h"
class Platform :
	public Entity
{
public:
	int solid;
	Platform(int, int, float, float, int);
};

