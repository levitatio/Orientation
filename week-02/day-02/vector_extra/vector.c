#include "vector.h"

void init(vector_t *vec, type_of_vector_t type, int size, error_t *result)
{
    *result = NO_ERROR;
    //if size is not ok
    if (size < 0 || size > MAX_SIZE_OF_VECTOR) {
        *result = OUT_OF_BOUNDS;
        return;
    }
    if (type < MYINT || type > MYVOID ){
        *result = WRONG_ARGUMENT;
        return;
    }
    vec->type = type;
    vec->size_of_type = size_of_type(vec);
    vec->size = 0;
    vec->capacity = size * 2;
    if (vec->capacity == 0) {
        vec->capacity = 1;
    };
    vec->data = (void *) calloc(vec->capacity, sizeof(vec->size_of_type));
}

void destroy(vector_t *vec, error_t *result)
{
    *result = NO_ERROR;
    vec->size = 0;
    vec->capacity = 0;
    free(vec->data);
}

void* element_at(vector_t *vec, int index, error_t *result)
{
    *result = NO_ERROR;
    if (index < 0 || index >= vec->size) {
        *result = OUT_OF_BOUNDS;
        return NULL;
    }
    return (vec->data + index * vec->size_of_type);
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
        vec->data = (void *) realloc(vec->data, vec->capacity * sizeof(vec->size_of_type));
    }
}

void push_back(vector_t *vec, void *data, type_of_vector_t type, error_t *result)
{
    *result = NO_ERROR;
    if (vec->type != type){
        *result = WRONG_ARGUMENT;
        return;
    }
    if (vec->capacity == 0) {
        vec->capacity = 1;
        vec->size = 0;  //it is just a safe method
    } else if (vec->size > (int) vec->capacity / 2) {
        vec->capacity = vec->size * 2;
    }
    if (vec->capacity == 0){
        vec->capacity = 1;
    }
    vec->data = (void *) realloc(vec->data, vec->capacity * sizeof(vec->size_of_type));
    write_data_to_end_of_vector (vec, data, result);
    vec->size++;
}


void print_vector (vector_t* vec)
{
    switch (vec->type) {
        case MYINT  : {for (int i = 0; i < vec->size; ++i) {
                printf("%d\n", *((int*)(vec->data + i * vec->size_of_type)));
            }; };break;
        case MYCHAR : {for (int i = 0; i < vec->size; ++i) {
                printf("%c\n", *((char*)(vec->data + i * vec->size_of_type)));
            }; }; break;
        case MYFLOAT: {for (int i = 0; i < vec->size; ++i) {
                printf("%f\n", *((float*)(vec->data + i * vec->size_of_type)));
            };}; break;
        default : break;
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

int size_of_type (vector_t* vec)
{
    switch (vec->type){
        case MYINT  : return sizeof(int);
        case MYCHAR : return sizeof(char);
        case MYFLOAT: return sizeof(float);
        case MYVOID : return sizeof(void) ;
        default : return 0;
    }
}

void write_data_to_end_of_vector (vector_t *vec, void *data, error_t *result)
{
    switch (vec->type){
        case MYINT  :  *((int*)(vec->data + vec->size * vec->size_of_type)) = *((int*)data); return;
        case MYCHAR : *((char*)(vec->data + vec->size * vec->size_of_type)) = *((char*)data); return;
        case MYFLOAT: *((float*)(vec->data + vec->size * vec->size_of_type)) = *((float*)data); return;
        default : return;
    }
}