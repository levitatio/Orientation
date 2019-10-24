#include "circular_buffer.h"

void circular_buffer_init(cbuf_handle_t *cbuf, uint8_t *buffer, size_t size)
{
    if (size > cbuf->capacity){
        size = cbuf->capacity;
    }
    for (size_t i = 0; i < size; i++){
        cbuf->elements[i] = buffer [i];
    }
}

void circular_buf_reset(cbuf_handle_t *cbuf)
{
    //it is not necessary to set elements to zero
    for (size_t i = 0; i < cbuf->capacity; ++i) {
        cbuf->elements[i] = 0;
    }
    cbuf->end_of_valid_data = cbuf->start_of_valid_data;
}

void circular_buf_put_ow(cbuf_handle_t *cbuf, uint8_t data)
{

}

int circular_buf_put(cbuf_handle_t *cbuf, uint8_t data)
{
    return 0;
}

int circular_buf_get(cbuf_handle_t *cbuf, uint8_t *data)
{
    return 0;
}

bool circular_buf_empty(cbuf_handle_t *cbuf)
{
    return 0 == circular_buf_size(cbuf);
}

bool circular_buf_full(cbuf_handle_t *cbuf)
{
    return cbuf->capacity == circular_buf_size(cbuf);
}

size_t circular_buf_capacity(cbuf_handle_t *cbuf)
{
    return cbuf->capacity;
}

size_t circular_buf_size(cbuf_handle_t *cbuf)
{
    size_t result = 0;
    if (cbuf->end_of_valid_data > cbuf->start_of_valid_data) {
        for (uint8_t *temp_ptr = cbuf->start_of_valid_data; temp_ptr != cbuf->end_of_valid_data; temp_ptr) {
            result++;
        }
    }else {
        for (uint8_t *temp_ptr = cbuf->start_of_valid_data; temp_ptr != cbuf->end_of_valid_data; temp_ptr) {
            result++;
        }
    }

    return result;
}
