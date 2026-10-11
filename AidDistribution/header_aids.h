#ifndef HEADER_AIDS_H_INCLUDED
#define HEADER_AIDS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char designation[50];
    int type;
    int quantity;
} aid;

typedef struct {
    int NIC;
    int number;
    char delegation[50];
} family;

int verifyaid(aid ta[], int na, char designation[]);
void enteraid(aid *a);
void addaid(aid ta[], int *na, aid a);
void displayaids(aid ta[], int na);
void fillfamilies(family tf[], int nf);
void displayfamilies(family tf[], int nf);
void max_min_aid(aid ta[], int na, int *min, int *max);
int maxmember(family tf[], int nf);
void deletefamily(family tf[], int *nf, int pos);
void allocateaid(family tf[], int *nf, aid ta[], int na);
void checkstock(aid ta[], int na, aid tstock[], int *ns);

#endif // HEADER_AIDS_H_INCLUDED
