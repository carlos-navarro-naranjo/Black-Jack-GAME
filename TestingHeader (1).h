#ifndef TESTINGHEADER_H
#define TESTINGHEADER_H



#include <string>
#include <vector>

using namespace std;

/* Program: New BlackJack Version
Description:
This  file contains all functions needed for the our game.
Our New BlackJack Version is a modified Blackjack game where the player can hit, stand,
or swap one card (optional). Besides, we also have one saving opportunity called LifeJacket that 
saving the player by reducing their card scores to 17 if their card value is over 21
*/

// Function prototypes: I do this to tell my program all my functions are real so that i can use them all later wherever I want.
// They are important because the computer only reads top to bottom so this way it has seen everything beforehand.


bool UserOptions(char option);

void ShowWelcome();
void ShowInstructions();

void BuildDeck(vector<string>& deck);
string DealCard(vector<string>& deck);

void ShowHand(vector<string> hand);
void ShowDealerFirstCard(vector<string> dealerHand);

string GetFaceValue(string card);
int GetCardValue(string card);
int CalculateHandValue(const vector<string>& hand);

bool bust(int sum_value);
bool DealerShouldHit(int dealer_total);
void winnerCheck(int player_total, int dealer_total);

void DealStartingHands(vector<string>& deck, vector<string>& playerHand, vector<string>& dealerHand);
void SwapCard(vector<string>& playerHand, vector<string>& deck, bool& usedSwap);

void PlayerTurn(vector<string>& playerHand, vector<string>& deck, bool& usedLifeJacket);
void DealerTurn(vector<string>& dealerHand, vector<string>& deck);

void ShowFinalHands(const vector<string>& playerHand, const vector<string>& dealerHand, bool usedLifeJacket);
void PlayRound(vector<string>& deck);

bool LifeJacket(int currentTotal, bool& usedLifeJacket, bool& keepPlaying);
int GetPlayerTotal(const vector<string>& playerHand, bool usedLifeJacket);


#endif