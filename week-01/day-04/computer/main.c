#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer = {2.4, 4, 32};
    Notebook notebook = {2.8, 2, 32};

    printf("cpu_speed: %f , ram_size: %d , bits: %d\n", computer.cpu_speed_GHz, computer.ram_size_GB, computer.bits);
    printf("cpu_speed: %f , ram_size: %d , bits: %d\n", notebook.cpu_speed_GHz, notebook.ram_size_GB, notebook.bits);
    return 0;
}