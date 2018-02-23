#include "stdafx.h"
#include "MovingObject.h"

MovingObject::MovingObject(int playfieldX, int playfieldY, int initialPosX, int initialPosY, DIRECTION direction) : 
	boundaryX(playfieldX), boundaryY(playfieldY), posX(initialPosX), posY(initialPosY), moveDirection(direction), active(true)
{
}

MovingObject::MovingObject()
{
	boundaryX = 0;
	boundaryY = 0;
	posX = 0;
	posY = 0;
	moveDirection = STOP;
	active = false;
}

MovingObject::~MovingObject()
{
}

/// <summary>
/// Default Move function
/// </summary>
 void MovingObject::Move()
{
	switch (moveDirection)
	{
	case LEFT:
		posX--;
		break;
	case RIGHT:
		posX++;
		break;
	case DOWN:
		posY++;
		break;
	case UP:
		posY--;
		break;
	default:
		break;
	}
}

