#pragma once
#include "MovingObject.h"
class Invader : public MovingObject
{
public:
	Invader(int playfieldX, int playfieldY, int initialPosX, int initialPosY);
	Invader();
	~Invader();
	void Move();
};

