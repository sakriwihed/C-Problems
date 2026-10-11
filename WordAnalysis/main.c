#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{   char ch[10],s[100],w[10];
    char mat[7][8]={"pbl","it","our","is","session","seventh"};
    char correct[7][8]={"it","is","our","seventh","pbl","session",};
    char sen[7][8];
    int i,j,nb,choice,num,order;
    printf ("*** menu***\n 1-display the words and their number \n 2-display the vowels and their number in a word \n3-compose a sentence\n0-quit\n");
    printf("enter your choice ");
    scanf("%d",&choice);
    switch (choice ){
    case 1:
        printf("enter a sentence\n");
        getchar();
        gets(s);
        strcpy(ch,"");
        i=0;
        j=0;
        nb=0;
        while (i<strlen(s)){
        if ((s[i]!=' ')&&(s[i]!='.'))
        {
            ch[j]=s[i];
            j++;
        }
        else{
            ch[j]='\0';
            nb++;
            printf("word %d :%s\n",nb,ch);
            j=0;
        }
        i=i+1;
        }

    break;
    case 2:
        printf("enter a word ");
        getchar();
        gets(w);
        i=0;
        num=0;
        while (i<strlen(w)){
            if ((w[i]=='o')||(w[i]=='e')||(w[i]=='a')||(w[i]=='i')||(w[i]=='y')||(w[i]=='u')){
                num++;
                printf("%c\n",w[i]);
                i++;
            }
            else
                i++;
        }
        printf("the number of vowels is %d",num);
        break;
    case 3:

        printf("here's the list of the words:\n ");
        for (i=0;i<6;i++){
            printf("%s-",mat[i]);
            }
        printf("\n");

        for (i=0;i<6;i++){
            printf("enter the order of the word %s",mat[i]);
            scanf("%d",&order);
            strcpy(sen[order-1],mat[i]);
            }

        j=0;
        while ((j<6)&&(strcmp(sen[j],correct[j])==0))
            j++;
        printf("\n");
        for (i=0;i<6;i++){
            printf ("%s ",sen[i]);}
        if (j<6)
            printf("  doesnt make sense!");
        else
            printf("  is true ");


        break;





    }




    return 0;
}
