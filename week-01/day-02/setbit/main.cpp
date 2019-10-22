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

uint8_t SetBit (uint8_t byte, int bit_position)
{
    if (bit_position > 7 || bit_position < 0) {
        return 0b00000000;
    }
    return byte | (0b00000001 << bit_position);
}

int main() {
    /*
     * Write a function called SetBit which takes a byte and a bit position
     * and sets the bit of byte in the specified bit position to 1.
     * E.g. byte = 0b1100, bit position = 1 => returns with 0b1110
     */
    PrintBinary(SetBit(0b1100, 1));

    return 0;
}