#ifndef GVDIE_H
#define GVDIE_H

typedef struct GVDie_struct {
   int value; 
} GVDie;

GVDie GVDie_create();
GVDie GVDie_roll(GVDie die) ;
int GVDie_getValue(GVDie die);
int GVDie_compareTo(GVDie die1, GVDie die2);

#endif
