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

int main() {
    uint8_t myVar = 0b10100101;

    printf("myVar in decimal format: %d\n", myVar);
    printf("myVar in hexadecimal format: %x\n", myVar);
    printf("myVar in binary format: ");
    PrintBinary(myVar);


    // 1. Print out myVar in decimal format
    // 2. Print out myVar in hexadecimal format
    // 3. Print out myVar in binary format using PrintBinary function

    // For the following tasks please verify your results with PrintBinary function

    // 4. Create 0b01010000 value from myVar with shift operator
    printf("myVar in binary format after shifting: ");
    PrintBinary(myVar << 4);

    // 5. Create 0b00101001 value from myVar with shift operator
    printf("myVar in binary format after shifting: ");
    PrintBinary(myVar >> 2);

    // 6. Create 0b00100000 value from myVar with a single bitwise operator
    printf("myVar in binary format after using a single bitwise operation: ");
    PrintBinary(myVar & 0b00100000);

    // 7. Create 0b11100101 value from myVar with a single bitwise operator
    printf("myVar in binary format after using a single bitwise operation: ");
    PrintBinary(myVar | 0b01000000);
    // 8. Create 0b01011010 value form myVar with a single bitwise operator
    printf("myVar in binary format after using a single bitwise operation: ");
    PrintBinary(~myVar);
    return 0;
}