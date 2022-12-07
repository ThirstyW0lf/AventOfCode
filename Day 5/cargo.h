#ifndef CARGO_H
#define CARGO_H

#include "linkedList.h"


#define CARGO_FILE "input"

#define MAX_SIZE_LINE (100)

#define NB_STACKS_CARGO (9)


int initCargo(struct node *** cargo, const int nbStacks);

void freeCargo(struct node ** cargo);

void printCargo(struct node ** cargo, const int nbStacks);

int openCargoFile(FILE ** input, const char * cargoFileName);

void closeFile(FILE * input);

int addLineCargo(struct node ** cargo, const char * lineCargo);

void rearrangement(struct node ** cargo, const int nbMove, const int srcStack, const int dstStack);

void rearrangement9001(struct node ** cargo, const int nbMove, const int srcStack, const int dstStack);

int makeMove(struct node ** cargo, const char * lineCargo, void(*rearrangementFct)(struct node **, const int, const int, const int));

void getCratesOnTop(struct node ** cargo, const int nbStacks);

#endif
