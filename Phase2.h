#pragma once
#include "Ship.h"
#include "Obstacle.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Fuel.h"
#include "Wormholes.h"
#include "Vector2D.h"
#define MAX 500

class Phase2
{
	Obstacle* List[MAX];
	float x_eye, y_eye, z_eye;
	Ship *ship;
public:
	Phase2(){}
	virtual ~Phase2() {
		for (int i = 0;i < MAX;i++) delete List[i];
	}
	void Initialize(){
		srand(time(NULL));
		Vector2 aux = ship->GetPos();
		x_eye=aux.x;
		y_eye=300;
		z_eye=300;
		for(int i=0;i<MAX;i++){
			if(i<200)List[i]=new Asteroid();
			else if(200<=i&&i<300)List[i]=new Fuel();
			else if(300<=i&&i<400)List[i]=new Wormholes();
			else if(400<=i&&i<500)List[i]=new UFO();
		}
		
	}
	void Draw(){
		Vector2 aux;
		aux = ship->GetPos();
		gluLookAt(aux.x, y_eye, z_eye,  // posicion del ojo
		0.0, -90, 30,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/space1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1); 
		glTexCoord2d(0, 1);  glVertex3f(-300, -50, 500);
		glTexCoord2d(1, 1);  glVertex3f(-300, -50, -500);
		glTexCoord2d(1, 0);  glVertex3f(300, -50, -500);
		glTexCoord2d(0, 0);  glVertex3f(300, -50, 500);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		
		for(int i=0;i<MAX;i++)
			List[i]->Draw;
		ship->Draw;
	}
};

