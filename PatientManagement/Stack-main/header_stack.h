#ifndef HEADER_STACK_H_INCLUDED
#define HEADER_STACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "header_stack.h"
typedef struct{
int number;
int priority;
} file;
struct node{
    file value ;
    struct node *next;
};
typedef struct node * stack;
//queue
typedef struct node node;

typedef struct
{
    node *front,*back;
}queue;



int emptyStack(stack st);
stack addFile(file F, stack st);
stack removee(stack st);
void displayTop(stack st);
stack place (stack st);
//queue
queue initialize();
int emptyQueue(queue Q);
queue addq(queue Q, stack S);





#endif // HEADER_STACK_H_INCLUDED
