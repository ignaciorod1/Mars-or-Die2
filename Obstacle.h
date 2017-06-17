#pragma once
#include "Sphere.h"
#include "MovingObject.h"
class Obstacle:public Sphere, public MovingObject
{
public:
	Obstacle(void);
	virtual ~Obstacle(void);
	void SetPos(float ix, float iy);
	void SetAcc(float ix, float iy);
};

