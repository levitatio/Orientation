#include <stdio.h>
#include <stdint.h>

int main() {
    int myInt = 123456789;
    float myFloat = 3.14159265359F;
    char myChar = 'c';

    int myIntRead;
    float myFloatRead;
    char myCharRead;

    FILE* fptr;
    fptr = fopen("../myInt.txt", "w");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return -1;
    }
    fprintf(fptr, "%d", myInt);

    fseek(fptr, 0, SEEK_END);
    long int size_text_file = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    fclose(fptr);

    fptr = fopen("../myInt.bin", "wb");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return -1;
    }
    fwrite(&myInt, sizeof(int),1,fptr);

    fseek(fptr, 0, SEEK_END);
    long int size_binary_file = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    printf ("Size of txtfile: %ld\n", size_text_file);
    printf ("Size of binaryfile: %ld\n", size_binary_file);
    fclose(fptr);

    fptr = fopen("../myFloat.bin", "wb");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return -1;
    }
    fwrite(&myFloat, sizeof(float), 1, fptr);
    fclose(fptr);

    fptr = fopen("../myChar.bin", "wb");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return -1;
    }
    fwrite(&myChar, sizeof(char), 1, fptr);
    fclose(fptr);

    fptr = fopen("../myChar.bin", "rb");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return -1;
    }
    fread(&myCharRead, sizeof(char), 1, fptr);
    printf("%c\n", myCharRead);
    fclose(fptr);

    fptr = fopen("../myFloat.bin", "rb");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return -1;
    }
    fread(&myFloatRead, sizeof(float), 1, fptr);
    printf("%f\n", myFloatRead);
    fclose(fptr);

    fptr = fopen("../myInt.bin", "rb");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return -1;
    }
    fread(&myIntRead, sizeof(int), 1, fptr);
    printf("%d\n", myIntRead);
    fclose(fptr);


// proceed with allocating memory and reading the file
    /*
     * 1. Write out myInt to myInt.txt as a text!
     * 2. Write out myInt to myInt.bin as a binary file!
     *    Check the size of myInt.txt and myInt.bin! Why it is different?
     * 3. Write out myInt to myInt.bin, myFloat to myFloat.bin and myChar to myChar.bin!
     * 4. Read them back to myIntRead, myFloatRead and myCharRead and compare these variables to myInt, myFloat, myChar,
     *    they should be the same.
     */

    return 0;
}