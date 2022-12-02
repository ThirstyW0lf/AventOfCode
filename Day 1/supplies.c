#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "supplies.h"



/*   --------------- Static Functions ---------------   */


static int longComparator(const void * first, const void * second){
/* Comparaison function for qsort () */

    long firstLong = * (const long *) first;
    /* eq : long firstLong = * ((const long *) first); */
    
    long secondLong = * (const long *) second;
    
    return (int) (firstLong - secondLong);
}



static int convertCalorieToLong(char * caloriesStr){
    
    long result = 0;
    
    char * endptr = NULL;
    
    
    result = strtol(caloriesStr, &endptr, 10);
            
    
    if(caloriesStr == endptr)
    {
        fprintf(stderr, "Nothing parsed from the string\n");
        return -1;
    }
    
    
    if(result == LONG_MAX || result == LONG_MIN)
    /* if((result == LONG_MAX || result == LONG_MIN) && errno == ERANGE)) */
    {
    fprintf(stderr, "Out of range\n");
        return -1;
    }
    
    
    return result;    
}


/*   -----------------------------------------------   */



int getNumberOfElves()
{

    int numberOfElves = 0;
    char caloriesStr[MAX_LENGTH_CALORIES] = "";
    
    FILE * input = NULL;
    
    input = fopen(SUPPLIES_FILE, "r");
    
    
    if (input == NULL)
    {
        printf("Impossible to open file %s !", SUPPLIES_FILE);
        return -1;
    }
    
    
    while ( fgets (caloriesStr, MAX_LENGTH_CALORIES, input) != NULL){
    /* fgets () function reads at most size - 1 caracters */
    
        if(caloriesStr[0] == '\n')
            numberOfElves++;
    }
    
    
    fclose(input);
    

    return numberOfElves;
}



int initCaloriesByElves(long ** caloriesByElves, const int numberOfElves){

    int i = 0;
    
    * caloriesByElves = malloc(numberOfElves * sizeof(long));
    
    
    if(*caloriesByElves == NULL){
    
        fprintf(stderr, "Impossible to allocate memory");
        return -1;
    }
    
    
    for(i = 0; i < numberOfElves; i++)
        (*caloriesByElves)[i] = 0;
    
    
    return 0;
}



void freeCaloriesByElves(long * caloriesByElves){
    
    free(caloriesByElves);
}



int getCaloriesByElves(long * caloriesByElves, const int numberOfElves){
    
    char caloriesStr[MAX_LENGTH_CALORIES] = "";
    long result = 0;
    int i = 0;
    
    FILE * input = NULL;
    
    
    input = fopen(SUPPLIES_FILE, "r");
    
    
    if (input == NULL){
        printf("Impossible to open file %s !", SUPPLIES_FILE);
        return -1;
    }
    
    
    while ( fgets (caloriesStr, MAX_LENGTH_CALORIES, input) != NULL && i < numberOfElves){
    /* fgets () function reads at most size - 1 caracters */
    
        if(caloriesStr[0] == '\n')
            i++;
        
        else
        {
            result = convertCalorieToLong(caloriesStr);
            
            if (result == -1)
                return -1;
            
            else
                caloriesByElves[i] += result;
        }
        
    }
    
    
    fclose(input);

    return 0;
}



long getMaxCalories(const long * caloriesByElves, const int numberOfElves)
{
    
    int i = 0;
    int indexMaxCalories = 0;
    
    
    for(i = 0; i < numberOfElves; i++){
        
        if(caloriesByElves[i] > caloriesByElves[indexMaxCalories])
            indexMaxCalories = i;
    }
    
    return caloriesByElves[indexMaxCalories];
}




void sortCaloriesByElves(long * caloriesByElves, const int numberOfElves)
{
    
    qsort(caloriesByElves, numberOfElves, sizeof(long), longComparator);
    
}
