#include "Obstacle.h"


Obstacle::Obstacle(void)
{
}


Obstacle::~Obstacle(void)
{
}

void Obstacle::SetPos(float ix, float iy) {  // también se puede inicializar con la sobrecarga del constructor de vector
	position.x = ix;		     // Vector2(float x, float y) y en la definición se pondría SetPos(Vector2).
	position.y = iy;		     // En esta situación son más cómodos dos floats, though
}

void Obstacle::SetAcc(float ix, float iy) {
	acc.x = ix;
	acc.y = iy;
}
