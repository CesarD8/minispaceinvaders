#include "stdafx.h"
#include "ObjectPool.h"
#include "Utilities.h"

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}

/// <summary>
/// Creates the bullets
/// </summary>
void ObjectPool::PopulateBullets(int playfieldX, int playfieldY)
{
	for (auto i = 0; i < (int)SizeofArray(bullets); i++)
	{
		bullets[i] = Bullet(playfieldX, playfieldY, 0, 0, DOWN);
		bullets[i].active = false;
	}
}

/// <summary>
/// If there is a bullet available, it returns a pointer to it, else it returns null
/// </summary>
Bullet* ObjectPool::GetBullet()
{
	for (int i = 0; i <  (int)SizeofArray(bullets); i++)
	{
		if (!bullets[i].active)
			return &bullets[i];
	}
	return nullptr;
}

/// <summary>
/// Calls Update on the bullets
/// </summary>
void ObjectPool::Update()
{
	for (int i = 0; i < (int)SizeofArray(bullets); i++)
	{
		bullets[i].Update();
	}
}


