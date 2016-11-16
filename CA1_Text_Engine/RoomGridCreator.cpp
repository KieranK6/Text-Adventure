#include "RoomGridCreator.h"

RoomGridCreator::RoomGridCreator() 
{
}

void RoomGridCreator::in(RoomGrid rg)
{
	editGrid = rg;
}

RoomGrid RoomGridCreator::out() const
{
	return editGrid;
}

void RoomGridCreator::go(Vector2 pos)
{
	//currentGrid = (pos.y*gridSize) - gridSize + pos.x;
	currentPos = pos;
	//currentRoom = editGrid.getGrid()[pos.x][pos.y];
}

void RoomGridCreator::go(int dir)
{
	switch (dir) {
		// must check if goes out of bounds!
		case  0:
			// north
			currentPos = { currentPos.x, currentPos.y - 1 };
			go(currentPos);
		break;
		case 1:
			// east
			currentPos = { currentPos.x + 1,currentPos.y };
			go(currentPos);
		break;
		case 2:
			// south
			currentPos = { currentPos.x,currentPos.y + 1 };
			go(currentPos);
		break;
		case 3:
			// west
			currentPos = { currentPos.x-1,currentPos.y};
			go(currentPos);
		break;
		default:
			std::cout << "Incorrect direction";
		break;
	}
}

void RoomGridCreator::set(Room r)
{
	editGrid.getGrid()[currentPos.x][currentPos.y] = r;
}
