#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum screen_size{
    SMALL, MEDIUM, BIG
}screen_size_t;

typedef struct smartphone{
    char name_of_gadget[50];
    int year_of_release;
    screen_size_t screen_type;
}smartphone_t;

smartphone_t get_oldes_phone (smartphone_t* array, int array_length);
screen_size_t get_screen_size_count(int size);

/* Create a smartphone register application
 * Read the content of smartphones.txt and store the informations in a structure called "smartphone:
 * - the name of the gadget (which is shorter than 256 characters) (Don't bother with the underscore('_') character, it's the part of the name)
 * - the year of the release (e.g. 2016)
 * - the type of the screen size (as a custom type, see below)
 *
 * In the file the size is given in cm but you should store the screen size type in an enumeration ("screen_size"),
 * the valid types are:
 *  - BIG -> (>= 15 cm)
 *  - MEDIUM -> (>= 12 cm)
 *  - SMALL -> (< 12 cm)
 *
 * The smartphones should be stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_phone()
 *    - it should return the name of oldest device
 *    - it is up to you how your function declaration looks like (return type and arguments)
 * - get_screen_size_count()
 *    - it returns the count of phones which has "screen_size" size
 *    - it is up to you how your function declaration looks like (return type and arguments)
 *
 * Your main function should invoke these functions and print the following:
 * The ..... is the oldest device in the database
 * There are .... phones with BIG (>= 15 cm) screen size
 * There are .... phones with SMALL (< 12 cm) screen size
 *
 *
 * Additionally, you need to create a new file(prices.txt) that looks like this:
 * <NAME> <PRICE>
 * <NAME> <PRICE>
 * .
 * .
 * .
 *
 * To calculate the price use the following method. The base price of every phone is 300$.
 * If the size is SMALL, that adds 0$ to the value
 * If the size is MEDIUM, that adds 100$ to the value
 * If the size is BIG, that doubles the base price.
 *
 * The price also depends on the age. For every year that passed since its release,
 * the phone loses 50$ but the maximum value that it can lose because of the age is 250$
 */

int main()
{
    smartphone_t smartphones[500];
    int number_of_smartphones = 0;
    FILE* fptr;
    fptr = fopen("../examples.txt","r");
    if (fptr == NULL){
        printf("File could not be opened!\n");
    }
    char temp[1000];
    char *temp_token;

    while (fgets(temp, 1000, fptr)){
        temp_token = strtok(temp," ");
        strcpy(smartphones[number_of_smartphones].name_of_gadget, temp_token);

        temp_token = strtok(NULL, " ");
        smartphones[number_of_smartphones].year_of_release = atoi(temp_token);

        temp_token = strtok(NULL, " ");
        smartphones[number_of_smartphones].screen_type = get_screen_size_count(atoi(temp_token));

        number_of_smartphones++;

    }
    fclose(fptr);
    return 0;
}

smartphone_t get_oldes_phone (smartphone_t* array, int array_length)
{
    smartphone_t result = *array;
    for (int i = 0; i < array_length; ++i) {
        if (result.year_of_release > array[i].year_of_release){
            result = array[i];
        }
    }
    return result;
}
screen_size_t get_screen_size_count(int size)
{
    if (size < 12){
        return SMALL;
    }else if (size >= 12 && size < 15){
        return MEDIUM;
    }else {
        return BIG;
    }
}