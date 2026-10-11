#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int carnum;
    int price;
    int state;
}vehicle;
int exist_id(int pos,int x,vehicle T[],int n)
{   int t,i;
    t=-1;
    for (i=0;i<pos;i++){
        if (x==T[i].id)
        t=1;
    }
    return t;
}
int exist_num(int pos,int x,vehicle T[],int n)
{   int t,i;
    t=-1;
    for (i=0;i<pos;i++){
        if (x==T[i].carnum)
        t=1;
    }
    return t;
}
void fill(vehicle T[],int n ){
    int i;
    for (i=0;i<n;i++){
        do{
        printf("enter the id \n");
        scanf("%d",&T[i].id);
        }while(exist_id(i,T[i].id,T,n)==1);
        do{
        printf("enter the number of the car \n");
        scanf("%d",&T[i].carnum);
        }while(exist_num(i,T[i].carnum,T,n)==1);
        printf("enter the price \n");
        scanf("%d",&T[i].price);
        printf("enter the state\n");
        scanf("%d",&T[i].state);
        }
}
void display(vehicle T[],int n)
{   int i;
    for (i=0;i<n;i++){
        printf("the id of the car %d is %d\n",i+1,T[i].id);
        printf("the number of the car %d is %d\n",i+1,T[i].carnum);
        printf("the rental price of the car %d is %d\n",i+1,T[i].price);
        printf("the state of the car %d is %d\n",i+1,T[i].state);
    }
}
int search(int x,vehicle T[],int n)
{   int t,i;
    t=-1;
    for (i=0;i<n;i++){
        if (x==T[i].id)
        t=i;
    }
    return t;
}
int search_cheap(vehicle T[],int n)
{   int pos,i,min;
    pos=0;
    min=T[0].price;
    for(i=1;i<n;i++){
        if (T[i].price<min){
            min=T[i].price;
            pos=i;
        }
    }
    return(T[pos].id);
}
int num_leased(vehicle T[],int n)
{   int nb,i;
    nb=0;
    for (i=0;i<n;i++){
        if (T[i].state==1)
            nb++;
    }
    return nb;
}

int main()
{   int n,idd,t;
    vehicle T[50];
    printf("enter the number of vehicles\n");
    scanf("%d",&n);
    fill(T,n);
    display(T,n);
    printf("enter the id of the car you want to display its details\n");
    scanf("%d",&idd);
    t=search(idd,T,n);
    printf("the number of the given car is %d\n",T[t].carnum);
    printf("the rental price of the given car is %d\n",T[t].price);
    printf("the state of the given car is %d\n",T[t].state);
    printf("the cheapest car is whose id is %d\n",search_cheap(T,n));
    printf("the number of cars leased is %d\n",num_leased(T,n));
    printf("the percentage of cars leased is %.2f%%\n",(float)num_leased(T,n)*100/n);




    return 0;
}
