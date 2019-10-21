#include <stdio.h>

int main() {
    int stored_number = 15;
    int user_number = 0;
    while (stored_number != user_number){
        printf("Your tip:\n");
        scanf("%d", &user_number);
        if (user_number < stored_number){
            printf("The stored number is higher\n");
        } else if (user_number > stored_number) {
            printf("The stored number is lower\n");
        } else {
            printf("You found the number: %d\n", stored_number);
        }
    }
    return 0;
}