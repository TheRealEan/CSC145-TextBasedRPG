#include <iostream>
#include "TalkingNPC.h"
#include "DialogueNode.h"

TalkingNPC::TalkingNPC(std::string nombre, int treeSize) 
	: Character(nombre) {
	dialogueTree.resize(treeSize, nullptr);
}

void TalkingNPC::setDialogue(int index, DialogueNode* node) {
	if (index >= 0 && index < static_cast<int>(dialogueTree.size())) {
		dialogueTree[index] = node;
	}
}

void TalkingNPC::printDialogue(int dialogue) {
	if (dialogue < 0 || dialogue >= static_cast<int>(dialogueTree.size()) || dialogueTree[dialogue] == nullptr) {
		std::cout << "Dialogue not found." << std::endl;
	}

	DialogueNode* currentNode = dialogueTree[dialogue];
	std::cout << getName() << ": " << currentNode->getNPCDialogue() << std::endl;
	std::cout << currentNode->getPlayerChoices() << std::endl;
	std::vector<int> nextNodes = currentNode->getNextDialogues();
	if (nextNodes.empty()) {
		std::cin.ignore();
		std::cin.get();
		return;
	}
	int choice;
	std::cout << "Enter your choice (1-" << nextNodes.size() << "): ";
	std::cin >> choice;
	choice = choice - 1;
	if (choice < 0 || choice >= static_cast<int>(nextNodes.size())) {
		std::cout << "Invalid choice." << std::endl;
		return;
	}
	int nextDialogueIndex = nextNodes[choice];
	printDialogue(nextDialogueIndex);
}

Hermit::Hermit()
	: TalkingNPC("Hermit", 9) {
	// Setup dialogue options.
	std::vector<int> next = { 1, 2, 3 };
	this->setDialogue(0, new DialogueNode(
		"Hello traveler. I see you are new here. I've lived alongside this road for many years and know much about its' inhabitants.\n",
		"1: Tell me about the enemies I will encounter.\n"
		"2: Where can I buy equipment?\n"
		"3: I'm busy, go away.",
		next));

	std::vector<int> next1 = { 4,5,6 };
	this->setDialogue(1, new DialogueNode(
		"There are three monsters you will have to fight: the Roomba, the Chinese Spy Pigeon, and Danny Devito.\n",
		"1: Tell me about the Roomba.\n"
		"2: Tell me about the Chinese Spy Pigeon.\n"
		"3: Tell me about Danny Devito.",
		next1));

	std::vector<int> next2 = { 7,8 };
	this->setDialogue(2, new DialogueNode(
		"What are you looking for, armor or weapons?\n",
		"1: Armor\n"
		"2: Weapons",
		next2));

	std::vector<int> next3 = {};
	this->setDialogue(3, new DialogueNode(
		"Have a blessed day traveller.\n",
		"Press any key to continue...",
		next3));

	std::vector<int> next4 = {};
	this->setDialogue(4, new DialogueNode(
		"The Roomba can be easily trampled underfoot.\n",
		"Press any key to continue...",
		next4));

	std::vector<int> next5 = {};
	this->setDialogue(5, new DialogueNode(
		"The Chinese Spy Pigeon can be defeated if you sever its radio connection.\n",
		"Press any key to continue...",
		next5));

	std::vector<int> next6 = {};
	this->setDialogue(6, new DialogueNode(
		"Danny Devito prefers to attack rather than defend.\n",
		"Press any key to continue...",
		next6));

	std::vector<int> next7 = {};
	this->setDialogue(7, new DialogueNode(
		"Go to town.There you will find an armor shop.Good luck in your travels!\n",
		"Press any key to continue...",
		next7));

	std::vector<int> next8 = {};
	this->setDialogue(8, new DialogueNode(
		"Go to town. There you will find a weapons shop. Good luck in your travels!\n",
		"Press any key to continue...",
		next8));
}

Salesman::Salesman()
	: TalkingNPC("Wandering Salesman", 89) {
	// Setup dialogue options.
	std::vector<int> next = { 1, 2, 3 };
	this->setDialogue(0, new DialogueNode(
		"Hello traveler! Would you be interested in joining a pyramid scheme?\n",
		"1: Tell me more.\n"
		"2: Isn't that illegal?\n"
		"3: STRANGER DANGER",
		next));

	std::vector<int> next1 = { 4,5,6 };
	this->setDialogue(1, new DialogueNode(
		"Well I will give you this very nice set of knives, and if you sell it to your family and friends, I will pay you a portion of the profit.\n",
		"1: That sounds great! Count me in!\n"
		"2: I don't know about this...\n"
		"3: This sounds like a scam, goodbye.",
		next1));

	std::vector<int> next2 = { 7,8 };
	this->setDialogue(2, new DialogueNode(
		"Nooooooooo of course not...\n",
		"1: Walk away in disdain.\n"
		"2: Steal the knives.",
		next2));

	std::vector<int> next3 = {};
	this->setDialogue(3, new DialogueNode(
		"Fine! Be that way.\n",
		"Press any key to continue...",
		next3));

	std::vector<int> next4 = {};
	this->setDialogue(4, new DialogueNode(
		"Great! Sign right here!\n",
		"You are now involved in a pyramid scheme...\n"
		"Press any key to continue...",
		next4));

	std::vector<int> next5 = {};
	this->setDialogue(5, new DialogueNode(
		"Oh come on! This is a completely foolproof business strategy!\n",
		"You walk away from the trap...\n"
		"Press any key to continue...",
		next5));

	std::vector<int> next6 = {};
	this->setDialogue(6, new DialogueNode(
		"But you can save up for college!!\n",
		"You ignore the crazy salesman and walk away...\n"
		"Press any key to continue...",
		next6));

	std::vector<int> next7 = {};
	this->setDialogue(7, new DialogueNode(
		"Hey don't leave! I promise you'll make money!\n",
		"You back away slowly...\n"
		"Press any key to continue...",
		next7));

	std::vector<int> next8 = {};
	this->setDialogue(8, new DialogueNode(
		"HEY! Those are mine!!\n",
		"You are now on the run...\n"
		"Press any key to continue...",
		next8));
}