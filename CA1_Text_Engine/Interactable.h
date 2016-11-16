#pragma once
#include "GameObject.h"
#include <vector>

//Purpose: 
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none

class Interactable : GameObject {
	
public:
	Interactable();
	Interactable(std::string name, std::string description, std::vector<std::string> verbList);
	~Interactable();

	std::string getName() const { return GameObject::getName(); }
	std::string getDescription() const { return GameObject::getDescription(); }
	void print() const;

	bool operator==(Interactable other);
	bool operator!=(Interactable other);
	
	std::vector<std::string> verbList = {};

	// Virtual Functions
	

	static void examine(Interactable i);

	//virtual void read();
private:
	
};
