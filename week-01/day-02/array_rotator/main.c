#include <stdio.h>
#include <stdint.h>

void print_binary(uint8_t byte) {
    printf("%c%c%c%c %c%c%c%c",
           (byte & 0x80 ? '1' : '0'),
           (byte & 0x40 ? '1' : '0'),
           (byte & 0x20 ? '1' : '0'),
           (byte & 0x10 ? '1' : '0'),
           (byte & 0x08 ? '1' : '0'),
           (byte & 0x04 ? '1' : '0'),
           (byte & 0x02 ? '1' : '0'),
           (byte & 0x01 ?'1' : '0'));
}

void print_all_bytes(void* ptr, uint32_t bytes)
{
    uint8_t* new_ptr = (uint8_t*)ptr;
    for (int i = 0; i < bytes; ++i) {
        print_binary(*(new_ptr + i));
        printf(" | ");
    }
    printf("\n");
}

int is_overflow (uint8_t* byte_ptr, uint8_t right)
{
    if (right < 0 && ((*byte_ptr & 0b10000000) == 128)) {
        return 1;
    }
    if (right >= 0 && ((*byte_ptr & 0b00000001) == 1)){
        return 1;
    }
    return 0;
}

void shift_right (uint8_t* byte_ptr)
{
     *byte_ptr >>= 1;
}
void shift_left (uint8_t* byte_ptr)
{
    *byte_ptr <<= 1;
}
void set_first_bit_one (uint8_t* byte_ptr)
{
    *byte_ptr |= 0b10000000;
}

void set_last_bit_one (uint8_t* byte_ptr)
{
    *byte_ptr |= 0b00000001;
}

void RotateRight (void *ptr, uint32_t bytes, uint32_t rotation_count)
{
    uint8_t* new_ptr = (uint8_t*) ptr;
    for (uint8_t j = 0; j < rotation_count; ++j) {
        int over_flow_flag = is_overflow(new_ptr + bytes - 1, 1);

        for (uint8_t i = bytes - 1; i > 0 ; i--) {
            shift_right(new_ptr + i);
            if (is_overflow(new_ptr + i - 1, 1)) {
                set_first_bit_one(new_ptr + i);
            }
        }
        shift_right(new_ptr);
        if (over_flow_flag) {
            set_first_bit_one(new_ptr);
        }
    }
}
void RotateLeft (void *ptr, uint32_t bytes, uint32_t rotation_count)
{
    uint8_t* new_ptr = (uint8_t*) ptr;
    for (uint8_t j = 0; j < rotation_count; ++j) {
        int over_flow_flag = is_overflow(*(new_ptr), -1);

        for (uint8_t i = 0; i < bytes - 1 ; i++) {
            shift_left(new_ptr + i);
            if (is_overflow(new_ptr + i + 1, -1)) {
                set_last_bit_one(new_ptr + i);
            }
        }
        shift_left(new_ptr);
        if (over_flow_flag) {
            set_last_bit_one(new_ptr);
        }
    }
}

void array_rotator(void *ptr, uint32_t bytes, uint32_t rotation_count, uint8_t right) {
    /* This function should rotate the ptr buffer bits by rotation_count to left or right direction.
     * The rotation direction is right if the right parameter is positive, left otherwise.
     * E.g. ptr ->  |   0xAA    |    0x55   |    0x23   |
     *              | 1010 1010 | 0101 0101 | 0010 0011 |
     * array_rotator(ptr, 3, 2, 1) result is:
     *              |   0xEA    |    0x95   |    0x48   |
     *              | 1110 1010 | 1001 0101 | 0100 1000 |
     */
    //rotate right
    if (right >= 0) {
        RotateRight(ptr, bytes, rotation_count);
    }else {
        RotateLeft(ptr, bytes, rotation_count);
    }

}

int main() {

    uint8_t input[3] = { 0xAA, 0x55, 0x23 };

    print_all_bytes(input, 3);
    array_rotator(input, 3, 2, 1 );
    print_all_bytes(input, 3);

    return 0;
}