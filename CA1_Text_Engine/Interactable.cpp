#include "Interactable.h"
#include <iostream>;

Interactable::Interactable() : GameObject("default_name", "default_description")
{
}

Interactable::Interactable(std::string name, std::string description, std::vector<std::string> verbList) : GameObject(name, description), verbList(verbList)
{
}

Interactable::~Interactable()
{
}

void Interactable::print() const
{
	std::cout << "	" << getName() << std::endl;
}

bool Interactable::operator==(Interactable other)
{
	if (getID() == other.getID()) {
		return true;
	}
	return false;
}

bool Interactable::operator!=(Interactable other)
{
	return !(operator==(other));
}

void Interactable::examine(Interactable item)
{
	std::cout << item.getDescription() << std::endl;
}