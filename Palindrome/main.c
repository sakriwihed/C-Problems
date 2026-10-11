#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   char ch[50];
    int i=0;
    printf("enter a string\n");
    fflush(stdin);
    gets(ch);
    if((strlen(ch)%2)!=0){
    while((i<=(strlen(ch)/2))&&(ch[i]==ch[strlen(ch)-i-1]))
        i=i+1;
    if (i>(strlen(ch)/2))
        printf("palindrome");
    else
        printf("not palindrome ");
    }
    else
    printf("not palindrome ");
    return 0;
}
