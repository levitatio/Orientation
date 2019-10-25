#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'

int distance (char* array);

int main ()
{
    char str[] = "This is a sample string";
    char *first, *last;

    printf("distance: %d\n", distance(str));
    return 0;
}

int distance (char* array)
{
    int result = 0;
    int temp = 0;
    char *first, *last;
    first = array;
    while (*first != '\000' && *first != 's'){
        first++;
    }
    last = first;
    while (*last != '\000'){
        if (*last == 's'){
            result = temp;
        }
        temp++;
        last++;
    }
    return result;
}