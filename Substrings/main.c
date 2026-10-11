#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   char s[50],ch[50];
    int n,m,ok,i,j;

    gets(s);
    gets(ch);
    n=strlen(s);
    m=strlen(ch);
    ok=0;
    for(i=0;i<n-m+1;i++)
    {
       if(s[i]==ch[0])
       {
         for(j=0;j<m;j++)
           if(s[i+j]!=ch[j])
                break;
            if(j==m)
                ok=1;
       }
       if(ok==1)
            break;
    }
    if(ok==1)
        printf("%s est une sous chaine de %s.\n",ch,s);
    else
        printf("%s n'est pas une sous chaine de %s.\n",ch,s);
    system("pause");
    return 0;
}
