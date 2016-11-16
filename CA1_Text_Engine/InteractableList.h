#pragma once
#include <list>;
#include "Interactable.h";

//Purpose: Holds interactables in a list
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none

class InteractableList {
public:
	InteractableList();
	InteractableList(std::list<Interactable> iList);
	~InteractableList();

	void setList(std::list<Interactable> interactableList) { InteractableList::interactableList = interactableList; }
	std::list<Interactable> getList() const { return interactableList; }

	void printItems() const;
	bool addItem(const Interactable &item);
	bool removeItem(const Interactable &item);
	bool contains(Interactable &item);


private:
	std::list<Interactable> interactableList;
};