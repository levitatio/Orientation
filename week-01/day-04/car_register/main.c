#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

typedef enum transmission
{
    manual, automatic, CVT, semiautomatic, dualclutch
}transmission_t;

typedef struct car{
    char* name_of_manufacturer;
    float price;
    int year_of_manufactured;
    transmission_t type_of_transmission;
}car_t;

int get_older_cars_than(struct car* array, int array_length, int age)
{
    int result = 0;
    for (int i = 0; i < array_length; ++i) {
        if (array[i].year_of_manufactured < (2019 - age)){
            result++;
        }
    }
    return result;
}

int  get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
{
    int result = 0;
    for (int i = 0; i < array_length; ++i) {
        if ((array + i)->type_of_transmission == trnsm){
            result++;
        }
    }
    return result;
}

int main()
{
    car_t cars[5];
    cars[0].year_of_manufactured = 2000;
    cars[0].type_of_transmission = CVT;
    cars[1].year_of_manufactured = 1990;
    cars[1].type_of_transmission = semiautomatic;
    cars[2].year_of_manufactured = 2010;
    cars[2].type_of_transmission = automatic;
    cars[3].year_of_manufactured = 2006;
    cars[3].type_of_transmission = manual;
    cars[4].year_of_manufactured = 2018;
    cars[4].type_of_transmission = CVT;
    printf("older than 10: %d cars\n", get_older_cars_than(cars, 5, 10));
    printf("cars with CVT transmission: %d\n", get_transmission_count(cars, 5, CVT));

    return 0;
}