#include "stdafx.h"
#include "Invader.h"
#include <iostream>

Invader::Invader(int playfieldX, int playfieldY, int initialPosX, int initialPosY) :
	MovingObject(playfieldX, playfieldY, initialPosX, initialPosY, RIGHT)//, bulletPool(&pool)
{
}

Invader::Invader()
{
	boundaryX = boundaryY = posX = posY = 0;
	moveDirection = RIGHT;
}

Invader::~Invader()
{
}

/// <summary>
/// Moves the invader in the current moveDirection
/// </summary>
void Invader::Move()
{
	if (moveDirection == LEFT)
	{
		if (posX > 1)
		{
			posX--;
		}
		else
		{
			moveDirection = RIGHT;
		}
	}
	else if(moveDirection == RIGHT)
	{
		if (posX < boundaryX - 1)
		{
			posX++;
		}
		else
		{
			moveDirection = LEFT;
		}
	}
}



