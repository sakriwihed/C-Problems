#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{   int len1,len2,i,j;
    //using the predefined functions
    char ch1[50];
    char ch2[50];
    char ch3[50]="";
    printf("enter a string 1");
    gets(ch1);
    printf("enter a string 2");
    gets(ch2);
    strncpy(ch3,ch1,strlen(ch1)/2);
    strncat(ch3,ch2,strlen(ch2)/2);
    printf("%s",ch3);
    //without using the predefined functions
    len1=0;
    while (ch1[len1]!='\0'){
        len1=len1+1;
    }
    len1--;
    i=0;
    while (i<=(len1/2))
    {
        ch3[i]=ch1[i];
        i++;
    }
    len2=0;
    while (ch2[len2]!='\0'){
        len2=len2+1;
    }
    len2--;
    j=0;
    while (j<=(len2/2))
    {
        ch3[j+(len1/2)+1]=ch2[j];
        j++;
    }

    printf("%s",ch3);



    return 0;
}
