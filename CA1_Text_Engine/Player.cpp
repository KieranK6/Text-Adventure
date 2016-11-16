#include "Player.h"
#include <iostream>

Player::Player() : name("default_name"), inventory(InteractableList())
{
}

Player::Player(std::string name)
{
}

Player::Player(std::string name, InteractableList inventory)
{
}

Player::~Player()
{
}

void Player::printInventory() const
{
	Interactable item;
	std::cout << "Inventory contains: " << std::endl;
	for (Interactable i : inventory.getList()) {
		std::cout << i.getName() << std::endl;
	}
}

bool Player::take(const Interactable &item)
{
	return(inventory.addItem(item));
}

bool Player::drop(const Interactable &item)
{
	return(inventory.removeItem(item));
}
