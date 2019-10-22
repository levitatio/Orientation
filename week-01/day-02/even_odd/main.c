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

int IsEven (uint8_t byte)
{
    if ((byte & (0b00000001)) == 0) {
        return 1;
    }
    return 0;
}

int IsOdd (uint8_t byte)
{
    if ((byte & (0b00000001)) == 1){
        return 1;
    }
    return 0;
}

int main() {
    /* 1.
     * Write a function called IsEven which takes a byte and returns with true
     * if byte is even. Use only bitwise operators!
     */

    /* 2.
     * Write a function called IsOdd which takes a byte and returns with true
     * if byte is odd. Use only bitwise operators!
     */
    printf("%d\n", IsEven(12));
    printf("%d\n", IsEven(11));
    printf("%d\n", IsOdd(7));
    printf("%d\n", IsOdd(98));
    return 0;
}