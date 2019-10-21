#include <stdio.h>
#include <math.h>

int is_prime (int a);

int main() {
    int number;
    printf("The number: \n");
    scanf("%d", &number);

    printf("The number is prime: %d", is_prime(number));
    return 0;
}

int is_prime (int a)
{
    int squareroot_of_number = (int)sqrt(a) + 1;
    for (int i = 2; i < squareroot_of_number; i++){
        if (a % i == 0){
            return 0;
        }
    }
    return 1;
}