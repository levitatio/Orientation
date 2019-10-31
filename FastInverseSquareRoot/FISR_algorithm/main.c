#include <stdio.h>
#include <time.h>

#define MAGIC_NUMBER 0x5f3759df

float fast_inverse_square_root (float number)
{
    float x = number;
    int *x_int_ptr = (int *) (&x);

    int y_int = MAGIC_NUMBER - (*x_int_ptr >> 1);

    float* y_float_ptr = (float *) (&y_int);
    return *y_float_ptr;
}
/* it does not work
float newton_algorithm (float x)
{
    float half_x = x * 0.5;

    for (int i = 0; i < 3; ++i) {
        x *= (1.5 - half_x * x * x);
    }
    return x;
}
*/

int main()
{
    //printf("newton: %f and fISR: %f\n", newton_algorithm(25), fast_inverse_square_root(25));

    printf("Calculating starts now\n");
    clock_t tStart = clock();
    for (unsigned int i = 0; i <  2147483648; ++i) {

        fast_inverse_square_root(2.5);
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    printf("%f", fast_inverse_square_root(25));
    return 0;
}