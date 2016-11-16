#pragma once
#include <string>
#include "InteractableList.h"

//Purpose: Splits input into two strings
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none

class Player {
public:
	Player();
	Player(std::string name);
	Player(std::string name, InteractableList inventory);
	~Player();

	void setName(std::string name) { Player::name = name; }
	void setInventory(InteractableList inventory) { Player::inventory = inventory; }
	
	std::string getName() const { return name; }
	InteractableList getInventory() const { return inventory; }
	void printInventory() const;

	bool take(const Interactable &item);
	bool drop(const Interactable &item);

private:
	std::string name;
	InteractableList inventory;
};