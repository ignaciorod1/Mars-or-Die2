#pragma once
#include "World.h"
#include "Phase2.h"

class Coordinator
{
	World world;
	enum State{HOME, FIRST_PHASE, FIRST_PHASE_DONE, GAME_OVER};
	State state;
	Phase2 world2;

public:

	void Draw();
	void Timer();
	void Key(unsigned char key, int x_t, int y_t);

	Coordinator();
	virtual ~Coordinator();
};

