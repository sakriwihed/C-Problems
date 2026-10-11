#include <stdio.h>
#include <stdlib.h>
#include "header_stack.h"

int main()
{
    file F;
    stack st = NULL;

    int choice;
    do
    {
        printf("\n0.Quit\n");
        printf("1.add folder\n");
        printf("2.remove folder\n");
        printf("3.display folder\n");
        printf("4.sort stack\n");
        scanf("%d",&choice);
        if(choice != 0)
        {
            switch(choice)
            {
                case 1:
                        printf("give number of Files: ");
                        scanf("%d",&(F.number));
                        printf("give priority of Files: ");
                        scanf("%d",&(F.priority));
                        st= addFile(F,st);
                break;
                case 2:
                    st= removee(st);
                break;
                case 3:
                    displayTop(st);
                break;
                case 4:
                    st= place(st);
                break;
            }
        }
    }while(choice!=0);

    return 0;
}
