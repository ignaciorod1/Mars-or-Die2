#define EARTH 1.6
#define MARS 0.8
#define VENUS 3.9
#define MERCURY 4.8

#include "World.h"
using ETSIDI::getTexture;

World::World() 
{ 
	ship = 0; 
}

World::~World() {delete ship; }

void World::Initialize() {

	sloMo = false;//slowmotion
	srand(time(NULL));

	x_eye = 0;
	y_eye = 400;
	z_eye = 400;
	//Inicializador del sol
	sun.SetColor(1.0F, 1.0F, 0);
	sun.SetRadius(20);
	//Se inicializa la tierra
	earth.SetIni(0.0F,0.0F,1.0F,8.5,210,EARTH);//4.5
	//Se inicializa marte
	mars.SetIni(1.0F,0.5F,0.0F,7,350,MARS);//3
	//Se inicializa mercurio
	mercury.SetIni(0.5F,0.0F,0.5F,6,30,MERCURY);//2
	//Se inicializa venus
	venus.SetIni(0.8F,0.5F,1.0F,6.8,60,VENUS);//2.8

	ETSIDI::playMusica("music/home_song.mp3", true);

}

void World::Draw() 
{
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
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

	sun.Draw("textures/Sun.png");
	mercury.Draw("textures/Mercury.png");
	earth.Draw("textures/Tierra.png");
	mars.Draw("textures/Mars.png");
	venus.Draw("textures/Venus.png");
	

	
	if (ship)
		ship->Draw();

}

void World::Timer() 
{		
	if (ship) {
		if (Interaction::ProximityOrbit(mars.GetPos(), ship->GetPos()))
			ship->SetOrbit(true);

		if (ship->GetOrbit())
			ship->OrbitAround(mars.GetPos()); // with this condition on you are able to pass to the next phase
		else
			ship->Move();
	}
	earth.Move();
	mercury.Move();
	mars.Move();
	venus.Move();
	
}

void World::Key(unsigned char key, int x_t, int y_t)
{
	if (key == ' ')
	{
		if (!sloMo)
		{
			sloMo = true;
			ship = new Ship;
			ship->SetPos(earth.GetPos());
			ship->SetOmega(earth.GetOmega());
			ship->GetAV(mars.GetPos());
			earth.SetOmega(EARTH * 0.1);
			mars.SetOmega(MARS * 0.1);
			venus.SetOmega(VENUS * 0.1);
			mercury.SetOmega(MERCURY * 0.1);
		}
		else
		{
			sloMo = false;
			earth.SetOmega(EARTH);
			mars.SetOmega(MARS);
			mercury.SetOmega(MERCURY);
			venus.SetOmega(VENUS);
			ship->SetT(2.5);
		}
	}
}