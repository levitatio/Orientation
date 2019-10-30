#include <stdio.h>
#include "node.h"

int main()
{
    node_t* list = NULL;
    data_t data = {3};
    push_front(&list, &data);
    print_list(list);

    data.x = 5;
    push_front(&list, &data);
    print_list(list);

    data.x = 7;
    push_back(&list, &data);
    print_list(list);

    data.x = 56;
    insert_at_by_index(list,&data, 5);
    print_list(list);

    data.x = 101;
    data_t data_for_searching = {5};
    insert_at_by_node(search_by_data(list, &data_for_searching), &data);
    print_list(list);

    delete_elements (&list, 10);
    print_list(list);


    printf("Hello, World!\n");
    return 0;
}