#include "Room.h"
#include <iostream>

Room::Room() : GameObject("default_name", "default_description")
{
	validRoom = false;
}

Room::Room(std::string name, std::string description) : GameObject(name, description)
{
	validRoom = true;
}

Room::Room(InteractableList contents, std::string name, std::string description) : contents(contents), GameObject(name, description)
{
	validRoom = true;
	for (Interactable i : contents.getList()) {
		Room::validCommands[i.getName()] = (i.verbList);
	}
}

//Room::Room(InteractableList contents, std::string name, std::string description, Room* connectedRooms) : contents(contents), GameObject(name, description)
//{
//	setConnectedRooms(connectedRooms);
//}


Room::~Room()
{
}

bool Room::addItem(const Interactable &item)
{
	return contents.addItem(item);
}

bool Room::removeItem(const Interactable &item)
{
	return contents.removeItem(item);
}

bool Room::contains(Interactable& item)
{
	if (contents.contains(item)) {
		return true;
	}
	return false;
}

void Room::printCommands() const
{
	std::vector<std::string> stringVector;
	for(auto& iter : validCommands) {
		std::cout << iter.first << ": ";
		stringVector = iter.second;
		for (std::string s : stringVector) {
			std::cout << s << ", ";
		}
		std::cout << std::endl;
	}
}

void Room::print() const
{
	std::cout << "You are in " << getName() << ", " << getDescription() << ", you see a: " << std::endl;
	contents.printItems();
}
