#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_binary.h"


void number_children(char number_children[100])
{   FILE *f=NULL;
    employee e;
    f=fopen("number_children.txt","a");
    if (f!=NULL){
    printf("enter the last name\n");
    fflush(stdin);
    gets(e.last_name);
    printf("enter the first name\n");
    fflush(stdin);
    gets(e.first_name);
    printf("enter the number of children\n");
    scanf("%d",&e.number);
    fwrite( &e, sizeof(employee), 1, f);
    fclose(f);

}
}
void search_first_name(char number_children[100],char ch[10])
{   FILE *f;
    employee e;
    int nb=0;
    f=fopen("number_children.txt","r");
    if (f!=NULL){
            while (fread(&e, sizeof(employee),1, f)!=EOF){
                if (strcmp(ch,e.last_name)){
                    nb=1;
                    printf("the name is %s, the last name is %s\n",e.first_name,e.last_name);

                }
                if (nb==0)
                    printf("the last name you searched does exist\n");
                }
}
fclose(f);
}

void incorporate(char number_children[100],int n)
{   FILE *f;
    employee e;
    f=fopen("number_children.txt","r");
    if (f!=NULL){

    while (fread( &e, sizeof(employee), 1, f)!=EOF){
    if(e.number>=n)
        printf("the employee whose name is %s is considered\n",e.first_name);

    }
    }
fclose(f);
}
void delete_0(char number_children[100])
{
    employee e;
    FILE *f2=NULL;
    FILE *f=NULL;
    f=fopen("number_children.txt","w");
    f2=fopen("temporary.txt","w");
    if (f!=NULL && f2!=NULL){
        while (fread( &e, sizeof(employee), 1, f)!=EOF){
            if(e.number==0){
                fwrite( &e, sizeof(employee), 1, f2);
                }
        }
    }
    fclose(f2);
    fclose(f);
    remove("number_children.txt");
    rename("temporary.txt","number_children.txt");
}
void save(char number_children[100],employee t[100],int *n)
{
    FILE *f;
    employee e;
    *n=0;
    f=fopen("number_children.txt","r");
    if (f!=NULL){
            while (fread( &e, sizeof(employee), 1, f)!=EOF){
                t[*n]=e;
                (*n)++;
            }
    }
}
void sortt(char number_children[100],employee t[100],int *n)
{   int i,j,min;
    employee aux;
    for (i=0;i<*n;i++)
        {
            min=i;
            for (j=i+1;j<*n;j++)
            {
                if (t[j].number<t[min].number)
                    min=j;
            }
    aux=t[i];
    t[i]=t[min];
    t[min]=aux;
    }
}
