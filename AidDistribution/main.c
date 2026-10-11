#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_aids.h"

int main()
{
    int c;
    aid a;
    int na = 0, ns = 0, nf = 0;
    aid ta[100], tstock[100];
    family tf[100];
    int max = -1;
    int min = -1;

    do {
        do {
            printf("**menu**\n0-quit\n1-add a new aid\n2-display the array of aids\n3-fill in the families array\n4-display the families array\n5-find the aid with the highest and the smallest quantity\n6-assign an aid to a family\n7-find and display the aids with quantity less than or equal to 5\n");
            printf("enter your choice\n");
            scanf("%d", &c);
        } while (c < 0 || c > 7);

        switch (c) {
        case 1:
            addaid(ta, &na, a);
            break;
        case 2:
            displayaids(ta, na);
            break;
        case 3:
            printf("enter the size of the families array\n");
            scanf("%d", &nf);
            fillfamilies(tf, nf);
            break;
        case 4:
            displayfamilies(tf, nf);
            break;
        case 5:
            if (na > 0) {
                max_min_aid(ta, na, &min, &max);
                printf("the max aid is at position %d and the min aid is at position %d\n", max + 1, min + 1);
            } else {
                printf("no aids yet\n");
            }
            break;
        case 6:
            allocateaid(tf, &nf, ta, na);
            break;
        case 7:
            checkstock(ta, na, tstock, &ns);
            displayaids(tstock, ns);
            break;
        }
    } while (c != 0);

    return 0;
}
