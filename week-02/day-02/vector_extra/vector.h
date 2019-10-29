#ifndef VECTOR_EXTRA_VECTOR_H
#define VECTOR_EXTRA_VECTOR_H

#define MAX_SIZE_OF_VECTOR 10000
#include <stdlib.h>
#include <stdio.h>

typedef enum type_of_vector {
    MYINT,
    MYCHAR,
    MYFLOAT,
    MYVOID
}type_of_vector_t;

typedef enum error {
    OUT_OF_BOUNDS,
    EMPTY,
    INTERNAL_ERROR,
    WRONG_ARGUMENT,
    NO_ERROR
}error_t;

typedef struct vector
{
    type_of_vector_t type;
    int size_of_type;
    void *data;
    int size;
    int capacity;
} vector_t;



void init(vector_t *vec, type_of_vector_t type, int size, error_t* result);
void destroy(vector_t *vec, error_t* result);
void* element_at(vector_t *vec, int index, error_t* result);
void pop_back(vector_t *vec, error_t* result);
void push_back(vector_t *vec, void* data, type_of_vector_t type, error_t* result);
int size_of_type (vector_t* vec);
void print_vector (vector_t* vec);
void print_error (error_t* error);
void write_data_to_end_of_vector (vector_t *vec, void *data, error_t *result);



#endif //VECTOR_EXTRA_VECTOR_H
