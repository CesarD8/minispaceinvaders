#include "stdafx.h"
#include "Player.h"
#include "Invader.h"
#include <conio.h>

Player::Player(int playfieldX, int playfieldY, int initialPosX, int initialPosY) : 
	MovingObject(playfieldX, playfieldY, initialPosX, initialPosY, STOP)
{
	bullet = Bullet(playfieldX, playfieldY, initialPosX, initialPosY, UP);
	bullet.active = false;
}

Player::Player()
{
	boundaryX = boundaryY = posX = posY = 0 ;
}

Player::~Player()
{
}

/// <summary>
/// Checks for keystrokes for moving and shooting
/// </summary>
void Player::Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'A':
		case 'a':
			moveDirection = LEFT;
			break;
		case 'D':
		case 'd':
			moveDirection = RIGHT;
			break;
		case 'W' :
		case 'w' :
			if(!bullet.active)
				Shoot();
			break;
		}
	}
	else
	{
		moveDirection = STOP;
	}
}

/// <summary>
/// Moves the player depending on the current moveDirection
/// </summary>
void Player::Move()
{
	switch (moveDirection)
	{
	case LEFT:
		posX--;
		break;
	case RIGHT:
		posX++;
		break;
	default:
		break;
	}

	//Limiting the movement of the ship
	if (posX >= boundaryX) posX = boundaryX - 1;
	else if (posX < 0) posX = 0;
}

/// <summary>
/// Activates the bullet and sets the position above the player to avoid collisions
/// </summary>
void Player::Shoot()
{
	bullet.active = true;
	bullet.SetPosition(posX, posY - 1);	
}

/// <summary>
/// Calls the functions that should be executed every frame
/// </summary>
void Player::Update()
{
	if (bullet.active)
		bullet.Update();
	Input();
	Move();
}

/// <summary>
/// Checks for collisions with other enemies
/// </summary>
void Player::CheckCollision(Invader objects[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (objects[i].active && objects[i].posX == posX && objects[i].posY == posY)
		{
			isAlive = false;
			break;
		}
	}
}
