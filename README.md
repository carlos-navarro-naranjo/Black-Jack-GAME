# 🎮 BlackJack GAME C++

A custom Blackjack game built in C++ featuring modified gameplay mechanics, interactive player choices, and a full card/deck system using vectors and functions.

This project was developed as a programming and problem-solving exercise focused on:
- Modular programming
- Function decomposition
- Vectors and string manipulation
- Game logic implementation
- Randomization
- User interaction in the console

Unlike traditional Blackjack, this version introduces two unique gameplay features.

---

# ✨ Custom Features

## 🔄 Swap Mechanic
Players can choose to swap one card from their hand before ending their turn.

The selected card is replaced with a random card from the deck, adding an extra strategic element to the game.

---

## 🛟 LifeJacket System
If the player goes over 21, they receive one emergency save called **LifeJacket**.

### LifeJacket Rules
- Activates automatically once per round
- Resets the player's score to **17**
- Immediately ends the player's turn

This creates a risk-versus-reward mechanic that changes traditional Blackjack strategy.

---

# 🃏 Game Rules

- Try to get as close to 21 as possible without going over
- Number cards are worth their numeric value
- Face cards (Jack, Queen, King) are worth 10
- Aces automatically adjust between 1 and 11 depending on the hand value
- Dealer must draw until reaching at least 17
- Highest hand under or equal to 21 wins

---

# 📂 Project Structure

## `TestingMain.cpp`
Contains the main game loop and controls the overall game flow.

## `TestingFunctionsGame.cpp`
Contains all gameplay functions, including:
- Deck creation
- Card dealing
- Hand value calculations
- Dealer AI
- Swap mechanics
- LifeJacket system
- Winner determination

## `TestingHeader.h`
Header file containing all function prototypes.

---

# 🧠 Concepts Used

This project demonstrates:
- Vectors
- Strings
- Loops
- Conditionals
- Pass-by-reference
- Modular design
- Random number generation
- Header files
- Function prototypes
- Game-state management

---

# ▶️ How to Run

Compile the program using a C++ compiler such as `g++`.

```bash
g++ TestingMain.cpp TestingFunctionsGame.cpp -o blackjack
./blackjack
```

---

# 🚀 Future Improvements

Possible future updates:
- Betting/chips system
- Multiple players
- Graphical interface
- Save/load system
- Card ASCII art
- Dealer difficulty levels
- Statistics tracking

---

# 👨‍💻 Authors

Developed by Carlos Navarro Naranjo.

---

# 📸 Example Gameplay

```text
Dealer shows:
Ace of Hearts

Your hand:
1. Eight of Clubs
2. King of Spades

Your total is: 18

Choose an option:
H = Hit
S = Stand
```
