#include <stdio.h>
#include <stdlib.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
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

char *concatenate_strings(char *str1, char *str2)
{
    //search /000 character to get to know size of str1
    int size_of_str1 = size_of_string(str1);
    int size_of_str2 = size_of_string(str2);
    char *result_ptr = (char *) malloc((size_of_str1 + size_of_str2 + 1) * sizeof(char));

    for (int i = 0; i < size_of_str1; ++i) {
        *(result_ptr + i) = *(str1 + i);
    }
    for (int j = 0; j < size_of_str2; ++j) {
        *(result_ptr + size_of_str1 + j) = *(str2 + j);
    }
    *(result_ptr + size_of_str1 + size_of_str2) = '\0';
    return result_ptr;
}


int main()
{
    char str[7] = "haho";
    char str2[1000] = "na mivan mar megint aojgewkfgowjfeoawjeojfojojfaewofjawojfowajfowejfowajfowajfowjfoajefowjjeaw"
                      "wfjihfweohfaweohfowahfofhoawhfoafhoaewhohaofhoewhfoawfhowfjoajwfojfojfowajofiajofjoafjoawjefoaw"
                      "jfowjfoeaofjohefoawhfoihfoiwahfiwefhifhiweafhfihifhihihwefifhwaihfiu This is the end!!!";
    char* new_str = concatenate_strings(str2, str);

    free(new_str);
    return 0;
}