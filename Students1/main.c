#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char name [20];
    char class[20];
    int number,age ;
}student;

void swapstrings(char ch1[],char ch2[])
{
    char time [20];
    strcpy(time,ch1);
    strcpy(ch1,ch2);
    strcpy(ch2,time);


}
void enter_student(student *s)
{
    fflush(stdin);
    gets(s->name);
    fflush(stdin);
    scanf("%s",s->class);
    scanf("%d",&s->number);
    scanf("%d",&s->age);//scanf("%d",&((*s)->age))
}
void swapstudent1(student *s1,student *s2)
{
    swapstrings(s1->class,s2->class);//swapstrings((*s1).class,(*s2).class);

}
void swapstudent2(student *s1,student *s2)
{
    char time [20]="";
    strcpy(time,s1->class);
    strcpy(s1->class,s2->class);
    strcpy(s2->class,time);
}
void get_imin_imax(student t[],int n,int *pmin,int *pmax)
{   int i;
    *pmin=0,*pmax=0;
    for (i=0;i<n;i++){
        if (t[i].age>t[*pmax].age)
            *pmax=i;
        if ((*(t+i)).age<(*(t+(*pmin)).age))
        {
            *pmin=i;
        }
    }
}


int main()
{   student s1,s2,t[100];
    enter_student(&s1);
    enter_student(&s2);
    swapstudent1(&s1,&s2);
    swapstudent2(&s1,&s2);
    get_imin_imax(t,n,&min,&max);

    printf("imax=%d and imin=%d\n",max,min);


    return 0;
}
