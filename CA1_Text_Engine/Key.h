#pragma once
#include "ItemInteractable.h"
#include "Door.h"

/**
*	Key is used for unlocking a particular door
*		door:		pointer to a particular door associated with this key
**/

//Purpose: To unlock door
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

class Key : public ItemInteractable{
public:
	Key(std::string name, std::string description, Door* door);
	Key();
	~Key();


private:
	Door* door;
};