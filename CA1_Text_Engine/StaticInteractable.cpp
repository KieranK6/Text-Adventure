#include "StaticInteractable.h"
#include <iostream>

StaticInteractable::StaticInteractable() : Interactable("default_name", "default_description", std::vector<std::string>{})
{
}

StaticInteractable::StaticInteractable(std::string name, std::string description) : Interactable(name, description, std::vector<std::string>{"take", "examine"})
{
}


StaticInteractable::~StaticInteractable()
{
}

bool StaticInteractable::operator==(StaticInteractable other)
{
	return false;
}

bool StaticInteractable::operator!=(StaticInteractable other)
{
	return false;
}

void StaticInteractable::setupVerbs()
{
}

void StaticInteractable::take(StaticInteractable item)
{
	std::cout << "You cannot fit the " << item.getName() << " in your inventory!" << std::endl;
}

void StaticInteractable::examine(StaticInteractable item)
{
	Interactable::examine(item);
}
