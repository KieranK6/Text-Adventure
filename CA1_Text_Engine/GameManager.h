#pragma once
#include "Player.h"
#include "Room.h"
#include "ActionParser.h"
#include "RoomGrid.h"
#include "Note.h"
#include "Interactable.h"
#include "StaticInteractable.h"
#include "Door.h"
#include "Key.h"
#include"NPC.h"

class GameManager {
public:
	GameManager();
	~GameManager();

	void setRoom(Room* room) { GameManager::room = *room; }
	void setPlayer(Player player) { GameManager::player = player; }
	void setGrid(RoomGrid grid) { GameManager::grid = grid; }

	Room room;
	RoomGrid grid;
	Player player;
	GenericMap<Interactable> interactableMap;
	GenericMap<StaticInteractable> staticMap;
	GenericMap<Door> doorMap;
	GenericMap<Key> keyMap;
	GenericMap<Note> noteMap;
	GenericMap<NPC> npcMap;
	GenericMap<std::string>  itemReferenceMap;

	void initialize();

	void initializeReferences();

	void addItemReference(std::string name, std::string type);

	// Game Functions
	void describeRoom();
	bool takeItem(const Interactable &item);
	bool dropItem(const Interactable &item);

	void loadGame();
	void saveGame();

	void takeInput();

	bool isAvailable(Interactable item);

	bool playerHas(Interactable item);

	bool move(int dir);

	bool running = true;



private:
	ActionParser actionParser;
};
