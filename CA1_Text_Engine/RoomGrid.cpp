#include "RoomGrid.h"

RoomGrid::RoomGrid() 
{
}

RoomGrid::RoomGrid(Vector2 startPos) : startPos(startPos)
{
}

Vector2 RoomGrid::getPos(unsigned int dir) {
	Vector2 newPos = { -1,-1 };
	switch (dir) {
	case  0:
		// north
		newPos = { currentPos.x, currentPos.y - 1 };
		break;
	case 1:
		// east
		newPos = { currentPos.x + 1,currentPos.y };
		break;
	case 2:
		// south
		newPos = { currentPos.x,currentPos.y + 1 };
		break;
	case 3:
		// west
		newPos = { currentPos.x - 1,currentPos.y };
		break;
	default:
		break;
	}
	return newPos;
}

bool RoomGrid::check(unsigned int dir)
{
	Vector2 newPos = getPos(dir);
	// Error checks
	// Maybe we don't even need these two if statements?
	if (newPos.x < 0 || newPos.y < 0) {
		return false;
	}
	if (newPos.x >= size || newPos.y >= size) {
		return false;
	}
	if (grid[newPos.x][newPos.y].validRoom) {
		return true;
	}
	return false;
}

bool RoomGrid::go(unsigned int dir)
{
	if (check(dir)) {
		Vector2 newPos = getPos(dir);
		currentRoom = &grid[newPos.x][newPos.y];
		currentPos = newPos;
		return true;
	}
	return false;
}

void RoomGrid::print() const
{

}

void RoomGrid::initialize()
{
	currentRoom = &grid[startPos.x][startPos.y];
	currentPos = startPos;
}

