#include "NPC.h"

//Purpose: An interactable character
//Author: Kieran
//Version: 1.0
//Bugs: None known
//TODO: none


NPC::NPC(std::string name, std::string description, std::string hi,
	std::string bye, std::array<StringPair, 3> dialogueArr)
	: StaticInteractable(name, description), hi(hi), bye(bye), dialogueArr(dialogueArr)
{
}

NPC::NPC() : StaticInteractable("default_name", "default_description"), hi("Hello!(Def)"), bye("Goodbye!(Def)")
{
	StringPair pairOne;
	StringPair pairTwo;
	StringPair pairThree;

	pairOne = {"Def Question1", "Def Responce1"};
	pairTwo = { "Def Question2", "Def Responce2" };
	pairThree = { "Def Question3", "Def Responce3" };

	dialogueArr[0] = pairOne;
	dialogueArr[1] = pairTwo;
	dialogueArr[2] = pairThree;
}


NPC::~NPC()
{
}

void NPC::talkTo()
{
	// hello message
	std::cout << hi << std::endl;

	//take choice
 	int choice = 0;
	do {
		//Possible Player Questions
		std::cout << "-------------------------" << getName() << "-------------------------" << std::endl;
		std::cout << "1. " << dialogueArr[0].one << std::endl;
		std::cout << "2. " << dialogueArr[1].one << std::endl;
		std::cout << "3. " << dialogueArr[2].one << std::endl;
		std::cout << "4. " << "Bye!" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
		//Take player choice
		std::cout << "Enter command:";
		std::cin >> choice;
		//Print NPC responce
		if (choice == 1) {
			std::cout << dialogueArr[0].two << std::endl;
		}
		else if (choice == 2) {
			std::cout << dialogueArr[1].two << std::endl;
		}
		else if (choice == 3) {
			std::cout << dialogueArr[2].two << std::endl;
		}

	} while (choice != 4); //Break
	//Goodbye Message
	std::cout << bye << std::endl;

}
