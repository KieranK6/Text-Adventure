#pragma once
#include "StaticInteractable.h"
#include "GenericMap.h"
#include <array>
#include "StringPair.h"

//Purpose: An interactable character
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none


class NPC : public StaticInteractable
{
public:
	NPC(std::string name, std::string description, std::string hi, std::string bye, std::array<StringPair, 3> dialogueArr);
	NPC();
	~NPC();

	std::string hi;
	std::string bye;


	
	typedef std::array<StringPair, 3> DialogueArr;

	void NPC::talkTo();
	


	DialogueArr dialogueArr;
	
	//GenericMap<Interactable> iMap;
	//array<map(std::string, std::string)> conversations;
};

