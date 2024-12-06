#pragma once

#include "Game.h"
#include "GameNode.h"

// GameList class represents a linked list that will store a sequence of Game objects.
// it allows to add node to the begin of the list, remove node from the beginning,
// display the data of a game object which is in current head node of the list, and
// count the number of node in current list 
class GameList {
    private:
        GameNode* head;         // pointer to the head node of the list
        int nodeCount;          // tracking the number of node in the list

    public:
        // default constructor
        GameList();

        // getter for the head node in the list
        GameNode* getLink() const{
            return head;
        }

        // add a new Game object to the beginning of the list
        void addToBeginning(Game theGame);

        // remove the first node from the list
        void removeFromBeginning();

        // clear the list by remove all nodes
        void clearGame();

        // display the data of the game in the first node
        void displayHeadNodeData();

        // count the number of node in the list
        int countNodes();
};