#include "vector.h"


void init(vector_t *vec, int size, error_t *result)
{
    *result = NO_ERROR;
    // size is not ok
    if (size < 0 || size > MAX_SIZE_OF_VECTOR) {
        *result = OUT_OF_BOUNDS;
        return;
    }
    vec->size = size;
    vec->capacity = size * 2;
    if (vec->capacity == 0) {
        vec->capacity = 1;
    };
    vec->data = (int *) calloc(vec->capacity, sizeof(int));
}

void destroy(vector_t *vec, error_t *result)
{
    *result = NO_ERROR;
    vec->size = 0;
    vec->capacity = 0;
    free(vec->data);
}

int element_at(const vector_t *vec, int index, error_t *result)
{
    *result = NO_ERROR;
    if (index < 0 || index >= vec->size) {
        *result = OUT_OF_BOUNDS;
        return 0;
    }
    return vec->data[index];
}

void pop_back(vector_t *vec, error_t *result)
{
    *result = NO_ERROR;
    if (vec->size == 0) {
        *result = OUT_OF_BOUNDS;
        return;
    }
    vec->size--;
    //realloc if datas shorter than half of capacity
    if (vec->size < (int) (vec->capacity / 2)) {
        vec->capacity = vec->size * 2;
        if (vec->capacity == 0) {
            vec->capacity = 1;      //data of this vector would vanish from heap with this if statement
        }
        vec->data = (int *) realloc(vec->data, vec->capacity * sizeof(int));
    }
}

void push_back(vector_t *vec, int data, error_t *result)
{
    *result = NO_ERROR;
    if (vec->capacity == 0) {
        vec->capacity = 1;
        vec->size = 0;  //it is just a safe method
    } else if (vec->size > (int) vec->capacity / 2) {
        vec->capacity = vec->size * 2;
    }
    if (vec->capacity == 0){
        vec->capacity = 1;
    }
    vec->data = (int *) realloc(vec->data, vec->capacity * sizeof(int));
    vec->data[vec->size] = data;
    vec->size++;
}

