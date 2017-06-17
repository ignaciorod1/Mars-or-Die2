#include "Fuel.h"
#define MAX_X 300
#define MAX_Y 400
#define MAX_R 20
#define MAX_A 1

Fuel::Fuel(void)
{
	SetRadius(MAX_R);//Valor random de tamaño entre 0 y 20
	SetPos(rand() % MAX_X, rand() % MAX_Y);
	SetAcc(rand() % MAX_A, rand() % MAX_A);
}


Fuel::~Fuel(void)
{
}
void Fuel::Draw() {
	Sphere::Draw("textures/Fuel.png");
}
