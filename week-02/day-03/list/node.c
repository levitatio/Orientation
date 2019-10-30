#include "node.h"

void create_first_node(node_t** head_pptr, data_t* data)
{
    if (*head_pptr == NULL)
    {
        *head_pptr = (node_t *)malloc(sizeof(node_t)); //it is not sure
        copy_data((*head_pptr), data);
        (*head_pptr)->next= NULL;
        (*head_pptr)->previous= NULL;
    }
}

void push_front(node_t** head_pptr, data_t* data)
{
    if (*head_pptr == NULL){
        //this node is empty, create the head
        create_first_node(head_pptr, data);
        return;
    }
    //if head is not head
    node_t* iterator = *head_pptr;
    while (decrement_node_ptr(&iterator, 1)){}

    //create new head node
    node_t* new_head_ptr = (node_t *)malloc(sizeof(node_t));
    iterator->previous = new_head_ptr;
    //init new head node
    copy_data(new_head_ptr, data);
    new_head_ptr->previous = NULL;
    new_head_ptr->next = iterator;
    //function changes it's argument pointer to point new head element
    *head_pptr = new_head_ptr;
}
void push_back(node_t** head_pptr, data_t* data)
{
    if (*head_pptr == NULL){
        //this node is empty, create the head
        create_first_node(head_pptr, data);
        return;
    }
    //jump to tail
    node_t* iterator = *head_pptr;
    while (increment_node_ptr(&iterator, 1)){}

    //create new tail node
    node_t* new_tail_ptr = (node_t *)malloc(sizeof(node_t));
    iterator->next = new_tail_ptr;
    //init new tail node
    copy_data(new_tail_ptr, data);
    new_tail_ptr->previous = iterator;
    new_tail_ptr->next = NULL;
}
void insert_at_by_node (node_t* element_ptr, data_t* data)
{
    if (element_ptr == NULL) return;

    //it will be changed
    node_t* temp_ptr = element_ptr->next;
    node_t* new_element_ptr = (node_t *)malloc(sizeof(node_t));

    //insert new element between element and element->next nodes
    element_ptr->next = new_element_ptr;
    //if it is not the tail
    if (temp_ptr != NULL) {
        temp_ptr->previous = new_element_ptr;
    }

    //init new node
    copy_data(new_element_ptr, data);
    new_element_ptr->previous = element_ptr;
    new_element_ptr->next = temp_ptr;
}

void insert_at_by_index (node_t* head_ptr, data_t* data, int index)
{
    node_t* iterator = head_ptr;
    if (increment_node_ptr(&iterator, index)){
        insert_at_by_node(iterator, data);
    }else {
        printf("wrong argument!\n");
    }
}

node_t* delete (node_t** head_pptr)
{
    node_t* result = NULL;
    if (empty(*head_pptr))
        return NULL;
    if ((*head_pptr)->next == NULL) {
        free(*head_pptr);
        *head_pptr = NULL;
        return NULL;
    }
    result = (*head_pptr)->next;
    result->previous = NULL;
    free(*head_pptr);
    *head_pptr = NULL;
    return result;
}

int delete_elements(node_t** head_pptr, int number)
{
    //delete number th nodes start from head
    if (number > size(*head_pptr)) number = size(*head_pptr);
    for (int i = 0; i < number; ++i) {
        *head_pptr = delete(head_pptr);
    }
}
node_t* search_by_data (node_t* head_ptr, data_t* data)
{
    if (head_ptr == NULL) return NULL;
    node_t* iterator = head_ptr;
    //first element
    if (compare_data_t(&iterator->datas, data)){
        return iterator;
    }
    //other elements if those exist
    while (increment_node_ptr(&iterator, 1)) {
        if (compare_data_t(&iterator->datas, data)){
            return iterator;
        }
    }
    return NULL;
}

int size(node_t* head_ptr)
{
    if (head_ptr == NULL){
        return -1;
    }
    node_t* iterator = head_ptr;
    int result = 1;
    while (increment_node_ptr(&iterator, 1)){
        result++;
    }
    return result;
}

int empty(node_t* head_ptr){
    if(head_ptr == NULL){
        return 1;
    }
    return 0;
}

int increment_node_ptr(node_t** node_pptr, int number)
{
    //if could be incremneted return 1 else 0
    for (int i = 0; i < number; ++i) {
        if ((*node_pptr)->next == NULL) {
            return 0;
        }
        *node_pptr = (*node_pptr)->next;
    }
    return 1;
}
int decrement_node_ptr(node_t** node_pptr, int number)
{
    for (int i = 0; i < number; ++i) {
        if ((*node_pptr)->previous == NULL) {
            return 0;
        }
        *node_pptr = (*node_pptr)->previous;
    }
    return 1;
}

void copy_data(node_t* list_element, data_t* data)
{
    if (list_element == NULL || data == NULL){
        return;
    }
    list_element->datas.x = data->x;
}
int compare_data_t (data_t* first, data_t* second)
{
    //if those have the same values it return 1, else 0
    if (first->x == second->x) return 1;
    return 0;
}

void print_list (node_t* head_ptr)
{
    if (head_ptr == NULL) return;
    node_t* iterator = head_ptr;
    int index = 0;
    //first element
    printf("This is the %d. element. X of data of it is: %d\n", index, iterator->datas.x);

    //other element if those exist
    while(increment_node_ptr(&iterator, 1)){
        printf("This is the %d. element. X of data of it is: %d\n", index, iterator->datas.x);
        index++;
    }
    printf("\n");
}