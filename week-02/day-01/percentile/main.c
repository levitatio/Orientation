#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int percentile (int* array, int array_length, float percentile)            //percentile is 0 - 100
{
    return array[(int) ((array_length * percentile) / 100)];
}

void sort (int* array, int array_length)
{
    int* temp_min_ptr = array;
    int temp_number = 0;
    for (int i = 0; i < array_length; ++i) {
        for (int j = i; j < array_length ; ++j) {
            if( *temp_min_ptr > *(array + j)){
                temp_min_ptr = array + j;
            }
        }
        temp_number = array[i];
        array[i] = *temp_min_ptr;
        *temp_min_ptr = temp_number;
    }
}

int* transform_two_dimensional_to_one_dimensional (int** array, int number_of_rows, int number_of_columns)
{
    int *result = (int*)malloc(number_of_rows * number_of_columns * sizeof(int));
    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            *(result + i * number_of_columns + j) = array[i][j];
        }
    }
    return result;
}

int main()
{
    int n = 0;
    int m = 0;
    printf("Give me size of the matrix: (two int)\n");
    scanf("%d", &n);
    scanf("%d", &m);

    int **matrix = (int **) malloc(n * sizeof(int*));
    for (int k = 0; k < n ; ++k) {
        matrix[k] = (int*) malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("elements of %d . row and %d .column\n", i, j);
            scanf("%d", &matrix[i][j]);
        }

    }

    int* array = transform_two_dimensional_to_one_dimensional(matrix, n, m);
    sort(array, n*m );

    printf("80 th percentile: %d\n", percentile(array, n*m, 80.0));
    printf("90 th percentile: %d\n", percentile(array, n*m, 90.0));


    free(array);
    free(matrix);
    return 0;
}