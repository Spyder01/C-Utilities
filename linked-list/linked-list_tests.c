#include<stdio.h>
#include "./linked-list.h"

DEFINE_LINKED_LIST(int, int_list)

void print_int(int value) {
    printf("%d\n", value);
}

int main() {
    int_list my_list;
    init_int_list(&my_list);

    add_int_list(&my_list, 10);
    add_int_list(&my_list, 20);
    add_int_list(&my_list, 30);
    print_int_list(&my_list, print_int);

    return 0;
}

