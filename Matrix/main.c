#include <stdio.h>
#include <stdlib.h>

int main()
{   int mat[10][10];
    int max[10];
    int min [10];

    int n,i,j,maxx,m;
    //part 1 of the ex
    do{
    printf("Number of rows and columns(max.10) : ");
    scanf("%d", &n);
    }while ((n<0)||(n>10));
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            printf("Element[%d][%d] in mat : ",i,j);
            scanf("%d", &mat[i][j]);
        }
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            printf("%7d|", mat[i][j]);
            printf("\n");
    }
    i=-1;
    for (j=0;j<n;j++){
        i=i+1;
        printf("%d",mat[i][j]);

    }
    printf("\n");
    //part 2 of the ex
    i=0;
    do{
    for (j=0;j<n;j++){}
        maxx=mat[i][0];
        if (mat[i][j]>maxx)
            maxx=mat[i][j];
        max[j]=maxx;
        i=i+1;

    }while(i<=n);


    for (m=0;m<n;m++)
        printf("%d|",max[m]);





    return 0;
}
