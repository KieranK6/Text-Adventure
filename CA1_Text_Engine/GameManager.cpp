#include "GameManager.h"
#include "GenericMap.h"
#include "Interactable.h"
#include "Note.h"
#include <map>

//Purpose: Handles game input and output (Player interaction)
//Author: Arnas and Kieran
//Version: 1.0
//Bugs: None known
//TODO: none

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::initialize() {
	initializeReferences();
	grid.initialize();
	room = *grid.currentRoom;
	std::cout << "You find yourself in ";
	describeRoom();
}
void GameManager::initializeReferences() {
	std::string name, type;
	for (auto iter : interactableMap.map) {
		name = iter.first;
		type = "Interactable";
		addItemReference(name, type);
	}
	for (auto iter : staticMap.map) {
		name = iter.first;
		type = "Static";
		addItemReference(name, type);
	}
	for (auto iter : doorMap.map) {
		name = iter.first;
		type = "Door";
		itemReferenceMap.add(name, type);
	}
	for (auto iter : keyMap.map) {
		name = iter.first;
		type = "Key";
		itemReferenceMap.add(name, type);
	}
	for (auto iter : noteMap.map) {
		name = iter.first;
		type = "Note";
		addItemReference(name, type);
	}
	for (auto iter : npcMap.map) {
		name = iter.first;
		type = "NPC";
		addItemReference(name, type);
	}
}

void GameManager::addItemReference(std::string name, std::string type) {
	itemReferenceMap.add(name, type);
}
void GameManager::describeRoom()
{
	std::string outString = "You see an opening to the ";

	room.print();


	if (grid.check(0)) {
		outString  += "north, ";
	}
	if (grid.check(1)) {
		outString += "east, ";
	}
	if (grid.check(2)) {
		outString += "south, ";
	}
	if (grid.check(3)) {
		outString +=  "west, ";
	}

	std::cout << outString << std::endl;
}

bool GameManager::takeItem(const Interactable &item)
{
	return (player.take(item) && room.removeItem(item));
}

bool GameManager::dropItem(const Interactable &item)
{
	return (player.drop(item) && room.addItem(item));
}

/**
*	Takes user input and determines an action from that
**/

void GameManager::takeInput()
{

	std::vector<std::string> commandVector = actionParser.takeInput();

	std::string noun = commandVector[0];
	std::string verb = commandVector[1];

	//std::cout << "Verb: " << verb << std::endl;
	//std::cout << "Noun: " << noun << std::endl;

	if (verb == "go" || verb == "move") {
		int dir = -1;
		std::string textDir;
		if (noun == "north") {
			dir = 0;
			textDir = noun;
		}
		if (noun == "east") {
			dir = 1;
			textDir = noun;
		}
		if (noun == "south") {
			dir = 2;
			textDir = noun;
		}
		if (noun == "west") {
			dir = 3;
			textDir = noun;
		}

		if (move(dir)) {
			std::cout << "You go "<< noun <<"!" << std::endl;
			describeRoom();
		}
		else {
			std::cout << "You can't go that way!" << std::endl;
		}
		
	}
	else if (verb == "describe")
	{
		describeRoom();
	}
	else {
		if (itemReferenceMap.contains(noun)) {
			Interactable item = interactableMap.get(noun);
			std::string type = itemReferenceMap.get(noun);

			if (isAvailable(item))
			{
				if (verb == "get" || verb == "pickup" || verb == "take")
				{
					if (room.contains(item)) {
						if (type == "Static")
						{
							std::cout << "You can't fit that in your inventory!" << std::endl;
						}
						else
						{
							takeItem(item);
							std::cout << "You pick up the " << item.getName() << std::endl;
						}
					}
				}
				else if (verb == "drop" || verb == "remove") {
					if (playerHas(item)) {
						dropItem(item);
						std::cout << "You drop the " << item.getName() << std::endl;
					}
					else {
						std::cout << "You don't have that!" <<  std::endl;
					}
				}
				else if (verb == "examine")
				{
					std::cout << item.getDescription() << std::endl;
				}
				else if (verb == "read")
				{
					if (type == "Note")
					{
						Note note = noteMap.get(noun);
						note.read();
					}
					else
					{
						std::cout << "You can't read that!" << std::endl;
					}
				}
				else if (verb == "open" || verb == "unlock")
				{
					if (type == "Door")
					{
						Door door = doorMap.get(noun);
						if (door.locked == true)
						{
							std::cout << "Unlock door" << std::endl;
						}
						else
						{
							std::cout << "The " << door.getName() << " is already open!" << std::endl;
						}
					}
					else
					{
						std::cout << "You can't open that!" << std::endl;
					}

				}
				else if (verb == "talk")
				{
					if (type == "NPC") {
						NPC npc = npcMap.get(noun);
						npc.talkTo();
					}
					else
					{
						std::cout << "You can't talk to that!" << std::endl;
					}
				}
			}
			else
			{
				std::cout << "No such item found!" << std::endl;
			}
		}
	}
}

bool GameManager::isAvailable(Interactable item) {
	if (room.contains(item) || playerHas(item)) {
		return true;
	}
	return false;
}

bool GameManager::playerHas(Interactable item) {
	return player.getInventory().contains(item);
}

bool GameManager::move(int dir)
{
	if (grid.go(dir)) {
		room = *grid.currentRoom;
		return true;
	}
	return false;
}


