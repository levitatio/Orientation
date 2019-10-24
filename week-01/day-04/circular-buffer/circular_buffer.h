#ifndef CIRCULAR_BUFFER_CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_CIRCULAR_BUFFER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct cbuf_handle {
    uint8_t elements[100];
    uint8_t* start_of_valid_data;
    uint8_t* end_of_valid_data;
    size_t capacity;
}cbuf_handle_t;

// Pass in a storage buffer and size
void circular_buffer_init(cbuf_handle_t *cbuf, uint8_t* buffer, size_t size);

// Reset the circular buffer to empty

void circular_buf_reset(cbuf_handle_t *cbuf);
// Put version 1 continues to add data if the buffer is full

// Old data is overwritten
void circular_buf_put_ow(cbuf_handle_t *cbuf, uint8_t data);

// Put Version 2 rejects new data if the buffer is full
// Returns 0 on success, -1 if buffer is full
int circular_buf_put(cbuf_handle_t *cbuf, uint8_t data);

// Retrieve a value from the buffer
// Returns 0 on success, -1 if the buffer is empty
int circular_buf_get(cbuf_handle_t *cbuf, uint8_t * data);

// Returns true if the buffer is empty
bool circular_buf_empty(cbuf_handle_t *cbuf);
// Returns true if the buffer is full
bool circular_buf_full(cbuf_handle_t *cbuf);
// Returns the maximum capacity of the buffer
size_t circular_buf_capacity(cbuf_handle_t *cbuf);
// Returns the current number of elements in the buffer
size_t circular_buf_size(cbuf_handle_t *cbuf);
*/
#endif //CIRCULAR_BUFFER_CIRCULAR_BUFFER_H
