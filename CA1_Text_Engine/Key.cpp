#include "Key.h"

//Purpose: To unlock door
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

Key::Key(std::string name, std::string description, Door* door) : ItemInteractable(name, description), door(door)
{
}

Key::Key()
{
}

Key::~Key()
{
}
