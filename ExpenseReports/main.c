#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

typedef struct
{
    int id;
    char lname[20];
    char fname[20];
    float ceiling;

}member;
typedef struct{
 int type ;
 int memberid;
 int ref;
 float price;

}report;
member enterad();
int menu();
int exist(int n,member t[],int x);
void addadherent(int n,member t[]);
void displaymember(int n, member t[]);
report enterreport();
void initialize ();
void addreport(report r,report m[3][5],int type);
void displayreport(report m[3][5]);
report findreport(int reff,report m[3][5]);
int checkrefund (int reff,report m[3][5]);
void update (int reff);
int (int type,report m[3][5]);




int main()
{

    return 0;
}
int menu(){
printf("**menu**\n1-enter a member\n2-add adherent\n3-display adherents\n4-enter report\n5-initialize the reference of the reports\n6-add report \n7-display reports\n8-find a given report\n9-check refund \n-10update the reimbursement limit\n11-calculate");


}
member enterad()
{   member m;
    printf ("enter the id\n");
    scanf("%d",&m.id);
    printf ("enter the last name\n");
    fflush(stdin);
    gets(m.lname);
    printf ("enter the first name\n");
    fflsush(stdin);
    gets(m.fname);
    printf("enter the reimbursement ceiling\n");
    scanf("%f",&m.ceiling);
    return m;
}
int exist(int n,member t[],int x){
    int i=0;
    while (i<n&& t[i].id!=x)// if exist==n the element doesnt exist
        i++;
    return i;
}
void addadherent(int n,member t[])
{   member mem;
    printf ("enter the id\n");
    scanf("%d",&mem.id);
    printf ("enter the last name\n");
    fflush(stdin);
    gets(mem.lname);
    printf ("enter the first name\n");
    fflsush(stdin);
    gets(mem.fname);
    printf("enter the reimbursement price\n");
    scanf("%f",&mem.price);
    if (exist(n,t,mem.id)==n)
        t[n]=mem;
    else
        printf("the member already exists\n");
}
void displaymember(int n, member t[])
{
    int i;
    for (i=0;i<n;i++){
        printf("the first name is %s\n",t[i].fname);
        printf("the last name is %s\n",t[i].lname);
        printf("the id is %d\n",t[i].id);
        printf("the reimbursement ceiling is %.2f\n",t[i].ceiling);
        }
}
report enterreport()
{
    report r;
    printf ("enter the type\n");
    scanf("%d",&r.type);
    printf ("enter the member id\n");
    scanf("%d",&r.memberid);
    printf ("enter the reference\n");
    scanf("%d",&r.ref);
    printf("enter the reimbursement price\n");
    scanf("%f",&r.price);
    if (exist(n,t,r.memberid)==n)
        printf("the member doesnt exist!\n");
        return 0;
    else
        return r;
}
void initialize(report m[5][3])
{   int i,j;
    for(j=0;j<5;j++){
        for (k=0;k<3;k++){
            m[j][k].ref=0;
        }
    }
}
void addreport(report r,report m[3][5],int type)
{   int ty,i;
    ty=r.type;
    switch (ty){
    case 0:
        i=0;
        while (i<5 && m[0][i]==0)
            i++;

        if (i<5)
            m[0][i]=r;
        else
            printf("the line is full!\n");
        break;
    case 1:
        i=0;
        while (i<5 && m[1][i]==0)
            i++;

        if (i<5)
            m[1][i]=r;
        else
            printf("the line is full!\n");
        break;
    case 2:
        i=0;
        while (i<5 && m[2][i]==0)
            i++;

        if (i<5)
            m[2][i]=r;
        else
            printf("the line is full!\n");
        break;

    }
}
void displayreport(report m[3][5])
{   int i,j;
    for (i=0;i<3;i++){
        for (j=0;j<5;i++){
            printf("the type is %d\n",m[i][j].type);
            printf("the member id is%d\n",m[i][j].id);
            printf("the reference is %d\n",m[i][j].ref);
            printf("the reimbursement price is %.2f\n",m[i][j].price);
            }
    }
}
report findreport(int reff,report m[3][5]);




