#pragma once
#include "MovingObject.h"
#include "Invader.h"
#include "Bullet.h"

class Player : public  MovingObject
{
public:
	Player(int playfieldX, int playfieldY, int initialPosX, int initialPosY);
	Player();
	~Player();
	Bullet bullet;
	void Input();
	void Move();
	void Update();
	void Shoot();
	void CheckCollision(Invader objects[], int size);
	bool isAlive;
};

