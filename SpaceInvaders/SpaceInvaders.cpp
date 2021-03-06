// SpaceInvaders.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "Player.h"
#include "Invader.h"
#include "Utilities.h"
#include "ObjectPool.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <memory>

using namespace std;
bool gameOver;
const int width = 40;
const int height = 20;
Player player;
Invader invaders[30];
Invader *leftMost, *rightMost;
ObjectPool bulletPool;

/// <summary>
/// Initializes the elements of the game
/// </summary>
void Setup()
{
	gameOver = false;
	bulletPool = ObjectPool();
	bulletPool.PopulateBullets(width, height);
	
	player = Player(width, height, width / 2, height - 1);
	for (int i = 0; i < (int)SizeofArray(invaders); i++)
	{
		int xPos = (i * 2) - (i/10*10)*2;
		invaders[i] = Invader(width, height, xPos, i/10);
	}

	leftMost = &invaders[0];
	rightMost = &invaders[9];
}

/// <summary>
/// Detects the active enemy farthest to the left and to the right, so they can control the change in Y position
/// </summary>
void SetEdges()
{
	for (int i = 0; i < (int)SizeofArray(invaders); i++)
	{
		if (invaders[i].active)
		{
			if(!leftMost->active || invaders[i].posX < leftMost->posX)
				leftMost = &invaders[i];
			if (!rightMost->active || invaders[i].posX > rightMost->posX)
				rightMost = &invaders[i];
		}
	}
}

/// <summary>
/// Draws the current state of the playfield and its visible elements
/// </summary>
void Draw()
{
	system("cls"); 
	for (int i = 0; i < width + 2; i++)
		cout << "#";

	cout << endl;

	int invaderIndex = 0;
	int eBulletIndex = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			bool printed(false);
			//WALL DRAW
			if (j == 0)
			{
				cout << "#";
				printed = true;
			}
			else
			{
				//ENEMIES DRAW
				for (int k = invaderIndex; k < (int)SizeofArray(invaders); k++)
				{
					if(invaders[k].active)
						if (j == invaders[k].posX && i == invaders[k].posY)
						{
							cout << "M";
							invaderIndex++;
							printed = true;
							break;
						}
				}
				//PLAYER DRAW
				if (i == player.posY && j == player.posX)
				{
					cout << "A";
					printed = true;
				}
				//BULLET DRAW
				if (i == player.bullet.posY && j == player.bullet.posX && player.bullet.active)
				{
					cout << "^";
					printed = true;
				}
				//SPACE DRAW
				else if (!printed)
				{
					cout << " ";
				}
				//WALL DRAW
				if (j == width - 1)
					cout << "#";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
}

/// <summary>
/// Coordinates the movement of the enemies, so everyone is moving in the same direction
/// </summary>
void CoordinateEnemies()
{
	if (leftMost->posX <= 1)
		for (int i = 0; i < (int)SizeofArray(invaders); i++)
		{
			invaders[i].moveDirection = RIGHT;
			invaders[i].posY++;
		}
	else if (rightMost->posX >= width - 1)
		for (int i = 0; i < (int)SizeofArray(invaders); i++)
		{
			invaders[i].moveDirection = LEFT;
			invaders[i].posY++;
		}
}

/// <summary>
/// Detects collisions between the enemies, the player and the bullet
/// </summary>
void CheckCollisions()
{
	player.CheckCollision(invaders, SizeofArray(invaders));
	if (player.bullet.active)
		player.bullet.CheckCollision(invaders, (int)SizeofArray(invaders));
}

/// <summary>
/// Calls the functions that should be executed each frame, mostly for moving objects
/// </summary>
void Update()
{
	Draw();
	SetEdges();
	player.Update();

	if (!player.isAlive) gameOver = true;
	
	for (int i = 0; i < (int)SizeofArray(invaders); i++)
	{
		invaders[i].Move();
	}
	
	CoordinateEnemies();
	CheckCollisions();
}

/// <summary>
/// Calls to Update and the functions that dont have much to do with the behaviour of the moving objects
/// </summary>
int main()
{
	Setup();
	while (!gameOver)
	{
		Update();
		Sleep(20);
	}
	return 0;
}