#pragma once
enum DIRECTION { STOP = 0, LEFT, RIGHT, UP, DOWN };
class MovingObject
{
public:
	MovingObject(int playfieldX, int playfieldY, int initialPosX, int initialPosY, DIRECTION direction);
	MovingObject();
	virtual ~MovingObject();
	int posX, posY;
	DIRECTION moveDirection;
	bool active;
	virtual void Move();

protected:
	int boundaryX, boundaryY;
};

