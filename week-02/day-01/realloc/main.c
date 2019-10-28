#include <stdio.h>
#include <stdlib.h>

// Please use the realloc function where applicable!
// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{

    int number = 0;
    printf("Give me the number: \n");
    scanf("%d", &number);
    int* pointer = (int*)realloc(NULL, number * sizeof(int));

    printf("Give me %d numbers!\n", number);
    for (int i = 0; i < number; ++i) {
        scanf("%d", pointer + i);
    }
    int sum = 0;
    for (int j = 0; j < number; ++j) {
        sum += pointer[j];
    }
    int* pointer2 = (int*)realloc(NULL, sum * sizeof(int));
    for (int k = 0; k < sum; ++k) {
        pointer2[k] = 1;
    }
    for (int l = 0; l < sum; ++l) {
        printf("%d\n", pointer2[l]);
    }
    realloc(pointer, 0);
    realloc(pointer2, 0);
    return 0;
}