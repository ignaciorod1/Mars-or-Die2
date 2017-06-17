#pragma once
#include "Obstacle.h"
#include "ETSIDI.h"
class Asteroid:public Obstacle
{
public:
	Asteroid(void);
	virtual ~Asteroid(void);
	void Draw();
};

