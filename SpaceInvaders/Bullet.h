#pragma once
#include "MovingObject.h"

class Bullet : public MovingObject
{
public:
	Bullet(int playfieldX, int playfieldY, int initialPosX, int initialPosY, DIRECTION direction);
	Bullet();
	~Bullet();
	void SetPosition(int x, int y);
	void CheckBoundaries();
	void Update();
	void CheckCollision(MovingObject objects[], int size);

};

