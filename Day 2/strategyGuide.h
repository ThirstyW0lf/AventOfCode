#ifndef STRATEGY_GUIDE_H
#define STRATEGY_GUIDE_H


#define GUIDE_FILE "input"


struct S_Round{
    char opponentPlay;
    char response;
};



int openFile(FILE ** input);

void closeFile(FILE * input);

int getOnRound(FILE * input, struct S_Round * round);

int getRoundScore(const struct S_Round round);

int getRoundScoreUltimate(const struct S_Round round);

int getScore(int (*scoreFunction)(const struct S_Round round));


#endif
