#include <stdio.h>
#include <stdlib.h>

#include "strategyGuide.h"



int openFile(FILE ** input)
{

    *input = fopen(GUIDE_FILE, "r");
    
    
    if (input == NULL)
    {
        printf("Impossible to open file %s !", GUIDE_FILE);
        return -1;
    }
    
    return 0;
    
}



void closeFile(FILE * input)
{
 
    fclose(input);
    
}



int getOnRound(FILE * input, struct S_Round * round){
    
    int returnValue = 0;
    

    returnValue = fscanf(input, "%c %c\n", &round->opponentPlay, &round->response);    

    if(returnValue != 2)
        return -1;
    
    else
        return 0;
}



int getRoundScore(const struct S_Round round){
    
    if(round.opponentPlay == 'A' && round.response == 'X')  // Rock - Rock
        return 4;
    
    else if(round.opponentPlay == 'A' && round.response == 'Y')  // Rock - Paper
        return 8;
    
    else if(round.opponentPlay == 'A' && round.response == 'Z')  // Rock - Scissors
        return 3;
    
    
    else if(round.opponentPlay == 'B' && round.response == 'X')  // Paper - Rock
        return 1;
    
    else if(round.opponentPlay == 'B' && round.response == 'Y')  // Paper - Paper
        return 5;
    
    else if(round.opponentPlay == 'B' && round.response == 'Z')  // Paper - Scissors
        return 9;
    
    
    else if(round.opponentPlay == 'C' && round.response == 'X')  // Scissors - Rock
        return 7;
    
    else if(round.opponentPlay == 'C' && round.response == 'Y')  // Scissors - Paper
        return 2;
    
    else if(round.opponentPlay == 'C' && round.response == 'Z')  // Scissors - Scissors
        return 6;
    
    
    else {
        fprintf(stderr, "The file %s is Invalid\n", GUIDE_FILE);
        return -1;
    }
    
}



int getRoundScoreUltimate(const struct S_Round round){
    
    if(round.opponentPlay == 'A' && round.response == 'X')  // X = Lose : Rock - Scissors
        return 3;
    
    else if(round.opponentPlay == 'A' && round.response == 'Y')  // Y = Draw : Rock - Rock
        return 4;
    
    else if(round.opponentPlay == 'A' && round.response == 'Z')  // Z = Win : Rock - Paper
        return 8;
    
    
    else if(round.opponentPlay == 'B' && round.response == 'X')  // X = Lose : Paper - Rock
        return 1;
    
    else if(round.opponentPlay == 'B' && round.response == 'Y')  // Y = Draw : Paper - Paper
        return 5;
    
    else if(round.opponentPlay == 'B' && round.response == 'Z')  // Z = Win : Paper - Scissors
        return 9;
    
    
    else if(round.opponentPlay == 'C' && round.response == 'X')  // X = Lose : Scissors - Paper
        return 2;
    
    else if(round.opponentPlay == 'C' && round.response == 'Y')  // Y = Draw : Scissors - Scissors
        return 6;
    
    else if(round.opponentPlay == 'C' && round.response == 'Z')  // Z = Win : Scissors - Rock
        return 7;

    
    else {
        fprintf(stderr, "The file %s is Invalid\n", GUIDE_FILE);
        return -1;
    }

}



int getScore(int (*scoreFunction)(const struct S_Round round)){
    
    int score = 0;
    int roundScore = 0;
    
    struct S_Round round;
    
    FILE * input = NULL;


    if(openFile(&input) == -1)
        return -1;
    
    
    while(getOnRound(input, &round) == 0){
        
        roundScore = (*scoreFunction)(round);
        
            
        #ifdef NDEBUG
        printf("%c %c %d %d\n", round.opponentPlay, round.response, roundScore, score);
        #endif
        
        
        if(roundScore == -1){
            closeFile(input);
            return -1;
        }
        
        else{
            score += roundScore;
        }

    }
    
    closeFile(input);
    
    
    return score;
}
