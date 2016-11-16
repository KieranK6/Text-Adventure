#include "ActionParser.h"
#include <iostream>
#include <string>
#include <algorithm>

//Purpose: Splits input into two strings
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none

ActionParser::ActionParser()
{
}

ActionParser::~ActionParser()
{
}

std::vector<std::string> ActionParser::parseAction(std::string action)
{
	std::string verb, noun;
	size_t newPos;
	size_t oldPos = 0;
	std::string delimiter = " ";

	newPos = action.find(delimiter);
	verb = action.substr(oldPos, newPos);
	noun = action.substr(newPos + 1, action.length());

	std::vector<std::string> commandVector;

	std::transform(verb.begin(), verb.end(), verb.begin(), ::tolower);
	std::transform(noun.begin(), noun.end(), noun.begin(), ::tolower);

	commandVector.push_back(noun);
	commandVector.push_back(verb);

	return commandVector;
}

std::vector<std::string> ActionParser::takeInput()
{	
	std::string command;
	std::cout << "Enter command:";
	std::getline(std::cin, command);
	return ActionParser::parseAction(command);
}
