#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

void split_string (char* sentence);

int main()
{
    printf("Type in a sentence:\n");
    char string[256] = "My first sentence.";
    
    //scanf("%s",string);
    split_string(string);


    return(0);
}

void split_string (char* sentence)
{
    char* temp_str;
    printf("Splitting string %s into tokens:\n", sentence);
    temp_str = strtok (sentence, " ");
    while ( temp_str != NULL){
        printf("%s\n", temp_str);
        temp_str = strtok(NULL, " ");
    }
}