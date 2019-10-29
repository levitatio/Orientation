#include <stdio.h>
#include "vector.h"

void print_vector (vector_t* vec)
{
    for (int i = 0; i < vec->size; ++i) {
        printf("%d\n", vec->data[i]);
    }
}

void print_error (error_t* error)
{
    switch (*error){
        case OUT_OF_BOUNDS  : printf("Out of bounds\n"); break;
        case EMPTY          : printf("empty\n"); break;
        case INTERNAL_ERROR : printf("Internal error\n"); break;
        case WRONG_ARGUMENT : printf("Wrong argument\n"); break;
        case NO_ERROR       : printf("No error\n"); break;
        default             : printf("Undefined error\n"); break;
    }
}

int main()
{
    error_t error = NO_ERROR;
    vector_t first, second, third;
    init(&first, 0, &error);
    init (&second, 10, &error);
    init (&third, 9000, &error);

    for (int i = 0; i < 10 ; ++i) {
        push_back(&first, i, &error);
    }
    print_vector(&first);
    pop_back(&first, &error);
    print_vector(&first);

    destroy(&first, &error);
    init(&first, 0, &error);

    print_vector(&first);
    for (int j = 0; j < 100 ; ++j) {
        push_back(&first, 100, &error);
    }
    printf("first element: %d\n 101. element: %d\n 0. element: %d", element_at(&first, 0, &error),
            element_at(&first, 100, &error), element_at(&first, -1, &error));

    destroy(&first, &error);
    destroy(&second, &error);
    destroy(&third, &error);
    return 0;
}