#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct {
    char* name;
    float price;
    float weight;
}Sandwich;

float price_of_order (Sandwich sandwich, int number_of_sandwiches)
{
    return sandwich.price * number_of_sandwiches;
}

int main()
{
    Sandwich sandw = {"Bela", 250.4, 50};
    printf ("Price of your order: %f", price_of_order(sandw, 4));
    return 0;
}