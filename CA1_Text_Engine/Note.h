#pragma once
#include "ItemInteractable.h"

//Purpose: A readable item
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none

class Note : public ItemInteractable
{
public:
	Note(std::string name, std::string description, std::string content);
	Note();
	~Note();

	std::string content;

	void read();
};

