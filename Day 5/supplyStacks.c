#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "cargo.h"


int main(int nbarg, char * argv[]){
    
    char answerChoise = ' ';
    
    FILE * input = NULL;

    char lineCargo[MAX_SIZE_LINE] = "";

    struct node ** cargo;
    
    void(*rearrangementFct)(struct node **, const int, const int, const int);
    
    
    
    if (nbarg > 1 && (argv[1][0] == '1' || argv[1][0] == '2')){
        answerChoise = argv[1][0];
    }
    
    else{
        fprintf(stderr, "Error with command line argument\n");
        return EXIT_FAILURE;
    }
    
    
    
    if(initCargo(&cargo, NB_STACKS_CARGO) == -1)
        return EXIT_FAILURE;
    
    
    if(openCargoFile(&input, CARGO_FILE) == -1)
        return -1;
    
    
    while(fgets (lineCargo, MAX_SIZE_LINE, input) != NULL){
        
        if (strchr(lineCargo, '[') != NULL){
            
            if(addLineCargo(cargo, lineCargo) == -1){
                freeCargo(cargo);
                closeFile(input);
                return EXIT_FAILURE;
            }
        }
        
        else{
            break;
        }
        
    }
    
    
    #ifdef NDEBUG
    printf("\n");
    printCargo(cargo, NB_STACKS_CARGO);
    #endif
    
    
    
    if(answerChoise == '1'){
        rearrangementFct = rearrangement;
    }
    
    else{
        rearrangementFct = rearrangement9001;
    }
    
    
    
    while(fgets (lineCargo, MAX_SIZE_LINE, input) != NULL){
            makeMove(cargo, lineCargo, rearrangementFct);
    }
    
    printf("Answer %c : ", answerChoise);
    getCratesOnTop(cargo, NB_STACKS_CARGO);
    
    
    
    #ifdef NDEBUG
    printf("\n");
    printCargo(cargo, NB_STACKS_CARGO);
    #endif
    
    
    
    freeCargo(cargo);
    
    closeFile(input);
    
    
    return EXIT_SUCCESS;
}
