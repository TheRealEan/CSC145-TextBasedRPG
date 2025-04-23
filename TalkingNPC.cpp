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