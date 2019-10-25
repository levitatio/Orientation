#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>


/*
 * 1. Create a struct which represents a person:
 * - name (max 64 characters)
 * - age (integer)
 * - height in meters (floating point)
 */

typedef struct stringt{
    char str[64];
}stringt_t;

typedef struct person{
    char name[64];
    int age;
    float height;
}person_t;

void write_person_to_file (const char* path, person_t* array_person, int length_of_array);
void read_person_from_file (const char* path, person_t* person, int length_of_array);
void print_person (person_t* person);
void fill_person_with_data(person_t* person);
stringt_t generate_string (const char* str);
void copy_str (char* target_array, char* src_array, int src_size);

int main() {

    srand(time(NULL));
    /*
     * 2. Create a person struct, fill it with some data and write it out to a binary file.
     *    Read it back to another struct variable and compare them. Are they equal?
     */

    person_t one = {"bela", 28, 91};
    write_person_to_file("../person.bin", &one, 1);
    read_person_from_file("../person.bin", &one, 1);
    print_person(&one);

    person_t persons[10];
    for (int i = 0; i < 10; ++i) {
        fill_person_with_data(persons + i);
    }
    write_person_to_file("../persons.bin", persons, 10);
    read_person_from_file("../persons.bin", persons, 10);
    for (int j = 0; j < 10; ++j) {
        print_person(persons + j);
    }
    /*
     * 3. Create an array which holds 10 person strcut.
     *    Fill them with some data and write out the array to a binary file.
     *    Read it back to another array and compare the array content to the first one. Are they equal?
     */

    return 0;
}

void write_person_to_file (const char* path, person_t* array_of_person, int length_of_array)
{
    FILE* fptr;
    fptr = fopen(path, "wb");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return;
    }
    fwrite(array_of_person, sizeof(person_t), length_of_array, fptr);
    fclose(fptr);
}
void read_person_from_file (const char* path, person_t* array_of_person, int length_of_array)
{
    FILE* fptr;
    fptr = fopen(path, "rb");
    if (fptr == NULL){
        printf("File could not be opened!\n");
        return;
    }
    fread(array_of_person, sizeof(person_t), length_of_array, fptr);
    fclose(fptr);
}
void print_person (person_t* person)
{
    printf("name: %s\n", person->name);
    printf("age: %d\n", person->age);
    printf("height: %f\n", person->height);
}

void fill_person_with_data(person_t* person)
{
    copy_str(person->name, "bela", 4);
    person->age = rand() % 50;
    person->height = rand() % 100 + 2.1;

}

stringt_t generate_string (const char* str)
{
    stringt_t result = {str};
    return result;
}
void copy_str (char* target_array, char* src_array, int src_size)
{
    for (int i = 0; i < src_size; ++i) {
        *(target_array + i) = *(src_array + i);
    }
    *(target_array + src_size) = '\000';
}