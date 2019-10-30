#ifndef node_node_H
#define node_node_H

#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int x;
}data_t;

typedef struct node{
    data_t datas;

    struct node *next;
    struct node *previous;
}node_t;


void copy_data(node_t* list_element, data_t* data);
int increment_node_ptr(node_t** node_pptr, int number);
int decrement_node_ptr(node_t** node_pptr, int number);
void create_first_node(node_t** head_pptr, data_t* data);
void push_front(node_t** head_pptr, data_t* data);
void push_back(node_t** head_pptr, data_t* data);
void insert_at_by_node (node_t* element_ptr, data_t* data);
void insert_at_by_index (node_t* head, data_t* data, int index);
int size(node_t* head);
int empty(node_t* head);
node_t* delete (node_t** head_pptr);
int delete_elements(node_t** head_pptr, int number);
node_t* search_by_data (node_t* head, data_t* data);
int compare_data_t (data_t* first, data_t* second);
void print_list (node_t* head);







#endif //node_node_H
