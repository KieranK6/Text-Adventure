#pragma once
#include "GameObject.h";
#include "InteractableList.h";
#include "GenericMap.h";

//Purpose: 
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

class Room : public GameObject{
public:
	Room();
	Room(std::string name, std::string description);
	Room(InteractableList contents, std::string name, std::string description);
	~Room();

	void setContents(InteractableList contents) { Room::contents = contents; }

	std::map<std::string, std::vector<std::string>> getCommands() const { return validCommands; }

	bool addItem(const Interactable &item);
	bool removeItem(const Interactable &item);
	bool contains(Interactable& item);

	bool validRoom;
	InteractableList contents;
	
#pragma region demo functions
	void printCommands() const;
#pragma endregion

	void print() const;
private:
	//RoomList connectedRooms; // 0: north	1: east		2: south	3: west
	std::map<std::string, std::vector<std::string>> validCommands; // "torch" -> "take, drop, etc"
};
