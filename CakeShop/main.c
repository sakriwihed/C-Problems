#include <stdio.h>
#include <stdlib.h>
#include "cake header.h"

int main()
{   cake c,tabc[50];
    int matv[5][7],type,day;
    float tabp[50];
    int tc,choice,pos;
    do{
    printf("**the menu**\n1-add a cake\n2-display the array of cakes\n3-find a cake\n4-initialize the sales matrix and the price array\n5-sell a cake\n6-display a recipe\n ");
    do{
    printf("enter your choice\n");
    scanf("%d",&choice);
    }while(choice<0 || choice>6);
    switch (choice)
    {
case 1:
    printf("enter the number of cakes\n");
    scanf("%d",&tc);
    fill(&c);
    addcake(tabc,c,&tc);
    break;
case 2:
    display (tabc,tc);
    break;
case 3:
    printf("enter the type of the cake searched\n");
    scanf("%d",&type);
    find(tabc,tc,type,&pos);
    printf("the position of the cake searched is %d\n",pos);
    break;
case 4:
    initialize(matv,tabp);
    break;
case 5:
    printf("enter the type of the cake sold\n");
    scanf("%d",&type);
    printf("enter the day\n");
    scanf("%d",&day);
    sell(matv,tabc,type,day,&tc,tabp);
    break;
case 6:
    printf("enter the day\n");
    scanf("%d",&day);
    displayrecipe(matv,day,tabp);
    break;

    }
    }while(choice!=0);


return 0;
}
