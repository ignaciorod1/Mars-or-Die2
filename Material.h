#pragma once
#include "glut.h"

class Material
{
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;

public:

	Material();
	~Material();

	void SetAmbient(float a, float b, float c, float d);
	void SetDiffuse(float a, float b, float c, float d);
	//void SetSpecular(float a, float b, float c, float d);
	//void SetShininess(float a);

};

