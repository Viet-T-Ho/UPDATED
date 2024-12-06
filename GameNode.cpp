# include "GameNode.h"

// default constructor
// initialized the node with a empty Game object and null pointer
GameNode :: GameNode(){
    this -> game = Game();      // initialized game with the default constructor of Game class
    this -> link = nullptr;     // set link to null pointer
}

// parameterized constructor
// initialized the node with a specific Game object and pointer to the next node
// parameter: - theGame: a specific Game object to store in the node
//            - theLink: a pointer to the next GameNode in the linked list
GameNode :: GameNode(Game theGame, GameNode* theLink){
    this -> game = theGame;     // set the game state for the node
    this -> link = theLink;     // set the link to point to the next node in the list
}

// getter for the link
// return a pointer to the next node
GameNode* GameNode :: getLink() const{
    return link;
}

// getter for the game object which is stored in current node
// return the Game object in the current node
Game GameNode :: getGame() const{
    return game;
}

// setter for the link
// set and update the link to next node in the list
void GameNode :: setLink(GameNode* theLink){
    this -> link = theLink;
}

// setter for the game object stored in the node
// set and update the Game object in the node
void GameNode :: setGame(Game theGame){
    this -> game = theGame;
}