#!/usr/bin/env python3

assignmentFileName = "input"


def pairStrToInt(pairStr):
    
    pairSplit = pairStr.split('-')
    pair = list(map(int, pairSplit))
    
    return pair




def isContainOther(firstPair, secondPair):
    
    if (firstPair[0] <= secondPair[0] and firstPair[1] >= secondPair[1]) \
        or (firstPair[0] >= secondPair[0] and firstPair[1] <= secondPair[1]):
        
        return 1
    
    else:
        return 0



def isOverlap(firstPair, secondPair):
    
    if (firstPair[0] <= secondPair[0] and firstPair[1] >= secondPair[1]) \
        or (firstPair[0] >= secondPair[0] and firstPair[1] <= secondPair[1]) \
        or (firstPair[0] <= secondPair[0] and firstPair[1] >= secondPair[0] and firstPair[1] <= secondPair[1]) \
        or (firstPair[0] >= secondPair[0] and firstPair[0] <= secondPair[1] and firstPair[1] >=  secondPair[1]) :
        
        return 1
    
    else:
        return 0



def getNbPairs(isFct):
    
    nbPairs = 0
    
    with open(assignmentFileName, 'r') as assignmentFile:
        
        assignmentPairs = assignmentFile.readlines()
        
        
        for assignmentPair in assignmentPairs:
            
            pairStr = assignmentPair[:-1].split(',')
            
            firstPair = pairStrToInt(pairStr[0])
            secondPair = pairStrToInt(pairStr[1])
            
            
            nbPairs += isFct(firstPair, secondPair)

    
    assignmentFile.close()
    
    return nbPairs



if __name__ == "__main__":
    
    nbPairsContainOther = getNbPairs(isContainOther)
    
    print('Answer 1 : {} assignment pairs does one range fully contain the other.'.format(nbPairsContainOther))

    
    nbPairsOverlap = getNbPairs(isOverlap)
    
    print('Answer 2 : {} assignment pairs do the ranges overlap.'.format(nbPairsOverlap))
