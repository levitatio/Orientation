#include <stdio.h>
#include <stdlib.h>

#define BIGGEST_INT 2147483647

typedef enum type{
    CHAR, INT, FLOAT
}type_t;

typedef enum metadat{
    FILESIZE, WIDTH, HEIGHT, DEPTH
}metadata_t;

int number_of_pixels (FILE* file);
// as bits
void print_array(void* array, type_t type, int array_length);
void read_meta_data (FILE* file, int* array_metadata, int array_length);
int read_bmp_file_into_array (char* path, int* array, int* array_length);
int* set_pointer_to_pixels (int* bytes_of_file);
void print_pixels (int* bytes_of_file, int size_of_file);

int main()
{

    int size_of_file = 0;
    //it proves bytes_of_file has memory on heap
    int* bytes_of_file = (int *)calloc(size_of_file, sizeof(int));

    char path[100] = "../../ninja_grayscale_mode.bmp";
    read_bmp_file_into_array(path, bytes_of_file, &size_of_file);

    free(bytes_of_file);
    return 0;
}

void print_pixels (int* bytes_of_file, int size_of_file){

    bytes_of_file += 54; //set to image data

}


int read_bmp_file_into_array (char* path, int* array, int* array_length)
{
    FILE* file = NULL;
    file = fopen(path, "rb");
    if (file == NULL) return 0;
    if ( -1 == (*array_length = number_of_pixels(file))) return 0;

    int meta_data[4];
    read_meta_data(file, meta_data, 4);
    //print_array(meta_data, INT, 4);

    *array_length = meta_data[FILESIZE];
    array = (int *)realloc(array, meta_data[FILESIZE] * sizeof(int));
    fread(array, meta_data[FILESIZE], 1, file);

    fclose(file);
    return 1;
}

int number_of_pixels (FILE* file)
{
    int size = 0;
    if (file == NULL) return -1;
    // get size of file
    return size;
}
void print_array(void* array, type_t type, int array_length)
{
    if (array_length < 0 || array_length > BIGGEST_INT - 1) return;
    switch (type){
        case CHAR : for (int i = 0; i < array_length; ++i) {
                printf("%c\n", *(char*)(array + i * sizeof(char)));
            } return;
        case INT : for (int i = 0; i < array_length; ++i) {
                int* temp = (int *)(array + i * sizeof(int));
                printf("%d\n", *(int *)(array + i * sizeof(int)));
            } return;
        case FLOAT : for (int i = 0; i < array_length; ++i) {
                printf("%f\n", *(float *)(array + i * sizeof(float)));
            } return;
        default: return;
    }
}
void read_meta_data (FILE* file, int* array_metadata, int array_length)
{
    //array_metadata is fix_sized specially 4
    unsigned char buffer[54];
    fread(buffer, 54, 1, file);
    array_metadata[FILESIZE] = *(int *) (buffer + 2);
    array_metadata[WIDTH]    = *(int *) (buffer + 18);
    array_metadata[HEIGHT]   = *(int *) (buffer + 22);

    *(buffer + 29) = '\0';
    *(buffer + 30) = '\0';
    *(buffer + 31) = '\0';
    array_metadata[DEPTH]    = *(int *) (buffer + 28);
}
int* set_pointer_to_pixels (int* bytes_of_file)
{
    //image datas start  after 54. byte
    char* temp_ptr = (char *) bytes_of_file;
    temp_ptr += 54;
    return (int *) temp_ptr;
}