#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

int write_into_file (const char* path, const char* word, int number)
{
    FILE* fptr;
    fptr = fopen (path, "w");
    if (fptr == NULL){
        printf("File could not be opened\n");
        return -1;
    }
    char str_buffer[number + 1];
    strcpy(str_buffer, word);
    strcat(str_buffer, "\n");
    for (int i = 0; i < number; ++i) {
        fputs(str_buffer, fptr);
    }
    fclose(fptr);
    return 0;
}

int main()
{
    write_into_file("../somewhere.txt", "rainbow", 101);
    return 0;
}