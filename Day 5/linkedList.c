#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"



void printStack(struct node * stack){
    
    while(stack != NULL){
        printf("%c ", stack->val);
        stack = stack->next;
    }
    
    printf("\n");

}



int addBegin(struct node ** stack, const char val)
{
    struct node * nextNode = NULL;
    

    if(*stack != NULL){
        nextNode = *stack;
    }
    

    *stack = malloc(sizeof(struct node));    
    
    if(*stack == NULL){
    
        fprintf(stderr, "Impossible to allocate memory (node)");
        return -1;
    }
    
    
    (*stack)->val = val;
    (*stack)->next = nextNode;
    
    return 0;
}



char pop(struct node ** stack){

    char val = '-';
    
    struct node * tmpNode = NULL;

    
    if(*stack == NULL){
        return '-';
    }
    
    
    
    if((*stack)->next == NULL)
    {
        val = (*stack)->val;
        free(*stack);
        *stack = NULL;
        return val;
    }
    
    
    
    tmpNode = *stack;
    
    while((tmpNode->next)->next != NULL){
        tmpNode = tmpNode->next;
    }
    
    val = (tmpNode->next)->val;
    free(tmpNode->next);
    tmpNode->next = NULL;
    
    
    return val;
}



int push(struct node ** stack, const char val){
    
    struct node * newNode = NULL;
    struct node * tmpNode = NULL;
    
    
    if(*stack == NULL){
        
        *stack = malloc(sizeof(struct node));
        
        if(*stack == NULL)
        {
            fprintf(stderr, "Impossible to allocate memory (node)");
            return -1;
        }
        
        else
        {
            (*stack)->val = val;
            (*stack)->next = NULL;
            return 0;
        }
    }
    
    
    
    tmpNode = *stack;
    
    while(tmpNode->next != NULL)
    {
        tmpNode = tmpNode->next;
    }
    
    
    newNode =  malloc(sizeof(struct node));
    
    if(newNode == NULL)
    {
        fprintf(stderr, "Impossible to allocate memory (node)");
        return -1;
    }
    
    else
    {
        newNode->val = val;
        newNode->next = NULL;
        tmpNode->next = newNode;
        return 0;
    }
    
    
    return 0;
    
}



char getLast(struct node * stack){

    if(stack == NULL){
        return '-';
    }
    
    while(stack->next != NULL){
        stack = stack->next;
    }
    
    return stack->val;
}
