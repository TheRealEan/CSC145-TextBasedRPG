#include "DialogueNode.h"

DialogueNode::DialogueNode(std::string line, std::string choices, std::vector<int> nextList)
	: NPCDialogue(line), playerChoices(choices), nextDialogues(nextList) {
}

std::string const DialogueNode::getNPCDialogue() {
	return NPCDialogue;
}

void DialogueNode::setNPCDialogue(std::string line) {
	NPCDialogue = line;
}

std::string const DialogueNode::getPlayerChoices() {
	return playerChoices;
}

void DialogueNode::setPlayerChoices(std::string choices) {
	playerChoices = choices;
}

std::vector<int> const DialogueNode::getNextDialogues() {
	return nextDialogues;
}

void DialogueNode::setNextDialogues(std::vector<int> nextList) {
	nextDialogues = nextList;
}
