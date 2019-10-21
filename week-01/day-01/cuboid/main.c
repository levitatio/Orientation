#include <stdio.h>

int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    printf("First side: ");
    scanf("%lf", &a);
    printf("Second side: ");
    scanf("%lf", &b);
    printf("Third side: ");
    scanf("%lf", &c);

    printf("Surface Area: %f \n", (a * b * 2 + a * c * 2 + b * c * 2));
    printf("Volume: %f \n", (a * b * c));
    return 0;
}