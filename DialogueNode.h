#ifndef DIALOGUENODE_H
#define DIALOGUENODE_H
#include <vector>
#include <string>

class DialogueNode {
public:
	DialogueNode(std::string line, std::string choices, std::vector<int> nextList);

	std::string const getNPCDialogue();
	void setNPCDialogue(std::string line);
	std::string const getPlayerChoices();
	void setPlayerChoices(std::string choices);
	std::vector<int> const getNextDialogues();
	void setNextDialogues(std::vector<int> nextList);

protected:
	std::string NPCDialogue{ "" };
	std::string playerChoices{ "" };
	std::vector<int> nextDialogues;
};

#endif