#!/usr/bin/env python3

dSBufferFile = "input"


def getMarker(nbDistinctCharacters):
    
    nbChar = 0
    
    valid = True
    
    
    with open(dSBufferFile, 'r') as dSBuffer:
        message = dSBuffer.readline()
    
    dSBuffer.close()
    
        
    for i in range(len(message) - nbDistinctCharacters):
        
        subMessage = message[i:i+nbDistinctCharacters]
        valid = True
        
        for j in range(nbDistinctCharacters):
            
            if subMessage[j] in subMessage[j + 1: nbDistinctCharacters]:
                valid = False
                break
            
            
        if valid == True:
            nbChar = i
            break
    
    
    return nbChar + nbDistinctCharacters
        


if __name__ == "__main__":
    
    nbCharacters4 = getMarker(4)
    
    print('Answer 1 : {} characters need to be processed.'.format(nbCharacters4))

    
    nbCharacters14 = getMarker(14)
    
    print('Answer 2 : {} characters need to be processed.'.format(nbCharacters14))
