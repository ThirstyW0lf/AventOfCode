#include <stdio.h>
#include <stdlib.h>

#include "strategyGuide.h"


int main(){
    
    int score = 0;
    
    
    /* ------------------------------ */
    
    score = getScore(&getRoundScore);
    
    if(score == -1)
        return EXIT_FAILURE;
    
    else
        printf("Answer n°1 : The score is %d\n", score);
    
    
    /* ------------------------------ */
    
    
    score = getScore(&getRoundScoreUltimate);
    
    if(score == -1)
        return EXIT_FAILURE;
    
    else
        printf("Answer n°2 : The score Ultimate is %d\n", score);
    

    return EXIT_SUCCESS;
}
