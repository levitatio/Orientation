#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits


int main()
{
    int* pointer = NULL;

    pointer = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 5 ; ++i) {
        pointer[i] = 10;
    }

    for (int j = 0; j < 10 ; ++j) {
        printf("pointer[%d] = %d\n", j, pointer[j]);
    }

    free(pointer);
    return 0;
}