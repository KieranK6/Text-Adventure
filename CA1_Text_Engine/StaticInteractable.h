#pragma once
#include "Interactable.h"

//Purpose: 
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

class StaticInteractable : public Interactable {
public:
	StaticInteractable();
	StaticInteractable(std::string name, std::string description);
	~StaticInteractable();

	bool operator==(StaticInteractable other);
	bool operator!=(StaticInteractable other);

	void setupVerbs();

#pragma region Action Functions
	static void take(StaticInteractable item);
	static void examine(StaticInteractable item);
#pragma endregion
};