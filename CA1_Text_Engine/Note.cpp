#include "Note.h"
#include <iostream>

//Purpose: A readable item
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none

Note::Note(std::string name, std::string description, std::string content) : ItemInteractable(name, description), content(content)
{
}

Note::Note()
{
}

Note::~Note()
{
}

void Note::read()
{
	std::cout << content << std::endl;
}


