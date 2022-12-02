#ifndef SUPPLIES_H
#define SUPPLIES_H



#define SUPPLIES_FILE "input"

#define MAX_LENGTH_CALORIES 100



int getNumberOfElves();

int initCaloriesByElves(long ** caloriesByElves, const int numberOfElves);

void freeCaloriesByElves(long * caloriesByElves);

int getCaloriesByElves(long * caloriesByElves, const int numberOfElves);

long getMaxCalories(const long * caloriesByElves, const int numberOfElves);

void sortCaloriesByElves(long * caloriesByElves, const int numberOfElves);


#endif
