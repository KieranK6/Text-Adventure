#include "Room.h"
#include "InteractableList.h"
#include "GenericMap.h"
#include "Main.h"
#include "GameManager.h"
#include "StaticInteractable.h"
#include "ItemInteractable.h"
#include "RoomGridCreator.h"
#include "Key.h"
#include "Note.h"
#include "NPC.h"

void initialize();
void initializeDictionaries();
void initializeRooms();
void initializePlayer();
void demo();

GenericMap<Interactable> iMap;
GenericMap<Note> noteMap;
GenericMap<StaticInteractable> staticMap;
GenericMap<Door> doorMap;
GenericMap<Key> keyMap;
GenericMap<NPC> npcMap;

GameManager game;

int main()
{
	initialize();

	// Game hardcoded demo
	//demo();

	// Game loop
	while (game.running) {
		game.takeInput();
	}

	system("pause");
	return 0;
}

void demo()
{
	/*
	std::cout << "*** Room before any action ***" << std::endl;
	game.describeRoom();
	std::cout << "*** Room after player takes hammer ***" << std::endl;
	game.takeItem(iMap.get("Key"));
	game.describeRoom();
	std::cout << "*** Players inventory after player takes key ***" << std::endl;
	game.player.printInventory();
	*/

	game.describeRoom();
	game.move(0);
	game.describeRoom();
	game.move(2);
}

void initialize()
{
	initializeDictionaries();
	initializeRooms();
	initializePlayer();
	game.initialize();
}

void initializeDictionaries()
{
	// ItemInteractables
	ItemInteractable tostring("tostring", "A function that converts a string");
	ItemInteractable actionparser("ActionParser", "Parses input");
	ItemInteractable roomcpp("Roomcpp", "Meta"); 
	ItemInteractable playercpp("Playercpp", "Player::Player(int id, vector2 pos, int heath, PlayerClass detective)");

	iMap.add("tostring", tostring);
	iMap.add("actionparser", actionparser);
	iMap.add("roomcpp", roomcpp);
	iMap.add("roomcpp", playercpp);

	// StaticInteractables
	StaticInteractable statue1("Statue", "This creepy statue seems to stare at you no matter where you are in the room.");
	staticMap.add("statue", statue1);
	iMap.add("statue", statue1);

	// Doors
	Door door("Door", "The door appears to be a set of 1's and 0's", true, 0);
	doorMap.add("door", door);
	iMap.add("door", door);

	// Keys
	Door* dp = &door;
	Key key("Compiler", "This compiles", dp);
	keyMap.add("key", key);
	iMap.add("key", key);

	// Notes
	Note protips("protips", "Coding ProTips", "1)Always comment your code 2)Use breakpoints 3)Test your code");
	noteMap.add("protips", protips);
	iMap.add("protips", protips);

	//NPC
	std::array<StringPair, 3> dialogueArr;
	StringPair pairOne;
	StringPair pairTwo;
	StringPair pairThree;

	pairOne = { "Do we have any bugs?", "I hope not" };
	pairTwo = { "What am I?", "Error: Player Not Defined!" };
	pairThree = { "Where are we?", "CA1" };

	dialogueArr[0] = pairOne;
	dialogueArr[1] = pairTwo;
	dialogueArr[2] = pairThree;

	NPC debug("debug", "A debug tool", "Hello!", "Goodbye!", dialogueArr);
	npcMap.add("debug", debug);
	iMap.add("debug", debug);

	// To Game
	game.interactableMap = iMap;
	game.staticMap = staticMap;
	game.doorMap = doorMap;
	game.keyMap = keyMap;
	game.noteMap = noteMap;
	game.npcMap = npcMap;
}

void initializeRooms()
{
	/**
	*	Creating Rooms
	**/

	InteractableList contents;

	//Add Items for room to contents
	contents.addItem(iMap.get("debug"));
	contents.addItem(iMap.get("key"));
	contents.addItem(iMap.get("door"));

	//Create room
	Room mainRoom(contents, "Main.cpp", "The heart of our code");

	//Re-set contents for next room
	contents.removeItem(iMap.get("debug"));
	contents.removeItem(iMap.get("key"));
	contents.removeItem(iMap.get("door"));
	contents.getList().clear(); //Not working

	//Add
	contents.addItem(iMap.get("tostring"));
	contents.addItem(iMap.get("actionparser"));

	//Room
	Room inputRoom(contents, "Input control", "We process player input commands here");

	//Re-set
	contents.removeItem(iMap.get("tostring"));
	contents.removeItem(iMap.get("actionparser"));
	
	//Add 
	contents.addItem(iMap.get("roomcpp"));

	//Room
	Room sourceRoom(contents, "Source Files", "Home of the Defintions");

	//Re-set
	contents.removeItem(iMap.get("roomcpp"));

	//Add
	contents.addItem(noteMap.get("protips"));
	//Room
	Room p1119(contents, "P1119", "For all your c++ needs!");
	//Re-set
	contents.removeItem(noteMap.get("protips"));

	//Add
	contents.addItem(iMap.get("playercpp"));
	//Room
	Room headerRoom(contents, "Header Files", "The Declaration Council");
	//Re-set
	contents.removeItem(iMap.get("playercpp"));

	/**
	*	Grid Editor
	**/

	Vector2 spawnCoordinates = { 3,3 };


	RoomGrid rg(spawnCoordinates);	// 5x5 grid as defined in RoomGrid.h
	RoomGridCreator rgc;

	rgc.in(rg);
	rgc.go(Vector2{ 3, 3 });
	rgc.set(mainRoom);
	rgc.go(Vector2{ 4, 3 });
	rgc.set(inputRoom); //east
	rgc.go(Vector2{ 3, 4 });
	rgc.set(sourceRoom); //south
	rgc.go(Vector2{ 2, 3 });
	rgc.set(p1119);		//west
	rgc.go(Vector2{ 3, 2 });
	rgc.set(headerRoom); //north
	rg = rgc.out();

	game.setGrid(rg);
	// End Grid Editor
}

void initializePlayer()
{
	game.setPlayer(Player());
}