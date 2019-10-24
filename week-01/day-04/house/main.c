#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct {
    char* address;
    int price;
    int number_of_rooms;
    float area_of_house;
}House, *House_p;

int is_valuable_house (House_p house)
{
    if (house->price < house->area_of_house * 400){
        return 1;
    }else {
        return 0;
    }
}

int number_of_valuable_houses (House_p houses, int number_of_houses)
{
    int result = 0;
    for (int i = 0; i < number_of_houses; ++i) {
        if (is_valuable_house(houses + i)){
            result++;
        }
    }
    return result;
}

int main()
{
    House houses[5];
    houses[0].price = 400;
    houses[0].area_of_house = 1;
    houses[1].price = 40000;
    houses[1].area_of_house = 200;
    houses[2].price = 1000;
    houses[2].area_of_house = 1;
    houses[3].price = 100;
    houses[3].area_of_house = 1;
    houses[4].price = 2000;
    houses[4].area_of_house = 90000;

    printf("number of valuable houses: %d\n", number_of_valuable_houses(houses, 5));
    return 0;
}