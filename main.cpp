#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "mersenne-twister.h"
#include "Game.h"
#include "GameNode.h"
#include "GameList.h"

using namespace std;

int promptAndGetNumLarge();
void processCalculation(string userInput, int& num1, char& operation, int& num2);

int main() {
	// Input a random seed for the program, and call the seed function
	int randSeed;
	cout << "Enter random seed: " << endl;
	cin >> randSeed;
	seed(randSeed);

    //** declare an object of class GameList to store and manage a list of game
    GameList userGame;

	// userContinue is used to input whether the user wants to continue to play another game
	string userContinue;
	do {
        //** reset the list to empty before starting new game
        userGame.clearGame();

		// Get the quantity of large numbers
		int numLarge = promptAndGetNumLarge();

		// Create the game variable, using that quantity of large numbers
		Game game(numLarge);

        //** assign data to the first node of the list
        userGame.addToBeginning(game);
        cout << endl;

		// Clear newline from previous input
		string userInput;
		getline(cin, userInput);

		// Repeat until the game is over
		while (!game.gameOver()) {
			//** Display the available numbers and get the user's calculation input
			//game.displayNumbers();
            userGame.displayHeadNodeData();

			//** variable stores the number of node in the current list
            int nodeCount = userGame.countNodes();
            //cout << "Number of Node is: " << nodeCount << endl;

			cout << "Enter a calculation (or U to Undo, S to Solve, or Q to Quit): ";
			getline(cin, userInput);
            //cout << endl;
            
			// Quit this game if the user choses Q, but don't exit the program (the user might play another game)
			if (userInput == "q" || userInput == "Q") {
				cout << "Exiting this game." << endl << endl;
				break;
			}

            //** undo the game if player chooses U, display the previous sequence of numbers
            // As the game list is always updated to the first node of the list, 
            // in order to undo, we simply remove the first node from the list. 
            // Using a variable nodeCount to handle the number of node in the current list. 
            // The game can undo if number of node is more than 1. 
            // If the list only have one node, cannot undo. 
			else if (userInput == "u" || userInput == "U"){
				if(nodeCount > 1){
					userGame.removeFromBeginning();
                    game = userGame.getLink() -> getGame();
				}
                else{
                    cout << "Cannot undo." << endl << endl;
                }
                continue; // skip to the next step
			}

            //** display the potiential solution if player chooses S
            else if(userInput == "s" || userInput == "S"){
                vector <string> solution;
                if(game.solveGame(solution)){
                    cout << "Solution:" << endl;
                    for (size_t i = 0; i < solution.size();i++){
                        cout << solution[i] << endl;
                    }
                }
                else{
                    cout << "Unable to find a solution" << endl;;
                }
                continue; // skip to the next step
            }

			// Get the numbers and operation from the user's input
			int num1;
			char operation;
			int num2;
			processCalculation(userInput, num1, operation, num2);

			// Make sure num1 and num2 are in the list of numbers
			if (!game.removeNumber(num1)) {
				// num1 was not found, display error message
				cout << num1 << " is not a valid number." << endl;
			}
			else if (!game.removeNumber(num2)) {
				// num2 was not found, display error message
				cout << num2 << " is not a valid number." << endl;
				// add num1 back into the list, since it was removed in the previous if condition
				game.addNumber(num1);
			}
			else {
				// num1 and num2 are in our list, perform the operation and display the equation
				int result = game.performOperation(num1, operation, num2);
				cout << num1 << " " << operation << " " << num2 << " = " << result << endl << endl;

				// Add the result to the list of numbers
				game.addNumber(result);

                //** add new node to beginning of the list after the calculation is made
                userGame.addToBeginning(game);

				// Display win or lose messages if appropriate
				if (game.wonGame()) {
					cout << "You win!" << endl;
				} else if (game.lostGame()) {
					cout << "You lose." << endl;
				}
			}
		}

		// Ask user if they want to continue, do so if they type Y or y
		cout << endl;
		cout << "Would you like to play again (y/n)? ";
		getline(cin, userContinue);
	} while (userContinue == "y" || userContinue == "Y");
}

// Display the greeting and the prompt for choosing big numbers
// Repeats until a valid big number is entered (must be 0-4)
// Returns a valid number of big numbers chosen by the user (0-4)
int promptAndGetNumLarge() {
	int numLarge = 0;

	// Display prompt and get the input
	cout << "Let's play Countdown!" << endl;
	cout << "How many big numbers would you like (0-4)? ";
	cin >> numLarge;

	// Repeat if the input isn't valid (valid is between 0 and 4, inclusive)
	while (numLarge < 0 || numLarge > 4) {
		cout << "That's not a valid number. You must choose between 0 and 4." << endl;
		cout << "How many large numbers would you like? ";
		cin >> numLarge;
	}

	// Return the number chosen
	return numLarge;
}

// Determines the pieces of a calculation from the user input
// Parameters:
// userInput is the string, for example "2+3"
// num1 is passed by reference to return the first number in the calculation (the 2 in the above example)
// operation is passed by reference to return the operation in the calculation ('+' in the above example)
// num2 is passed by reference to return the second number in the calculation (the 3 in the above example)
// Function doesn't return a value, it uses the reference variables to return the information
// Will cause an exception if userInput is anything but a valid operation
void processCalculation(string userInput, int& num1, char& operation, int& num2) {
	// Use a stringstream (essentially turning the given string into a stream)
	stringstream ss(userInput);

	// Input the first number, then the operation, and then the second number from that stream
	ss >> num1 >> operation >> num2;
}