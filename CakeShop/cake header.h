#ifndef CAKE_HEADER_H_INCLUDED
#define CAKE_HEADER_H_INCLUDED
typedef struct{
char designation[100];
int quantity;
float unit;

}ingredient;
typedef struct{
int type;          //(0: chocolate, 1: nougatine, 2:pstachio)
int num_ingredients;
ingredient arr[100];
}cake;
void fill (cake *c);
void addcake ( cake tabc[], cake c, int * tc);
void display (cake tabc[], int tc);
void find(cake tabc[],int tc, int type, int *pos);
float calculateprice(cake c );
void initialize(int matv [][7], float tabp[]);
void sell(int matv[][7], cake tabc[], int type, int day, int *tc, float tabp[]);
void displayrecipe(int matv[][7], int day, float tabp[]);

#endif // CAKE_HEADER_H_INCLUDED
