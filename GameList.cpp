#include "GameList.h"
#include <iostream>

using namespace std;

// default constructor 
// initilized the head pointer with null pointer and the number of node is 0 
GameList :: GameList(){
    head = nullptr;
    nodeCount = 0;
}

// add a Game object to the beginning of the list
// parameter: - theGame: the Game object will be added to the list
void GameList :: addToBeginning(Game theGame){
    // create a new node with data is theGame and null pointer
    GameNode* newNode = new GameNode(theGame, nullptr);

    // set the new node to link to the current head node
    newNode ->setLink(head);

    // set the new node as the new head node of the list
    head = newNode;

    // number of node is increasing as new node is added
    nodeCount++;
}

// remove the first node from the list
void GameList :: removeFromBeginning(){
    // create a new node which temporarily store the current head node
    GameNode* temp = head;

    // update the head to the next node in the list
    head = head -> getLink();

    // delete the original head node to free the memory
    delete temp;

    // number of node is decreasing as a node was removed
    nodeCount--;
}

// clear all nodes from the list by using the function removeFromBeginning()
void GameList :: clearGame(){
    // remove nodes until the list is empty
    if (head != nullptr){ 
        removeFromBeginning();
    }
    // the list is empty, so the number of node is 0
    nodeCount = 0;
}

// display the data of the head node
void GameList :: displayHeadNodeData(){
    if(head != nullptr){
        // get the game state in the head node by calling getGame(), 
        // then display numbers in that Game's object by calling displayNumbers
        head -> getGame().displayNumbers();
    }
}

//return the number of nodes in current list
int GameList :: countNodes(){
    return nodeCount;
}