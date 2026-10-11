#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_aids.h"

/* reads a line of text and removes the newline at the end */
static void readline(char s[], int size)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); /* clear the rest of the previous input */
    fgets(s, size, stdin);
    s[strcspn(s, "\n")] = '\0';
}

/* returns the position of the aid, or -1 if it does not exist */
int verifyaid(aid ta[], int na, char designation[])
{
    int i;
    for (i = 0; i < na; i++)
    {
        if (strcmp(ta[i].designation, designation) == 0)
            return i;
    }
    return -1;
}

void enteraid(aid *a)
{
    printf("enter the designation of the new aid\n");
    readline(a->designation, sizeof(a->designation));
    printf("enter the type of the new aid\n");
    scanf("%d", &a->type);
    printf("enter the quantity of the new aid\n");
    scanf("%d", &a->quantity);
}

void addaid(aid ta[], int *na, aid a)
{
    int pos;
    enteraid(&a);
    pos = verifyaid(ta, *na, a.designation);
    if (pos == -1)
    {
        ta[*na] = a;
        (*na)++;
    }
    else
        ta[pos].quantity += a.quantity;
}

void displayaids(aid ta[], int na)
{
    int i;
    for (i = 0; i < na; i++)
    {
        printf("the designation of the aid %d is %s\n", i + 1, ta[i].designation);
        printf("the type of the aid %d is %d\n", i + 1, ta[i].type);
        printf("the quantity of the aid %d is %d\n", i + 1, ta[i].quantity);
    }
}

void fillfamilies(family tf[], int nf)
{
    int i;
    for (i = 0; i < nf; i++)
    {
        printf("enter the nic of the head of the family %d\n", i + 1);
        scanf("%d", &tf[i].NIC);
        printf("enter the number of members in the family %d\n", i + 1);
        scanf("%d", &tf[i].number);
        printf("enter the associated delegation of the family %d\n", i + 1);
        readline(tf[i].delegation, sizeof(tf[i].delegation));
    }
}

void displayfamilies(family tf[], int nf)
{
    int i;
    for (i = 0; i < nf; i++)
    {
        printf("the nic of the family %d is %d\n", i + 1, tf[i].NIC);
        printf("the number of members in the family %d is %d\n", i + 1, tf[i].number);
        printf("the associated delegation of the family %d is %s\n", i + 1, tf[i].delegation);
    }
}

void max_min_aid(aid ta[], int na, int *min, int *max)
{
    int i;
    *max = 0;
    *min = 0;
    for (i = 1; i < na; i++)
    {
        if (ta[i].quantity > ta[*max].quantity)
            *max = i;
        if (ta[i].quantity < ta[*min].quantity)
            *min = i;
    }
}

/* returns the position of the family with the most members */
int maxmember(family tf[], int nf)
{
    int maxm = 0, i;
    for (i = 1; i < nf; i++)
    {
        if (tf[i].number > tf[maxm].number)
            maxm = i;
    }
    return maxm;
}

void deletefamily(family tf[], int *nf, int pos)
{
    int i;
    for (i = pos; i < (*nf) - 1; i++)
    {
        tf[i] = tf[i + 1];
    }
    (*nf)--;
}

/* gives aids to the biggest family, then removes it from the list */
void allocateaid(family tf[], int *nf, aid ta[], int na)
{
    int i, pos;
    family fam;

    if (*nf == 0)
    {
        printf("no families left\n");
        return;
    }
    pos = maxmember(tf, *nf);
    fam = tf[pos];

    i = 0;
    while (i < na && ta[i].type != 1)
        i++;
    if (i < na)
        ta[i].quantity -= fam.number;

    i = 0;
    while (i < na && ta[i].type != 2)
        i++;
    if (i < na)
        ta[i].quantity -= fam.number;

    i = 0;
    while (i < na && ta[i].type != 3)
        i++;
    if (i < na)
        ta[i].quantity -= 1;

    deletefamily(tf, nf, pos);
}

void checkstock(aid ta[], int na, aid tstock[], int *ns)
{
    int i;
    *ns = 0;
    for (i = 0; i < na; i++)
    {
        if (ta[i].quantity <= 5)
        {
            tstock[*ns] = ta[i];
            (*ns)++;
        }
    }
}
