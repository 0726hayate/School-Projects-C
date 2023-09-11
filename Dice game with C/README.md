# Dice-game-with-C
This C program simulates a simple dice game where the player rolls two dice and aims to achieve a specific goal while managing their credits. The game continues until the player runs out of credits.

# How to Play
1. Compile the program:
+ gcc main.c GVDie.c -o dice_game

2. Run the program:
+ ./dice_game

3. Follow the on-screen instructions:
+ Enter a seed for random number generation.
+ Enter the initial number of credits you want to start with.

# Code Structure
## 'main.c'
The main.c file contains the main game logic. It includes comments to explain key parts of the code. The game loop continues until the player's credits reach zero.

## 'GVDie.h'
The GVDie.h file contains the declarations for a custom data type GVDie, representing a six-sided die. This header file defines functions to create, roll, get the value of, and compare two dice.

## 'GVDie.c'
The GVDie.c file provides the implementations of the functions declared in GVDie.h. It includes functions to create a die, roll a die, get the value of a die, and compare two dice.

# How the Game Works
1. The player enters a seed for random number generation and the initial number of credits.
2. In each round, two dice are rolled, and the total value is calculated.
3. Depending on the total value of the dice, the player's credits are updated:
  + If the total is 2, 3, or 12, the player loses a credit.
  + If the total is 7 or 11, the player gains a credit.
  + Otherwise, the total becomes the player's goal.
4. If there is a goal, the player continues rolling the dice until they either achieve the goal or roll a 7.
  + If the player rolls a 7, they lose a credit, and the goal is reset.
  + If the player achieves the goal, they gain a credit, and the goal is reset.
5.The game continues until the player runs out of credits, and the total number of rounds played is displayed.

# Custom Die Implementation
The program uses a custom GVDie data type to represent a six-sided die. This allows for better abstraction and organization of the code. The custom die functions make it easy to work with dice in the game logic.

# Author
This C code was created by [Your Name]. Feel free to contact me if you have any questions or suggestions for improvement.

Enjoy the game! 🎲
