#include <stdio.h>
#include <stdint.h>

void PrintBinary(uint8_t byte) {
    printf("%c%c%c%c %c%c%c%c\n",
           (byte & 0x80 ? '1' : '0'),
           (byte & 0x40 ? '1' : '0'),
           (byte & 0x20 ? '1' : '0'),
           (byte & 0x10 ? '1' : '0'),
           (byte & 0x08 ? '1' : '0'),
           (byte & 0x04 ? '1' : '0'),
           (byte & 0x02 ? '1' : '0'),
           (byte & 0x01 ? '1' : '0'));
}

int CountOnes (uint8_t byte)
{
    int result = 0;
    for (int i = 0; i < 8 ; ++i) {
        if (((byte >> i) & 0b00000001) == 1){
            result++;
        }
    }
    return result;
}


int CountZeros (uint8_t byte)
{
    int result = 0;
    for (int i = 0; i < 8 ; ++i) {
        if (((byte >> i) & 0b00000001) == 0){
            result++;
        }
    }
    return result;
}
int main() {
    /* 1.
     * Write a function called CountOnes which takes a byte returns
     * with the number of one bits in it.
     * E.g. byte = 0b1101 => returns with 3
     */
    printf("%d\n", CountOnes(0b1101));
    /* 2.
     * Write a function called CountZeros which takes a byte returns
     * with the number of zero bits in it.
     * E.g. byte = 0b1000 => returns with 3
     */
    printf("%d\n", CountZeros(0b1000));
    return 0;
}
