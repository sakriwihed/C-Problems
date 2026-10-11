#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "cake header.h"

void fill (cake *c)
{   int i;

    printf("enter the cake type\n");
    scanf("%d",&(*c).type);
    printf("enter the number of ingredients\n ");
    scanf("%d",&(*c).num_ingredients);
    for (i=0;i<(*c).num_ingredients;i++){
        printf("enter the designation\n");
        fflush(stdin);
        gets((*c).arr[i].designation);
        printf("enter the quantity of ingredients\n");
        scanf("%d",&(*c).arr[i].quantity);
        printf("enter the unit price \n");
        scanf("%f",&(*c).arr[i].unit);

    }

}
void addcake ( cake tabc[], cake c, int * tc)
{   if ((*tc)<50){
    tabc[*tc]=c;
    (*tc)++;
}
}
void display (cake tabc[], int tc)
{ int i,j;
    for (i=0;i<tc;i++){
        printf("the type is %d\n",tabc[i].type);
        printf("the number of ingredients is %d\n ",tabc[i].num_ingredients);
        for (j=0;j<tabc[i].num_ingredients;j++){
        printf("the designation is %s\n",tabc[i].arr[j].designation);
        printf("the quantity of ingredients is %d\n",tabc[i].arr[j].quantity);
        printf("the unit price is %f\n",tabc[i].arr[j].unit);

    }
}
}
void find(cake tabc[],int tc,int type,int *pos)
{   int i=0;
    (*pos)=-1;
    while ((i<=tc)&&(tabc[i].type!=type)){
        i++;
    }
    if (i<=tc)
        (*pos)=i;
}
float calculateprice(cake c )
{   int i;
    float cost=0,gain,price;
    for (i=0;i<c.num_ingredients;i++){
        cost=cost+(c.arr[i].unit)*(c.arr[i].quantity);
    }
    switch (c.type){
case 0:
    gain=cost*10/100;
    break;
case 2:
    gain=cost*20/100;
    break;
case 1:
    gain=cost*15/100;
    break;
}
price =gain+cost;
return (float) price;
}
void initialize(int matv [][7], float tabp[])
{   int i,j;
    for (i=0;i<3;i++){
        for(j=0;j<7;j++){
            matv[i][j]=0;
        }
    }
    for (i=0;i<7;i++){
        tabp[i]=0;
    }

}
void sell(int matv[][7], cake tabc[], int type, int day, int *tc, float tabp[])
{   int pos,price,i;
    find(tabc,*tc,type,&pos);
    for (i=(pos);i<(*tc);i++){
        tabc[i]=tabc[i+1];
    }
    (*tc)--;
    price=calculateprice(tabc[pos]);
    tabp[day]=tabp[day]+price ;
    matv[type][day]++;
}
void displayrecipe(int matv[][7], int day, float tabp[])
{
    printf("for the day %d the turnover is %f and the quantity of cakes sold for type 0 is %d and for type 1 is %d and for type 2 is %d\n",day,tabp[day],matv[0][day],matv[1][day],matv[2][day]);
}
