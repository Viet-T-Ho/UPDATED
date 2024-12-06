#pragma once

#include "Game.h"
// GameNode class represents a node in linked list that holds game state
// each GameNode includes a Game object and a pointer to the next node
class GameNode {
    private:
        Game game;            // the Game object that a node is stroring
        GameNode* link;       // pointer to the next node in the list
    public:
        // default constructor
        GameNode();

        // parameterized constructor
        GameNode(Game theGame, GameNode* theLink);

        // declare getter funtions
        GameNode* getLink() const;
        Game getGame() const;

        // declare setter funtions
        void setLink(GameNode* theLink);
        void setGame(Game theGame);
};
