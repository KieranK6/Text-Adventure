#include "ItemInteractable.h"
#include <iostream>

ItemInteractable::ItemInteractable() : Interactable("default_name", "default_description", std::vector<std::string>{})
{
	//setupVerbs();
}

ItemInteractable::ItemInteractable(std::string name, std::string description) : Interactable(name, description, std::vector<std::string>{"take", "drop", "examine"})
{
	// unnecessary unless Interactable has verbs of its own
	//setupVerbs();
}


ItemInteractable::~ItemInteractable()
{
}

void ItemInteractable::print() const
{
	Interactable::print();
}

bool ItemInteractable::operator==(ItemInteractable other)
{
	return false;
}

bool ItemInteractable::operator!=(ItemInteractable other)
{
	return false;
}

void ItemInteractable::take(ItemInteractable item)
{
	std::cout << "You pick up the " << item.getName() << std::endl;
}

void ItemInteractable::drop(ItemInteractable item)
{
	std::cout << "You drop the " << item.getName() << std::endl;
}

void ItemInteractable::examine(ItemInteractable item)
{
	Interactable::examine(item);
}

void ItemInteractable::setupVerbs()
{
	Interactable::verbList.push_back("take");
	Interactable::verbList.push_back("drop");
	Interactable::verbList.push_back("examine");
}

