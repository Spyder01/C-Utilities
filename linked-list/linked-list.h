#include<stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define DEFINE_LINKED_LIST(type, list_name) \
    typedef struct list_name##_node {       \
        type data;                          \
        struct list_name##_node *next;      \
    } list_name##_node;                     \
                                            \
    typedef struct {                        \
        list_name##_node *head;             \
    } list_name;                            \
                                            \
    void init_##list_name(list_name *list) {  \
        list->head = NULL;                    \
    }                                         \
                                              \
    void add_##list_name(list_name *list, type value) {  \
        list_name##_node *new_node = malloc(sizeof(list_name##_node)); \
        new_node->data = value;                        \
        new_node->next = list->head;                   \
        list->head = new_node;                         \
    }                                                  \
                                                       \
    void print_##list_name(list_name *list, void (*print_fn)(type)) { \
        list_name##_node *current = list->head;      \
        while (current != NULL) {                    \
            print_fn(current->data);                 \
            current = current->next;                 \
        }                                            \
    }

#endif

