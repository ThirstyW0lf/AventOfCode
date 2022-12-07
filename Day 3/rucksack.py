#!/usr/bin/env python3

rucksacksFile = "input"


def getItemPriority(item):
    
    priorities = {'a': 1, 'b' : 2, 'c' : 3, 'd' : 4, 'e' : 5, 'f' : 6, 'g' : 7, 'h' : 8, 'i' : 9, 'j' : 10, 'k' : 11, 'l' : 12, 'm' : 13, 'n' : 14, 'o' : 15, 'p' : 16, 'q' : 17, 'r' : 18, 's' : 19, 't' : 20, 'u' : 21, 'v' : 22, 'w' : 23, 'x' : 24, 'y' : 25, 'z' : 26, 'A': 27, 'B' : 28, 'C' : 29, 'D' : 30, 'E' : 31, 'F' : 32, 'G' : 33, 'H' : 34, 'I' : 35, 'J' : 36, 'K' : 37, 'L' : 38, 'M' : 39, 'N' : 40, 'O' : 41, 'P' : 42, 'Q' : 43, 'R' : 44, 'S' : 45, 'T' : 46, 'U' : 47, 'V' : 48, 'W' : 49, 'X' : 50, 'Y' : 51, 'Z' : 52}
    
    return priorities[item]



def getPrioritiesIfInBoth(rucksack):
    
    lenHalfLine = (int)((len(rucksack) - 1) / 2)           

            
    firstLine = rucksack[:lenHalfLine]
    secondLine = rucksack[lenHalfLine:]

            
    for item in firstLine:
        if item in secondLine:
            return getItemPriority(item)

    return 0



def getSumPrioritiesInBoth():
    
    sumPriorities = 0
    
    with open(rucksacksFile, 'r') as rucksacksF:
        rucksacks = rucksacksF.readlines()
        
        
        for rucksack in rucksacks:
            sumPriorities += getPrioritiesIfInBoth(rucksack)


    rucksacksF.close()
    
    return sumPriorities



def getSumPrioritiesBadge():
    
    sumPriorities = 0
    
    with open(rucksacksFile, 'r') as rucksacksF:
        
        firstRucksack = rucksacksF.readline()
        secondRucksack = rucksacksF.readline()
        thirdRucksack = rucksacksF.readline()
        
        
        while firstRucksack != "":
            
            for item in firstRucksack:
                
                if secondRucksack.find(item) != -1 and thirdRucksack.find(item) != -1:
                    sumPriorities += getItemPriority(item)
                    break
            
            firstRucksack = rucksacksF.readline()
            secondRucksack = rucksacksF.readline()
            thirdRucksack = rucksacksF.readline()
            
    
    rucksacksF.close()
    
    return sumPriorities



if __name__ == "__main__":
    
    sumPrioritiesInBoth = getSumPrioritiesInBoth()
    
    print('Answer 1 : The sum of item type that appears in both compartments is : {}'.format(sumPrioritiesInBoth))

    
    sumPrioritiesBadge = getSumPrioritiesBadge()
    
    print('Answer 2 : The sum of item type that corresponds to the badges is : {}'.format(sumPrioritiesBadge))
