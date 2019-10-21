#include <stdio.h>

int compare_sum_of_digits(int a, int b);
int sum_of_digits (int a);

int main() {
    int a;
    int b;
    printf("First number: \n");
    scanf("%d", &a);
    printf("Second number: \n");
    scanf("%d", &b);
    printf("Sum of number of digits equal: %d\n", compare_sum_of_digits(a, b));
    return 0;
}

int compare_sum_of_digits(int a, int b)
{
    if (sum_of_digits(a) == sum_of_digits(b)){
        return 1;
    }
    return 0;
}
int sum_of_digits (int a)
{
    int sum_a = 0;
    while (a != 0){
        int temp = a % 10;
        sum_a += temp;
        a = (a - temp) / 10;
    }
    return sum_a;
}