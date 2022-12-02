#include <stdio.h>
#include <stdlib.h>

#include "supplies.h"


int main(){
    
    int numberOfElves;
    
    long * caloriesByElves = NULL;
    
    
    numberOfElves = getNumberOfElves();
        
    if(numberOfElves < 1)
        return EXIT_FAILURE;
    
    
    #ifdef NDEBUG
    printf ("NumberOfElves : %d\n", numberOfElves);
    #endif
    
    
    if(initCaloriesByElves(&caloriesByElves, numberOfElves) == -1){
        return EXIT_FAILURE;
    }


    if(getCaloriesByElves(caloriesByElves, numberOfElves) == -1){
        freeCaloriesByElves(caloriesByElves);
        return EXIT_FAILURE;
    }
    
    
    #ifdef NDEBUG
    for(int i = 0; i < numberOfElves; i++){
        printf("%ld\n", caloriesByElves[i]); 
    }
    #endif


    printf("Answer n°1 : Maximum of Calories is %ld\n", getMaxCalories(caloriesByElves, numberOfElves));
    
    
    /* ------------------------------------------------- */
    
    
    sortCaloriesByElves(caloriesByElves, numberOfElves);
    

    if(numberOfElves < 3){
        printf("Answer n°2 : Not enough Elves");
    }
    
    else {
        printf("Answer n°2 : Total of 3 max Calories is %ld\n", caloriesByElves[numberOfElves - 1] +            caloriesByElves[numberOfElves - 2] + caloriesByElves[numberOfElves - 3]);
    }
    
    
    freeCaloriesByElves(caloriesByElves);
    
    return EXIT_SUCCESS;
}
