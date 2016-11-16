#include "Door.h"

//Purpose: A lockable connection between rooms
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

Door::Door(std::string name, std::string description, bool locked, int dir) : StaticInteractable(name, description), locked(locked), dir(dir)
{
}

Door::Door()
{
}

Door::~Door()
{
}

void Door::unlock()
{
	locked = false;
}
