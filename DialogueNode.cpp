#include"DialogueNode.h"

using namespace std;

//See DialogueNode.h for specifics of each member
DialogueNode::DialogueNode(string NPCLine, string playerChoiceList, vector<int> nextList) {
	NPCDialogue = NPCLine;
	playerChoices = playerChoiceList;
	nextDialogues = nextList;
}

string DialogueNode::getNPCDialogue() {
	return NPCDialogue;
}

void DialogueNode::setNPCDialogue(string dialogue) {
	NPCDialogue = dialogue;
}

string DialogueNode::getPlayerChoice() {
	return playerChoices;
}

void  DialogueNode::setPlayerChoices(string choices) {
	playerChoices = choices;
}