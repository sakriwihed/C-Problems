#include <stdio.h>
#include <stdlib.h>
#include "header_stack.h"
//stack
int emptyStack(stack st)
{
    if (st==NULL)
        return 1;
    else
        return 0;

}
stack addFile(file F, stack st){
    stack nw ;
    nw=malloc(sizeof(struct node));
    nw->value=F;
    nw->next=st;
    st=nw;
    return st;
}
stack removee(stack st){
    stack del;
    if(emptyStack(st)==0){
        del=st;
        st=st->next;
        free(del);
    }
    else
        printf("stack is empty\n");
    return st;
}
void displayTop(stack st){
    if (emptyStack(st)==0)
        printf("file is empty\n");
    else
        printf("%d %d",st->value.number,st->value.priority);
}
stack place (stack st)
{
    stack st1 = NULL, st2 = NULL;
    while(emptyStack(st)==0)
    {
        if(st->value.priority ==1)
        {
            st1= addFile(st->value,st1);
            st = removee(st);
        }
        else
        {
            st2 = addFile(st->value,st2);
            st= removee(st);
        }
    }
    while(emptyStack(st2)==0)
    {
        st= addFile(st2->value,st);
        st2 = removee(st2);
    }
    while(emptyStack(st1)==0)
    {
        st= addFile(st1->value,st);
        st1 = removee(st1);
    }
    return st;
}


//queue
queue initialize()
{
    queue Q;
    Q.front = NULL;
    Q.back = NULL;
    return Q;
}

int emptyQueue(queue Q)
{
    if (Q.front == NULL && Q.back == NULL)
        return 1;
    else
        return 0;
}

queue addq(queue Q, stack st)
{
    if (emptyQueue(Q)==1)
    {
        Q.front =st;
        Q.back =st;
        st= removee(st);
    }
    else
    {
        (Q.back)->next = st;
        Q.back =st;
        st= removee(st);
    }
    return Q;
}







