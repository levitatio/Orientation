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

uint8_t RotateRight (uint8_t byte, int rotation_number)
{
    for (int i = 0; i < rotation_number ; ++i) {
        if ((byte & 0b00000001) == 1) {
            byte = (byte >> 1) | 0b10000000;
        } else {
            byte = (byte >> 1);
        }
    }
    return byte;
}
uint8_t RotateLeft (uint8_t byte, int rotation_number)
{
    for (int i = 0; i < rotation_number ; ++i) {
        if ((byte & 0b10000000) == 128) {
            byte = (byte << 1) | 0b00000001;
        } else {
            byte = (byte << 1);
        }
    }
    return byte;
}

int main() {
    /* 1.
     * Write a function called RotateRight which takes a byte and a number
     * and rotates the bits of byte in right direction number times.
     * It should return with the result.
     * E.g. byte = 0b1000000, number = 1 => returns 0b01000000
     * E.g. byte = 0b1000001, number = 2 => returns 0b01100000
     */
    PrintBinary(RotateRight(0b10000000, 1));
    PrintBinary(RotateRight(0b10000001, 2));
    /* 2.
     * Write a function called RotateLeft which takes a byte and a number
     * and rotates the bits of byte in left direction number times.
     * It should return with the result.
     * E.g. byte = 0b1000000, number = 1 => returns 0b00000001
     * E.g. byte = 0b1000001, number = 2 => returns 0b00000110
     *
     */
    PrintBinary(RotateLeft(0b10000000, 1));
    PrintBinary(RotateLeft(0b10000001, 2));
    return 0;
}