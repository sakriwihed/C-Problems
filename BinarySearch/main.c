#include <stdio.h>
#include <stdlib.h>

int main()
    //ex1
{
    int find,start,end ,v,n,i,swap1,swap2,aux1,aux2,mid;
    int t1[10];
    int t2[10];
    do{
        printf("enter the size of the arrays\n ");
        scanf("%d",&n);
    }while((n<0)||(n>10));
    for (i=0;i<n;i++){
        printf("enter a value in t1\n");
        scanf("%d",&t1[i]);
        printf("enter a value in t2\n");
        scanf("%d",&t2[i]);
    }
    for (i=0;i<n;i++){
            printf("%d|",t1[i]);
    }
    for (i=0;i<n;i++){
            printf("%d|",t2[i]);
    }
    //the sort
    do{
    swap1= 0;
    for( i=0 ;i<n-1;i++ ){
        if ( t1[i] > t1[i+1] ){
            aux1= t1[i];
            t1[i]= t1[i+1];
            t1[i+1]=aux1 ;
            swap1= 1;
            }
        }
    }while(swap1== 1);
    do{
    swap2=0;
    for( i=0 ;i<n-1;i++ ){
        if ( t2[i] > t2[i+1] ){
            aux2= t2[i];
            t2[i]= t2[i+1];
            t2[i+1]=aux2 ;
            swap2=1;
            }
        }
    }while(swap2== 1);


    //dichotomous search
    printf("enter the value you are looking for \n");
    scanf("%d",&v);
    find=-1; start=0 ; end=n-1 ;
    while ((find==-1)&&(start<= end)){
    mid=(start + end)/2;
    if (t2[mid] > v )
        end=mid-1;
    else if (t2[mid]<v)
        start= mid+1;
    else
        find=1;
    }
    if (find==1)
        printf("the value searched is found!\n");
    else
        printf("the value searches not found !\n");

    return 0;
}
