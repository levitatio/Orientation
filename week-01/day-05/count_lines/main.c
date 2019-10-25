#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int count_lines_in_file (const char* file_name);

int main ()
{
    printf("number of lines in file: %d", count_lines_in_file("../../sometext.txt"));
    return 0;
}

int count_lines_in_file (const char* file_name)
{
    int result = 0;
    FILE* fptr;
    fptr = fopen(file_name, "r");
    if (fptr == NULL) {
        printf("File could not be loaded!\n");
        return 0;
    }
    char str[100];
    while (fgets(str, 100, fptr) != NULL){
        result++;
    }
    return result;
}