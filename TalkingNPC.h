#ifndef TALKINGNPC_H
#define TALKINGNPC_H
#include <vector>
#include "Character.h"
class DialogueNode;

class TalkingNPC : public Character {
public:
    TalkingNPC(std::string nombre, int treeSize);
    virtual ~TalkingNPC() = default;

    void setDialogue(int index, DialogueNode* node);
    void printDialogue(int dialogue);

protected:
    std::vector<DialogueNode*> dialogueTree;
};

class Hermit : public TalkingNPC {
public:
    Hermit();
};

class Salesman : public TalkingNPC {
public:
    Salesman();
};

#endif
