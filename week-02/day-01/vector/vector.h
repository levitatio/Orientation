#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#endif //VECTOR_VECTOR_H

#define MAX_SIZE_OF_VECTOR 10000
#include <stdlib.h>

typedef enum error {
    OUT_OF_BOUNDS,
    EMPTY,
    INTERNAL_ERROR,
    WRONG_ARGUMENT,
    NO_ERROR
}error_t;

typedef struct vector
{
    int *data;
    int size;
    int capacity;
} vector_t;

void init(vector_t *vec, int size, error_t* result);
void destroy(vector_t *vec, error_t* result);
int element_at(const vector_t *vec, int index, error_t* result);
void pop_back(vector_t *vec, error_t* result);
void push_back(vector_t *vec, int data, error_t* result);
