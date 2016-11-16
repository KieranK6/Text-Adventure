/**
*	Door only blocks passage to another room
*		locked:		whether the door is locked or not
*		dir:		a door can be on one of the 4 walls of the room	
*
*		unlock():	unlocks the door allowing passage
**/
//Purpose: A lockable connection between rooms
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

#pragma once
#include "StaticInteractable.h"
class Door : public StaticInteractable {
public:
	Door(std::string name, std::string description, bool locked, int dir);
	Door();
	~Door();

	bool locked;
	int dir;

	void unlock();

private:
};