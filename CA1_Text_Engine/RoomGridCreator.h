#pragma once
#include "RoomGrid.h"
#include "Vector2.h"

//Purpose: RoomGrid editor
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

static class RoomGridCreator {
public:
	RoomGridCreator();
	void in(const RoomGrid rg);
	RoomGrid out() const;
	void go(Vector2 pos);
	void go(int dir);
	void set(Room r);


private:
	RoomGrid editGrid;
	Vector2 currentPos;
	//Room* currentRoom;
	//int currentGrid;
	int gridSize;
	
};