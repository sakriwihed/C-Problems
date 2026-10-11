#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_aids.h"

int main()
{   int c;
    aid a;
    int *na,*ns;
    aid ta[100],tstock[100];

    family tf[100];
    int max=-1;
    int min=-1;
    do{
    do{
    printf("**menu**\n0-quit\n1-add a new aid\n2-display the array of aids\n3-fill in the families array\n4-display the families array\n5-find the aid with the highest amount of available quantity and with the smallest quantity\n6-assign an aid to a family\n7-find and display the aids with quantity less than or equal to 5\n ");
    printf("enter your choice\n");scanf("%d",&c);
    }while (c<0||c>7);
    printf("enter the size of the families array\n");
    scanf("%d",&nf);

    switch(c){
    case 1:
        addaid(ta,&na,a);
        break;
    case 2:
        displayaids(ta,na);
        break;
    case 3:
        fillfamilies(tf,nf);
        break;
    case 4:
        displayfamilies(tf[],nf);
        break;
    case 5:
        max_min_aid(ta[],na,&min, &max);
        printf("the max aid is the aid of position %d and the min one is of position %d\n",max,min);

        break;
    case 6:
        allocateaid(tf,&nf,ta,na);
        break;
    case 7:
        checkstock(ta,na,tstock,&ns);
        displayaids(tstock[],*ns);
        break;
    }
} while(c!=0);
    return 0;
}
