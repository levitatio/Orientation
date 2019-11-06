#include <stdio.h>
#include <time.h>
#include <math.h>

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
    float x = 987698776;
    int *x_int_ptr = (int *) (&x);
    int y_int = MAGIC_NUMBER - (*x_int_ptr >> 1);
    float* y_float_ptr = (float *) (&y_int);

    printf("Calculating by FISR starts now\n");
    clock_t tStart = clock();
    for (unsigned int i = 0; i <  2147483648; ++i) {

        //fast_inverse_square_root(25);

        x_int_ptr = (int *) (&x);
        y_int = MAGIC_NUMBER - (*x_int_ptr >> 1);
        y_float_ptr = (float *) (&y_int);
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf("The result: %f\n\n", fast_inverse_square_root(x));

    printf("Calculating by built-in power function starts now\n");

    tStart = clock();
    for (unsigned int i = 0; i <  2147483648; ++i) {

        pow(25, -(.5));
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf("The result: %f\n\n", pow(x, -(.5)));

    printf("Calculating by sqrt and 1^ functions starts now\n");
    tStart = clock();
    for (unsigned int i = 0; i <  2147483648; ++i) {

        1/ (sqrtf(25));
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf("The result: %f\n\n", 1/(sqrtf(x)));

    return 0;
}