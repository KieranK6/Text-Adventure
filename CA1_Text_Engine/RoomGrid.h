#pragma once
#include "Room.h"
#include "Vector2.h"
#include <array>

//Purpose: A grid of rooms
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

class RoomGrid {
public:
	RoomGrid();
	RoomGrid(Vector2 startRoom);
	
	const static int size = 5;
	typedef std::array<std::array<Room, size>, size> Grid;

	Vector2 startPos;
	Room* currentRoom;
	Vector2 currentPos;

	bool go(unsigned int dir);
	bool check(unsigned int dir);
	Vector2 getPos(unsigned int dir);
	void print() const;
	void initialize();

	// cant use 
	// const Room *getGrid() const { return grid; }
	// to return multidimensional array
	Grid& getGrid() {
		return grid;
	}
	
	
private:
	Grid grid;
};