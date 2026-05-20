#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "TestingHeader.h"



int main() {
    vector<string> deck;
    char playAgain;
    char needInstructions;

    srand(static_cast<unsigned int>(time(0)));

    //First we build the deck by calling our function BuildDeck() to create the cards for the game.
    BuildDeck(deck);

    ShowWelcome();

    cout << "Would you like to see the instructions? (Y/N): ";
    cin >> needInstructions;

    if (UserOptions(needInstructions)) {
        ShowInstructions();
    }

    playAgain = 'y';

    while (UserOptions(playAgain)) {
        PlayRound(deck);

        cout << endl;
        cout << "Would you like to play another round? (Y/N): ";
        cin >> playAgain;
    }

    cout << endl;
    cout << "Thanks for playing Our New BlackJack Version.\nGoodbye!" << endl;

    return 0;
}