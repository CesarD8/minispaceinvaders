#include "stdafx.h"
#include "Bullet.h"
#include "Invader.h"
#include <memory>

Bullet::Bullet(int playfieldX, int playfieldY, int initialPosX, int initialPosY, DIRECTION direction) :
	MovingObject(playfieldX, playfieldY, initialPosX, initialPosY, direction)
{
	
}

Bullet::Bullet() : MovingObject(0, 0, 0, 0, UP)
{
}

Bullet::~Bullet()
{
}

/// <summary>
/// Sets the values of posX and posY
/// </summary>
void Bullet::SetPosition(int x, int y)
{
	posX = x;
	posY = y;
}

/// <summary>
/// Checks if the bullet is inside the playfield, if not, it deactivates the bullet
/// </summary>
void Bullet::CheckBoundaries()
{
	if (posX <= 0 || posX >= boundaryX || posY <= 0 || posY >= boundaryY)
		active = false;
}

/// <summary>
/// Calls to the function that should execute each frame
/// </summary>
void Bullet::Update()
{
	Move();
	CheckBoundaries();
}

/// <summary>
/// Checks for collisions with other movingObjects, if there is one, it deactivates the objects involved
/// </summary>
void Bullet::CheckCollision(MovingObject objects[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (objects[i].active && objects[i].posX == posX && objects[i].posY == posY)
		{
			active = false;
			objects[i].active = false;
			break;
		}
	}
}


