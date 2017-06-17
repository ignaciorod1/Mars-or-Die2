#include "Obstacle.h"


Obstacle::Obstacle(void)
{
}


Obstacle::~Obstacle(void)
{
}

void Obstacle::SetPos(float ix, float iy) {
	position.x = ix;
	position.y = iy;
}

void Obstacle::SetAcc(float ix, float iy) {
	acc.x = ix;
	acc.y = iy;
}
