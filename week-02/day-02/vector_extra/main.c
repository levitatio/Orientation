#include <stdio.h>
#include "vector.h"

int main()
{
    error_t error = NO_ERROR;
    vector_t int_vector, char_vector, float_vector;
    init(&int_vector, MYINT,0, &error);
    int temp;
    for (int i = 0; i < 10 ; ++i) {
        temp = i;
        push_back(&int_vector, &temp, MYINT, &error);
    }
    print_vector(&int_vector);
    pop_back(&int_vector, &error);
    print_vector(&int_vector);

    init (&char_vector, MYCHAR,10, &error);

    char c = 'c';
    for (int j = 0; j < 20 ; ++j) {
        push_back(&char_vector, &c, MYCHAR ,&error);
    }
    print_vector(&char_vector);

    float f = 2.5;
    init (&float_vector, MYFLOAT,19, &error);
    for (int k = 0; k < 19; ++k) {
        push_back(&float_vector, &f, MYFLOAT, &error);
    }
    print_vector(&float_vector);
    destroy(&int_vector, &error);
    destroy(&char_vector, &error);
    destroy(&float_vector, &error);
    return 0;
}