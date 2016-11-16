#pragma once
#include <string>
#include <vector>

//Purpose: Splits input into two strings
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none


class ActionParser{
public:
	ActionParser();
	~ActionParser();

	std::vector<std::string> parseAction(std::string action);
	std::vector<std::string> takeInput();
private:
};