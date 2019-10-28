#include <stdio.h>
#include <stdlib.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

int size_of_string(char *str)
{
    char *temp = str;
    int size_of_str = 0;
    while (*temp != '\000' && size_of_str < 10000) {
        temp++;
        size_of_str++;
    }
    if (size_of_str == 10000) {
        return -1;
    }
    return size_of_str;
}

char *repeat_string(char *str, int number)
{
    int size_of_str = size_of_string(str);
    char *result_str = (char *) malloc((number * size_of_str + 1) * sizeof(char));
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < size_of_str; ++j) {
            *(result_str + i * size_of_str + j) = *(str + j);
        }
    }
    *(result_str + number * size_of_str) = '\0';
    return result_str;
}

int main()
{
    char my_str[10] = "Hy guys!";
    char *repeated_str = repeat_string(my_str, 5);

    free(repeated_str);
    return 0;
}