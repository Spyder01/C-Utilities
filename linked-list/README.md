# README for `LinkedList` Implementation in C

## Overview

This `LinkedList` implementation in C allows you to create and manage singly linked lists with ease. The linked list is generic, meaning you can define lists for any data type by using a macro. The implementation includes basic operations such as initialization, adding elements, and printing the list.

## Features

- **Generic Implementation:** Create linked lists for any data type.
- **Simple API:** Initialize, add elements, and print the list with easy-to-use functions.
- **Custom Print Function:** Pass a custom function to print elements of the list.

## Usage

### Defining a Linked List

To define a linked list for a specific data type, use the `DEFINE_LINKED_LIST` macro. This macro generates the necessary types and functions for managing the linked list.

```c
#define DEFINE_LINKED_LIST(type, list_name)
```

- **type:** The data type of the elements in the linked list.
- **list_name:** The name of the linked list.

### Example

Here is an example of defining and using a linked list that stores integers:

```c
#include "linked_list.h"
#include <stdio.h>

void print_int(int value) {
    printf("%d\n", value);
}

DEFINE_LINKED_LIST(int, IntList)

int main() {
    IntList list;
    init_IntList(&list);
    
    add_IntList(&list, 10);
    add_IntList(&list, 20);
    add_IntList(&list, 30);
    
    print_IntList(&list, print_int);
    
    return 0;
}
```

### Functions

The following functions are automatically generated when you use `DEFINE_LINKED_LIST`:

- **`void init_##list_name(list_name *list)`**  
  Initializes a new linked list. Sets the head of the list to `NULL`.

- **`void add_##list_name(list_name *list, type value)`**  
  Adds a new element to the front of the linked list.

- **`void print_##list_name(list_name *list, void (*print_fn)(type))`**  
  Prints all elements in the linked list using the provided print function.

### Important Notes

- **Memory Management:** Ensure that dynamically allocated memory for the linked list nodes is managed properly. Since this implementation doesn't include a free function, remember to manually free the memory when it's no longer needed.
- **Custom Print Function:** The print function passed to `print_##list_name` should be able to handle the data type stored in the linked list.

## Conclusion

This `LinkedList` implementation provides a flexible and easy way to create and manage singly linked lists in C. The use of the `DEFINE_LINKED_LIST` macro allows you to quickly define lists for various data types and manage them with a straightforward API.
