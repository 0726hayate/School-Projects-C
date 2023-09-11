#include <stdio.h>
#include <stdlib.h>
#include "GVDie.h"

int main() {
   int goal = -1;      // Initialize the goal to -1
   int credits;        // Initialize credits (player's balance)
   int rounds = 0;     // Initialize the number of rounds played
   int seed;           // Variable to store the seed for random number generation
   int total;          // Initialize the total value of two dice rolls
   GVDie die1 = GVDie_create();  // Create the first die
   GVDie die2 = GVDie_create();  // Create the second die

   // Read the seed for random number generation
   scanf("%d", &seed);
   srand(seed);

   // Read the initial number of credits (player's balance)
   scanf("%d", &credits);

   // Main game loop
   while (credits != 0) {
       rounds++; // Increment the number of rounds played
       
       // Roll two dice
       die1 = GVDie_roll(die1);
       die2 = GVDie_roll(die2);
   
       // Calculate the total value of the two dice rolls
       total = GVDie_getValue(die1) + GVDie_getValue(die2);
   
       // Check the total value and update credits accordingly
       if (total == 2 || total == 3 || total == 12) {
           credits--;
       }
       else if (total == 7 || total == 11) {
           credits++;
       }
       else {
           goal = total; // Set the goal if total is not 2, 3, 7, 11, or 12
       }

       printf("Dice total: %d\n", total);

       // Check if there is a goal (a point to be achieved)
       if (goal != -1) {
           while (total != 7 || total != goal) {
               // Roll two dice again
               die1 = GVDie_roll(die1);
               die2 = GVDie_roll(die2);
               total = GVDie_getValue(die1) + GVDie_getValue(die2);

               printf("Dice total: %d\n", total);

               // Check if the player achieved the goal or rolled a 7
               if (total == 7) {
                   credits--;
                   goal = -1; // Reset the goal
                   break;
               }
               else if (total == goal) {
                   credits++;
                   goal = -1; // Reset the goal
                   break;
               }
           }
       }

       printf("Credits: %d\n", credits);
   }

   // Print the total number of rounds played
   printf("Rounds: %d\n", rounds);

   return 0;
}
