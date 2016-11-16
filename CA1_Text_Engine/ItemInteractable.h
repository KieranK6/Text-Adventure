#pragma once
#include "Interactable.h"

//Purpose: 
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

class ItemInteractable : public Interactable{
public:
	ItemInteractable();
	ItemInteractable(std::string name, std::string description);
	~ItemInteractable();

	void print() const;

	bool operator==(ItemInteractable other);
	bool operator!=(ItemInteractable other);

	void setupVerbs();

#pragma region Action Functions
	static void take(ItemInteractable item);
	static void drop(ItemInteractable item);
	static void examine(ItemInteractable item);
#pragma endregion

private:
};