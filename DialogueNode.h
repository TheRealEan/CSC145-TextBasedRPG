#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class DialogueNode {
protected:
	//This is the current line the NPC says
	string NPCDialogue;
	//This contains all possible options for player dialogue in response to the NPC line
	//This should use numbers corresponding to each possible line
	string playerChoices;
	//Contains what the NPC will reply with based on what number diaglogue option the player chose
	vector<int> nextDialogues;

public:
    DialogueNode(string NPCLine, string playerChoiceList, vector<int> nextList)
        : NPCDialogue(NPCLine), playerChoices(playerChoiceList), nextDialogues(nextList)
    {
    }
   
    string getNPCDialogue() {
        return NPCDialogue;
    }

    void setNPCDialogue(string dialogue) {
        NPCDialogue = dialogue;
    }

    string getPlayerChoice() {
        return playerChoices;
    }

    void setPlayerChoices(string choices) {
        playerChoices = choices;
    }

    vector<int> getNextDialogues() const {
        return nextDialogues;
    }
};