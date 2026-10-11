#ifndef HEADER_MACHINE_H_INCLUDED
#define HEADER_MACHINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
char ref[50];
int status;
}failure;

typedef struct{
 int id;
 failure fails[10];
}machine;

void entermachine(machine*m);
int searchmachine(machine tm[],int n,int id);
void addmachine(machine tm[],machine m,int *n);
void enterfailure(failure*f);
void addfailure(int id, machine tm[], int n, failure f);
int totalfailures(int id, machine tm[], int n) ;
void modify_status_failure (int id, machine tm[], int n) ;
void display (int n, machine tm[],int id);
void find (machine tm[], int n, int *n_rep, int *n_nrep, int id);
void delete (machine tm[], int *n);



#endif // HEADER_MACHINE_H_INCLUDED
