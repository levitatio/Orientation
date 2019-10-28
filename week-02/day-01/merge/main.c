#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// the resulting array should be 20 elements long
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int* odd_numbers = (int*)malloc(10 * sizeof(int));
    int* even_numbers = (int*)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        odd_numbers[i] = 1;
        even_numbers[i] = 2;
    }
    even_numbers = (int* ) realloc(even_numbers, 20 * sizeof(int));
    for (int j = 0; j < 10; ++j) {
        even_numbers[10 + j] = odd_numbers[j];
    }
    free(odd_numbers);
    for (int k = 0; k < 20; ++k) {
        printf("%d\n", even_numbers[k]);
    }
    free(even_numbers);
    return 0;
}