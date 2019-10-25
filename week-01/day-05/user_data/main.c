#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main ()
{
    printf("Please give me your full name and age, delimited by space!\n");
    char data[100];
    gets(data);

    char *first_name, *last_name, *temp;
    int age;
    first_name = strtok(data, " ");
    last_name = strtok(NULL, " ");
    temp = strtok(NULL, " ");
    age = atoi(temp);

    printf("%s %s is %d old.\n", first_name, last_name, age);

    return 0;
}