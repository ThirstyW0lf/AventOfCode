#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cargo.h"
#include "linkedList.h"



int initCargo(struct node *** cargo, const int nbStacks){
    
    int i = 0;
    
    if(nbStacks <= 0){
        fprintf(stderr, "The size of the Cargo est <= 0");
        return -1;
    }
    
    
    *cargo = malloc (nbStacks * sizeof(struct node *));
    
    if(cargo == NULL){
    
        fprintf(stderr, "Impossible to allocate memory");
        return -1;
    }
    
    
    for(i = 0; i < nbStacks; i++)
        (*cargo)[i] = NULL;
    
    
    return 0;
    
}



void freeCargo(struct node ** cargo){

    free(cargo);

}



void printCargo(struct node ** cargo, const int nbStacks){
    
    int i = 0;
    
    printf("**********   CARGO   **********\n");
    
    for(i = 0; i < nbStacks; i++){
        printf("Stack n° %d : ", i + 1);
        printStack(cargo[i]);
    }
    
    printf("*******************************\n");

}



int openCargoFile(FILE ** input, const char * cargoFileName){

    *input = fopen(cargoFileName, "r");
    
    
    if (input == NULL)
    {
        printf("Impossible to open file %s !", cargoFileName);
        return -1;
    }
    
    return 0;
    
}



void closeFile(FILE * input){
 
    fclose(input);

}



int addLineCargo(struct node ** cargo, const char * lineCargo){
    
    int sizeLine = 0;
    
    int stack;
    
    char crate;
    
    int i = 0;
    
    
    sizeLine = strlen(lineCargo);
    
    
    for(i = 0; (i * 4) + 1 <= sizeLine; i++){
        
        crate = lineCargo[(i * 4) + 1];
        stack = i;
        
        if((crate >= 'a' && crate <= 'z') || ( crate >= 'A' && crate <= 'Z')){
            
            if(addBegin(&cargo[stack], crate) == -1){
                return -1;
            }
        }
        
    }
    
    return 0;
    
}



void rearrangement(struct node ** cargo, const int nbMove, const int srcStack, const int dstStack){
    
    int tmpCrate = 0;
    
    int i = 0;

    
    for(i = 0; i < nbMove; i++){
        tmpCrate = pop(&cargo[srcStack-1]);
        push(&cargo[dstStack-1], tmpCrate);
    }
    
}



void rearrangement9001(struct node ** cargo, const int nbMove, const int srcStack, const int dstStack){
    
    int tmpCrate = 0;
    
    struct node * tmpCargo = NULL;
    
    int i = 0;

    
    for(i = 0; i < nbMove; i++){
        tmpCrate = pop(&cargo[srcStack-1]);
        push(&tmpCargo, tmpCrate);
    }
    
    
    for(i = 0; i < nbMove; i++){
        tmpCrate = pop(&tmpCargo);
        push(&cargo[dstStack-1], tmpCrate);
    }
    
}



int makeMove(struct node ** cargo, const char * lineCargo, void(*rearrangementFct)(struct node **, const int, const int, const int)){

    int nbMove = 0;
    
    int srcStack = 0;
    int dstStack = 0;
    
    
    if(sscanf(lineCargo, "move %d from %d to %d", &nbMove, &srcStack, &dstStack) != 3){
        return -1;
    }
    
    
    (*rearrangementFct)(cargo, nbMove, srcStack, dstStack);
    
    
    return 0;
    
}



void getCratesOnTop(struct node ** cargo, const int nbStacks){
    
    int i = 0;
    
    for(i = 0; i < nbStacks; i++){
        printf("%c", getLast(cargo[i]));
    }
    
    printf("\n");
    
}
