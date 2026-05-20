#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "TestingHeader.h"

using namespace std;

/* Program: New BlackJack Version
Description:
This  file contains all functions needed for the our game.
Our New BlackJack Version is a modified Blackjack game where the player can hit, stand,
or swap one card (optional). Besides, we also have one saving opportunity called LifeJacket that
saving the player by reducing their card scores to 17 if their card value is over 21
*/





// Checks yes/no user option and returns true if the user enters Y or y as an answer, or false if he inputs anything else.
bool UserOptions(char option) {
    return option == 'Y' || option == 'y';
}



// This just shows a welcome message to the player.
void ShowWelcome() {
    cout << "Welcome to Tai & Carlos BlackJack Version!" << endl;
    cout << "The goal of this game is trying to get as close to 21 points as possible without exceeding! I recomend you to read the instructions carefully as this version has many different feature comapred to regular black Jack!" << endl;
    cout << endl;
}


// This just shows the playing instructions to the player.
void ShowInstructions() {
    cout << "PLEASE READ CAREFULLY: TAI & CARLOS'S GAME IS NOT TRADITIONAL BLACKJACK! WE ADDED SOME SPICY CAHNGES FOR OUR PLAYERS AHHAHAHAAHAH!!!" << endl;
    cout << endl;
    cout << endl;
    cout << "Like I said, this game is a bit diffrenet than regular Blackjack .Your goal is to get as  close as posible to 21  without exceeding it." << endl;
    cout << "The regular cards containing numbers on the top are equal to their number values. Except for: " << endl;
    cout << "Jack, Queen, and King wich are worth 10 points." << endl;
    cout << "The Ace can mutate to count either as 1 point or 11 points, whichever helps better to win the game!." << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Here are the player choices:" << endl;
    cout << "_ Hit: You draw one more card." << endl;
    cout << "_ Stand: Stop drawing cards and keep your current cards." << endl;
    cout << "_ Swap: So this one is tricky! You can only use it if you decide to stand. After using Swap, your turn finishes right away! So think carefully when choosing this one!" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "But hold on! Thre is one more fun change to the usual regular game! I present to you the Life Jacket!!!! " << endl;
    cout << endl;
    cout << endl;
    cout << "This works basically like a saving your life mercy option: " << endl;
    cout << "If your total value goes over 21... well LifeJacket can save you one time. When LifeJacket is activated, your score is automatically set back to 17." << endl;
    cout << "All good news you may think.... however I have a not so good one... hahahahah  otherwise this game will not be fun after all. Here is the bad news for you buddy: After LifeJacket activates, your turn finishes immediately." << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Here are the Dealer rules:" << endl;
    cout << "- The dealer has to draw while their total is below 17." << endl;
    cout << "- The dealer can have the option to stop when their total is 17 or higher." << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Ok! At this time you are probably asking yourself how can I Win the game?:" << endl;
    cout << endl;
    cout << endl;
    cout << "- If you go exceed 21 and LifeJacket has already been used, you bust and lose." << endl;
    cout << "- If the dealer goes over 21, congrats buddy!  you win!!!!" << endl;
    cout << "- If neither you nor the house busts, the hand closer to 21 wins." << endl;
    cout << "- If both you and the house total the same value... well... the round is tied!" << endl;
    cout << endl;
}


// Builds a standard 52-card deck like the one we did in class.
//Takes on a vector of strings as a parameter.
//I made the deck to be passed by reference this way it modifies the original deck.
void BuildDeck(vector <string>& deck) {

    // Declare and initialize vectors
    vector <string> suit = { "Hearts", "Diamonds", "Clubs", "Spades" };
    vector <string> face = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

    //Create the 52-card deck using a nested for loop (outer loop is for suits and the inner one the face
    for (int i = 0; i < suit.size(); ++i) {
        for (int j = 0; j < face.size(); ++j) {
            deck.push_back(face.at(j) + " of " + suit.at(i));
        }
    }
}



//This function picks a random card & REMOVES IT FROM THE DECK & OUTPUTS/RETURNS THAT CARD.
//I passed the vector of my deck by reference ass well this way it modifies the original deck after I deal the card. 
string DealCard(vector <string>& deck) {
    int randomNum;
    string dealCard;

    if (deck.empty()) {
        cout << "Error: empty deck!" << endl;
        return ""; //I added this to make sure the prgram doesnt crash when division by zero
    }
    // Picks one random card from the deck.
    randomNum = rand() % deck.size(); //Index 0-51
    dealCard = deck.at(randomNum);

    //Removes the random card using the .back() functions to put the card at last and then  removes the last element from the vector like we talked in class using pop_pack().
    deck.at(randomNum) = deck.back();
    deck.pop_back(); // The deck card is reduced.

    return dealCard; //returns the selected card as a string.
}


// It shows all cards in a hand of player
void ShowHand(vector<string> hand) {
    for (int i = 0; i < hand.size(); ++i) {
        cout << i + 1 << ". " << hand.at(i) << endl; //I added the numbers so that later on functions like swap the user can easily identify the card they want to swap.
    }
}


// Shows only the dealer's first card. Remember that the dealer has two cards and the player can only see one.
// It takes the dealer's hand as the parameter and prints out only the dealer's first card.
void ShowDealerFirstCard(vector<string> dealerHand) {
    if (!dealerHand.empty()) { //This just makes sure that the dealer has a minimun of one card on the hand in order to show one card. I added this since if I added an empty vector it will crash the program.
        cout << "The first card of dealer is: " << dealerHand.at(0) << endl;
    }
}


// This function extract the face value from a card string. Example: out of Ace of Sapeds, it returns Ace. I use this function later to calculate Values!
string GetFaceValue(string card) {
    int position;

    position = card.find(" of "); // We learned this function in class, it searches the string and gives the index where " of ".

    return card.substr(0, position); // THIS just gets the everything we need from the string from ths string . Starting at that index 0 up until the index that we obtained in the previous line. It uses the function  substr( from zero to the position number) to just get the face vale part of teh string.
}


// Gets the point value of one card. It takes the card string as the parameter. calls the function GetFaceValue and passes the card we want to get the value out of. Then with a simple if else statement we compare strings and return points as integer depending on the face value.
int GetCardValue(string card) {
    string face;

    face = GetFaceValue(card);

    if (face == "Ace") {
        return 11;
    }
    else if (face == "King" || face == "Queen" || face == "Jack") {
        return 10;
    }
    else if (face == "Ten") {
        return 10;
    }
    else if (face == "Nine") {
        return 9;
    }
    else if (face == "Eight") {
        return 8;
    }
    else if (face == "Seven") {
        return 7;
    }
    else if (face == "Six") {
        return 6;
    }
    else if (face == "Five") {
        return 5;
    }
    else if (face == "Four") {
        return 4;
    }
    else if (face == "Three") {
        return 3;
    }
    else if (face == "Two") {
        return 2;
    }

    //Invalid Card Case FOR SAFETY!
    else {
        cout << "Error, card does not exist!" << endl;
    }
    return -1;
}


// Calculates hand value and adjusts Ace from 11 to 1 if needed
// It takes a vector of cards (your hand or the house hand) and adds all the card values together. It counts if you have any aces and if you do it adjust from 11 to 1 in the value if needed.
int CalculateHandValue(const vector<string>& hand) {
    int total = 0; // sum of all the cards
    int aceCount = 0; // number of aces that we have in the hand
    string face; //The string that contains the string vale.

    for (int i = 0; i < hand.size(); ++i) { //goes through every card in the hand
        face = GetFaceValue(hand.at(i)); //gets the face value of each card on the hand calling our previously defined GetFaceValue function.
        total += GetCardValue(hand.at(i)); //Adds the card values together 

        if (face == "Ace") { //This count any ace.
            aceCount++;
        }
    }

    while (total > 21 && aceCount > 0) { //we adjust the total if this excess 21 by changing the ace values until we are again ok with the 21 point rule that is why i used a whuile loop.
        total -= 10; //The ace was counted previously as 11 but if i change it to just counting it as 1 we reduce by 10.
        aceCount--; //As I go through each ace that i have on my hand.
    }

    return total; //The fucntion always gives the best possble score.
}


// Checks if a hand went over 21 points, since that would be a bust!
bool bust(int sum_value) {
    return sum_value > 21;
}


// Returns player's total. If LifeJacket was used through the bool parameter in the function it will use the if statement to assign the player's score to 17 automatically.
int GetPlayerTotal(const vector<string>& playerHand, bool usedLifeJacket) {
    if (usedLifeJacket) {
        return 17;
    }

    return CalculateHandValue(playerHand); //It passes the player hand value through the CalculateHandValue function that we created in order to provide the total points of that player.
}


// Saves the player one time if they go over 21.
// The player's score becomes 17, and the player cannot draw anymore.
bool LifeJacket(int currentTotal, bool& usedLifeJacket, bool& keepPlaying) {
    if (currentTotal > 21 && !usedLifeJacket) {
        usedLifeJacket = true;
        keepPlaying = false;

        cout << endl;
        cout << "LifeJacket activated!" << endl;
        cout << "You went over 21, but LifeJacket saved you." << endl;
        cout << "Your score is now set to 17." << endl;
        cout << "Your turn is now over. You cannot draw another card." << endl;

        return true;
    }

    return false;
}

// Dealer must hit below 17, so if the integer passed which is the number of points the dealer hand's have at that moment is lower than 17, then DealerShouldHit will return a true boolean.
bool DealerShouldHit(int dealer_total) {
    return dealer_total < 17;
}


// Determines and prints the winner. It takes two integers as parameters with both, the score of the player and teh score of the house and it uses a simple if-else statement to decide winners and loosers based on the games' rules.
void winnerCheck(int player_total, int dealer_total) {
    if (player_total > 21 && dealer_total > 21) {
        cout << "OMG! SO BORING.... Both players busted. It's a tie!" << endl;
    }
    else if (player_total > 21) {
        cout << "You lost. You busted!" << endl;
    }
    else if (dealer_total > 21) {
        cout << "Congrats buddy! Its your lucky day! You won because the dealer busted!" << endl;
    }
    else if (player_total > dealer_total) {
        cout << "Congrats! You won!!! Great game!!!!" << endl;
    }
    else if (player_total < dealer_total) {
        cout << "You lost :/ The house won! Better get more lucky next time!" << endl;
    }
    else {
        cout << "Booooring!!!! It's a tie!!! The house and you have the same points!!!" << endl;
    }
}


// Deals two cards to player and dealer. This function is created to only be used at the begining and it uses push_back to add the cards dealt to each of the hands respectively.
void DealStartingHands(vector<string>& deck, vector<string>& playerHand, vector<string>& dealerHand) {
    playerHand.push_back(DealCard(deck)); //uses our previously defined function called DealCard and passes our deck vector.
    dealerHand.push_back(DealCard(deck));

    playerHand.push_back(DealCard(deck));
    dealerHand.push_back(DealCard(deck));
}


// This function replaces one card of the players hand with one random card from deck
void SwapCard(vector<string>& playerHand, vector<string>& deck, bool& usedSwap) { // It uses the current hand from the player passed by reference so that any changes remain after the function is called. The deck also passed by reference and the usedSwap which is the boolean that makes sure that we have not used the swap before!
    int choice;
    string oldCard;
    string newCard;

    if (usedSwap) {
        cout << "You already used your swap this round." << endl;
        return; //prevents more than one swap each round if usedSwap is true.
    }



    cout << endl;
    cout << "Here are your cards:" << endl;
    ShowHand(playerHand);

    cout << "Choose the card number you want to swap: ";
    cin >> choice;

    //I added this to make sure the player types the right number and the program dont go crazy on it if not.
    while (choice < 1 || choice > playerHand.size()) {
        cout << "Invalid choice. Choose a valid card number: ";
        cin >> choice;
    }

    oldCard = playerHand.at(choice - 1); //Since the player doesnt know that their choice is 1 less value that the index system we use.
    newCard = DealCard(deck); //You use the DealCard function to get the card from the deck and the selected card is removed from the deck.

    playerHand.at(choice - 1) = newCard; // replaces the old card for the new card in the players hand
    usedSwap = true; //Updates the boolean of swapping to true so that your swap ahs been regsitereed in case you try to swap again the program will stop you from it.

    cout << "You swapped out: " << oldCard << endl; //That way the player is aware and see the swap.
    cout << "You received: " << newCard << endl;
}



// This is the function that takes care of the dealer's turn
// It draws cards automatically, stops drawing if it reaches 17 or more points. It doesnt make those player decisions and doesnt have those fancy chnages that are presented to the player.
// It functions quite a bit like the trditional style.
// I passed the hnad that the dealer has by refenece since it will be changed throughout the dealer's turn. I also passed teh deck by reference since there will be changes that i need to do to the deck as well.

void DealerTurn(vector<string>& dealerHand, vector<string>& deck) {
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "It is the Dealer's turn!!!! The dealer is now Playing!!!! Be afraid! He is feeling lucky today! hahahahahah" << endl;

    //Two conditions here, it uses the value hand calculatio function to check the value of the dealer on the cards the dealer has and passes it to the dealershouldhit function to decide if it need to hit or no based on the 17 point rule.
    // The shouldhit function will output true or false.
    //The other condition is the bust which will give true or false if the dealer goes beyond 21 points after passing also the dealers hand value to the bust function
    //Now pretty much while the dealer hit function is true and there is no bust, the dealer is gonna keep going on drawing cards until he is either over 17 or busted.
    while (DealerShouldHit(CalculateHandValue(dealerHand)) && !bust(CalculateHandValue(dealerHand))) {
        string newCard;

        newCard = DealCard(deck);
        dealerHand.push_back(newCard);

        cout << "Dealer drew: " << newCard << endl; //I could hide the dealer's hand and just say something like dealer drew or dealer stands but in order to show in this project the flow of the game I will display it since I might need this to debug my code while I make it.
    }

    cout << "Dealer stands with total: " << CalculateHandValue(dealerHand) << endl; //Outputs the dealers value after the dealer is done with drawing cards from the deck.

    if (bust(CalculateHandValue(dealerHand))) {
        cout << "Dealer busted!" << endl; //checks real quick if busting just happened on the dealers turn to stop the game if true.
    }
}


// Shows final hands and winner
void ShowFinalHands(const vector<string>& playerHand, const vector<string>& dealerHand, bool usedLifeJacket) {
    int playerTotal;
    int dealerTotal;

    playerTotal = GetPlayerTotal(playerHand, usedLifeJacket);
    dealerTotal = CalculateHandValue(dealerHand);

    cout << endl;
    cout << "Final results:" << endl;

    cout << endl;
    cout << "Your final hand:" << endl;
    ShowHand(playerHand);

    if (usedLifeJacket) {
        cout << "LifeJacket was used. Your final total is set to: " << playerTotal << endl;
    }
    else {
        cout << "Your total: " << playerTotal << endl;
    }

    cout << endl;
    cout << "Dealer's final hand:" << endl;
    ShowHand(dealerHand);
    cout << "Dealer total: " << dealerTotal << endl;

    cout << endl;
    winnerCheck(playerTotal, dealerTotal);
}

// On the Player turn function, all the decisions concerning the player are deveopled (hit, stand, swap or use the lifeJacket function previously coded.
// the functuion starts by passing  the players hand by reference, the deck and a boolean by reference as well to track by reference if your lifejaccket has been utilized yet or not.
// How I coded this I pretty much keep askig the player what to do until three thing might activate: stand, bust or lifejacket.
void PlayerTurn(vector<string>& playerHand, vector<string>& deck, bool& usedLifeJacket) {
    char choice; //H or S input
    char swapChoice; //Y or N input for swap
    bool usedSwap = false; //helps me with the once swap per round rule
    bool keepPlaying = true; //helps me with the loop control
    int currentTotal; //keeps my current hand value

    while (keepPlaying && !bust(CalculateHandValue(playerHand))) { //The loop keeps going waiting for either a bust or the keeplaying goes to false (commanded by player)
        cout << endl;
        cout << "Your hand:" << endl;
        ShowHand(playerHand);
        cout << "Your total is: " << GetPlayerTotal(playerHand, usedLifeJacket) << endl; //calls the player total value function that i wrote earlier on the code.
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Choose an option:" << endl;
        cout << "Type H for Hit" << endl;
        cout << "Type S for Stand" << endl;
        cout << "Type your decision buddy! Hurry Up! we dont have all day!!!!: ";
        cin >> choice;

        if (choice == 'H' || choice == 'h') { //I added the h just in case they mess up
            string newCard;

            newCard = DealCard(deck); //deal card
            playerHand.push_back(newCard);

            cout << "You drew: " << newCard << endl; //show card

            currentTotal = CalculateHandValue(playerHand); //recalculate total

            if (bust(currentTotal)) { //checks for bust before doing anything else.
                if (!LifeJacket(currentTotal, usedLifeJacket, keepPlaying)) { //If player is not saved he or she looses and if not their value for total hand value goes to 17
                    cout << "You busted!" << endl;
                }
            }
        }
        else if (choice == 'S' || choice == 's') { //if the player ask to stand.. we ask him or her later to see if they wanna swap.
            cout << endl;
            cout << "You chose to stand." << endl;
            cout << "Would you like to use your one Swap before ending your turn? (Y/N): ";
            cin >> swapChoice;

            if (UserOptions(swapChoice)) { //If the players says yes I use my swap function to take care of it and then CalculateHandValue will take care of the recalculation.
                SwapCard(playerHand, deck, usedSwap);

                currentTotal = CalculateHandValue(playerHand);

                if (bust(currentTotal)) { //and then again we gotta check for bust since he got a new updated hand combination  from the swap
                    if (!LifeJacket(currentTotal, usedLifeJacket, keepPlaying)) {
                        cout << "After swapping, you busted!" << endl;
                    }
                }
            }

            keepPlaying = false; //this exits the loop
        }
        else {
            cout << "Invalid option. Please choose H or S." << endl; // i pu this here later since who knwo maybe they touch the wrong key on the computer and i dont want the entire program to go crazy if thats the case.
        }
        //To cnclude this function i wanted to explain it well: The loop is gonna keep going until the player either stand, player busts and he doesnt have a lifejcket or he/she activates the lifejacket.
    }
}

void PlayRound(vector<string>& deck) {
    vector<string> playerHand;
    vector<string> dealerHand;

    bool usedLifeJacket = false;

    // Rebuild deck if too small
    if (deck.size() < 10) {
        deck.clear();
        BuildDeck(deck);
    }

    // Deal starting hands
    DealStartingHands(deck, playerHand, dealerHand);

    cout << endl;
    cout << "Dealer shows:" << endl;
    ShowDealerFirstCard(dealerHand);

    // Player turn
    PlayerTurn(playerHand, deck, usedLifeJacket);

    // Dealer turn only if player didn't bust
    if (!bust(GetPlayerTotal(playerHand, usedLifeJacket))) {
        DealerTurn(dealerHand, deck);
    }

    // Show results
    ShowFinalHands(playerHand, dealerHand, usedLifeJacket);
}