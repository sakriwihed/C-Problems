#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header aids"



int verifyaid ( aid ta[], int na, char designation[])
{
    int test,i;
    test=0;
    for (i=0; i<na; i++)
    {
        if(strcmp(ta[i].designation,designation)==0)
            test=i;
    }
    return test;
}
void enteraid(aid *a)
{
    printf("enter the designation of the new aid\n ");
    fflush (stdin);
    gets((*a).designation);
    printf("enter the type of the new aid\n ");
    scanf("%d",&(*a).type);
    printf("enter the quantity of the new aid\n ");
    scanf("%d",&(*a).quantity);
}
void addaid(aid ta[], int *na, aid a)
{
    enteraid(&a);

    if (verifyaid(ta,na,a.designation)==0)
        {ta[*na]=a;
        (*na)++;}
    else
        ta[verifyaid(ta,na,a.designation)].quantity++;
}
void displayaids(aid ta[], int na)
{
    int i;
    for (i=0; i<na; i++)
    {
        printf("the designation of the aid %d is %s",i+1,ta[i].designation);
        printf("the type of the aid %d is %d",i+1,ta[i].type);
        printf("the quantity of the aid %d is %d",i+1,ta[i].quantity);

    }
}
void fillfamilies(family tf[], int nf)
{
        int i;
        for (i=0; i<nf; i++)
        {
            printf ("enter the nic of the head of the family %d\n",i+1);
            scanf("%d",&tf[i].NIC);
            printf ("enter the number of members in the family %d\n",i+1);
            scanf("%d",&tf[i].number);
            printf ("enter the associated delegation of the family %d\n",i+1);
            fflush(stdin);
            gets(tf[i].delegation);
        }


}
void displayfamilies(family tf[], int nf)
{
        int i;
        for (i=0; i<nf; i++)
        {
            printf("the nic of the family %d is %d ",i+1,tf[i].NIC);
            printf("the number of members in the family %d is %d",i+1,tf[i].number);
            printf("the associated delegation of the family %d is %s",i+1,tf[i].delegation);
        }

}
void max_min_aid(aid ta[], int na, int *min, int *max)
{
        int i,j;
        (*max)=0;
        for(i=1; i<na; i++)
        {
            if (ta[i].quantity>ta[(*max)].quantity)
                (*max)=i;
        }
        (*min)=0;
        for(j=1; j<na; j++)
        {
            if (ta[j].quantity<ta[(*min)].quantity)
                (*min)=j;
        }
}
int maxmember(family tf[], int nf)
    {
        int maxm,i;
        maxm=0;
        for(i=1; i<nf; i++)
        {
            if (tf[i].number>tf[maxm].number)
                maxm=i;
        }
        return i;
    }
void deletefamily (family tf[], int *nf, int pos)
    {
        int i;
        for (i=pos; i<(*nf)-1; i++)
        {
            tf[i]=tf[i+1];
        }
        *nf--;
    }
void allocateaid(family tf[], int *nf, aid ta[], int na)
    {
        int i;
        family fam;
        fam=tf[maxmember(tf,*nf)];
        i=0;
        while(i<na &&ta[i].type!=1)
            i++;
        if (i<na)
        {
            ta[i].quantity=ta[i].quantity-fam.number;
        }
        i=0;
        while(i<na &&ta[i].type!=2)
            i++;
        if (i<na)
        {
            ta[i].quantity=ta[i].quantity-fam.number;
        }
        i=0;
        while(i<na &&ta[i].type!=3)
            i++;
        if (i<na)
        {
            ta[i].quantity=ta[i].quantity-1;
        }
        deletefamily(tf,&nf,maxmember(tf,*nf));

}

void checkstock( aid ta[], int na, aid tstock[], int *ns)
{   int i;
    (*ns)=0;

    for (i=0; i<na; i++)
    {
        if (ta[i].quantity<=5){
            tstock[*ns]=ta[i];
            (*ns)++;
        }

    }
}
