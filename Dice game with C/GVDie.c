#include <stdio.h>
#include <stdlib.h>
#include "GVDie.h"

GVDie GVDie_create() {
   GVDie die;
   die.value = -1;
   return die;
}

GVDie GVDie_roll(GVDie die) {
   die.value = (rand() % 6) + 1;  //1 to 6
   return die;
}

int GVDie_getValue(GVDie die) {
   return die.value;
}

// Allows dice to be compared if necessary
int GVDie_compareTo(GVDie die1, GVDie die2) {
   return GVDie_getValue(die1) - GVDie_getValue(die2);
}
