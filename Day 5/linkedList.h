#ifndef LINKED_LIST_H
#define LINKED_LIST_H


struct node{
    char val;
    struct node * next;
};


void printStack(struct node * stack);

int addBegin(struct node ** stack, const char val);

char pop(struct node ** stack);

int push(struct node ** stack, const char val);

char getLast(struct node * stack);


#endif
