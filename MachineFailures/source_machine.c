#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_machine.h"

void entermachine(machine*m)
{   int i;
    printf("enter the machine identifier \n");
    scanf ("%d",&(*m).id);
    for (i=0; i<10; i++)
    { strcat((*m).fails[i].ref,"");
    }
}
int searchmachine (machine tm [],int n, int id)
{
    int i=0;
    while(i<n && tm[i].id!=id)
        i++;
    if (i<n)
        return i;
    else
        return -1;
}
void addmachine(machine tm [],machine m,int *n)
{
    int idd;
    printf("enter the id of the machine you want to add\n");
    scanf("%d",&idd);
    if (searchmachine(tm,n,idd)==-1)
    {
        tm[*n]=m;
        *n++;
    }
    else
        printf("machine already exists\n");
}
void enterfailure(failure * f)
{
    printf("enter the reference of the failure\n");
    scanf("%d",&(*f).ref);
    printf ("enter the status of the failure\n");
    scanf("%d",&(*f).status);
}
void addfailure(int id, machine tm[], int n, failure f)
{
    int fails[10];
    int size=0,i;
    i=searchmachine (tm,n,id);
    if (i!=-1)
    {
        tm[i].fails[size]=f;
        size++;
    }
    else
        printf("machine doesnt even exist !\n");
}
int totalfailures(int id, machine tm[], int n)
{
    int i,tot=0,j;
    i=searchmachine (tm,n,id);
    if (i!=-1)
    {
        for (j=0; j<n; j++)
        {
            if (strcmp(tm[i].fails[j].ref,"")!=0)
                tot++;
        }
    }
    return tot;
}
void modify_status_failure (int id, machine tm[], int n)
{
    int i,j;
    i=searchmachine (tm,n,id);
    if (i!=-1)
    {
        for (j=0; j<10; j++)
        {
            if(tm[i].fails[j].status==0)
                tm[i].fails[j].status=1;
        }

    }
}
void display (int n, machine tm[],int id)
{
    int i,j;
    i=searchmachine (tm,n,id);
    if (i!=-1)
    {
        for (j=0; j<10; j++)
        {
            printf("the reference of failure %d is %s and its status is %d\n",j+1,tm[i].fails[j].ref,tm[i].fails[j].status);
        }
    }
    else
        printf ("machine doesnt even exist!\n");
}
void find (machine tm[], int n, int *n_rep, int *n_nrep, int id)
{
    int i,j;
    *n_rep=0;
    *n_nrep=0;
    i=searchmachine (tm,n,id);
    if (i!=-1)
    {
        for (j=0; j<10; j++)
        {
            if(tm[i].fails[j].status==0)
                *n_nrep++;
            else
                *n_rep++;
        }
    }
        else
            printf ("machine doesnt even exist!\n");
}
void delete (machine tm[], int *n)
    {
        int i,j,n_nrep=0, n_rep=0;
        for (i=0; i<*n; i++)
        {
            find (tm,n,&n_rep,&n_nrep,tm[i].id);
            if(n_rep==totalfailures(tm[i].id,tm,*n))
            {
                for(j=i; j<*n-1; j++)
                {
                    tm[j]=tm[j+1];
                }
                i--;
                *n--;
            }
        }
   }
