#ifndef HEADER_BINARY_H_INCLUDED
#define HEADER_BINARY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char last_name[10];
    char first_name[10];
    int number;

}employee;
void number_children(char number_children[100]);
void search_first_name(char number_children[100],char ch[10]);
void incorporate(char number_children[100],int n);
void delete_0(char number_children[100]);
void save(char number_children[100],employee t[100],int *n);
void sortt(char number_children[100],employee t[100],int *n);


#endif // HEADER_BINARY_H_INCLUDED
