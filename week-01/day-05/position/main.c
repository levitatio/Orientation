#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void list_i (char* words);

int main ()
{
    char string[55] = "This is a string for testing";
    char *p;
    list_i(string);

    return 0;
}

void list_i (char* words)
{
    char* p = words;
    int pos = 0;
    while (*p != '\000'){
        if (*p == 'i'){
            printf("%d\n", pos);
        }
        pos++;
        p++;
    }
}