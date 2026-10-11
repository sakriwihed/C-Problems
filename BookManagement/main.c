#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//exercice 4
struct date{
    int day;
    int month;
    int year;
    };

typedef struct{
    char ref[50];
    char name[50];
    char aname[50];
    struct date datepub;
}book ;


int main()

{   int i,n,choice,j,swap;
    char newbook[50];
    book tab[50];
    book b,aux;


    //we must fill a table of books first to be able to work with them
    printf("enter the number of books that already exist\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the name \n");
        scanf("%s",b.name);
        printf("enter the reference \n");
        scanf("%s",b.ref);
        printf("enter the authors name \n");
        scanf("%s",b.aname);
        printf("enter the day of publication\n");
        scanf("%d",&b.datepub.day);
        printf("enter the month of publication\n");
        scanf("%d",&b.datepub.month);
        printf("enter the year of publication\n");
        scanf("%d",&b.datepub.year);
        tab[i]=b;
        }
    printf("1-add a book\n2-display the table of books\n3-sort the array in descending order of reference\n");
    do{
        printf("enter your choice");
        scanf("%d",&choice);
    }while((choice<0)||(choice>3));
    switch(choice){
    case 1:
        printf("enter the reference of the book you want to add\n");
        scanf("%s",newbook);
        j=0;
        while((j<n)&&(tab[j].ref!=newbook))
            j++;
        if (j==n){
            strcpy(tab[n].ref,newbook);
            printf("enter the name of the new book\n");
            scanf("%s",tab[n].name);
            printf("enter the authors name of the new book\n");
            scanf("%s",tab[n].aname);
            printf("enter the day of publication of the new book\n");
            scanf("%d",&tab[n].datepub.day);
            printf("enter the month of publication of the new book\n");
            scanf("%d",&tab[n].datepub.month);
            printf("enter the year of publication of the new book\n");
            scanf("%d",&tab[n].datepub.year);
            n++;
        }
        else
            printf("book already exists!\n");
        break;
    case 2:
        for(i=0;i<n;i++){
            printf("book number %d\n",i+1);
            printf("name %s\n",tab[i].name);
            printf("authors name %s\n",tab[i].aname);
            printf("reference %s\n",tab[i].ref);
            printf("day of pub %d\n",tab[i].datepub.day);
            printf("month of pub %d\n",tab[i].datepub.month);
            printf("year of pub %d\n",tab[i].datepub.year);
        }
        break;
    case 3:
        do{
            swap=0;
            for(i=0;i<n-1;i++ ){
                if(tab[i].ref<tab[i+1].ref )
                    {// swap
                    aux=tab[i];
                    tab[i]=tab[i+1];
                    tab[i+1]=aux ;
                    swap=1;}
                    }
        }while(swap==1);
        break;

    }
return 0;
}
