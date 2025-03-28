#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Character.h"
#include "DialogueNode.h"
using namespace std;

class talkingNPC : public Character {
public:
    vector<DialogueNode*> dialogueTree;
    talkingNPC(string name, int treeSize) : Character(name) {
        dialogueTree.resize(treeSize, nullptr);
    }
    void setDialogue(int index, DialogueNode* node) {
        if (index >= 0 && index < static_cast<int>(dialogueTree.size())) {
            dialogueTree[index] = node;
        }
    }

    void printDialogue(int dialogue) {
        if (dialogue < 0 || dialogue >= static_cast<int>(dialogueTree.size()) || dialogueTree[dialogue] == nullptr) {
            cout << "Dialogue not found." << endl;
            return;
        }
        DialogueNode* currentNode = dialogueTree[dialogue];
        cout << getName() << ": " << currentNode->getNPCDialogue() << endl;
        cout << currentNode->getPlayerChoice() << endl;
        vector<int> nextNodes = currentNode->getNextDialogues();
        if (nextNodes.empty()) {
            cin.ignore();   
            cin.get();      
            return;
        }
        int choice;
        cout << "Enter your choice (1-" << nextNodes.size() << "): ";
        cin >> choice;
        choice = choice - 1;
        if (choice < 0 || choice >= static_cast<int>(nextNodes.size())) {
            cout << "Invalid choice." << endl;
            return;
        }
        int nextDialogueIndex = nextNodes[choice];
        printDialogue(nextDialogueIndex);
    }
};
