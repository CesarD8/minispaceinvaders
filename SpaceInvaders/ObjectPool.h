#pragma once
#include "Bullet.h"

class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();
	void PopulateBullets(int playfieldX, int playfieldY);
	void Update();
	Bullet* GetBullet();
	Bullet bullets[3];
};

