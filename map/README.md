# `Map`

## Overview

This `Map` implementation in C provides a simple and efficient way to store key-value pairs using a dynamically sized array. It leverages binary search for quick lookups and insertion sort for maintaining sorted order when inserting new elements. The implementation is flexible, allowing the use of any data types for keys and values by defining custom map types.

## Features

- **Dynamic Array:** Automatically resizes when capacity is reached.
- **Binary Search:** Fast lookups in O(log n) time.
- **Insertion Sort:** Efficient insertion while maintaining sorted order.
- **Customizable:** Define maps with different key and value types and a custom comparison function.

## Usage

### Defining a Map

To define a map with specific key and value types, use the `DEFINE_MAP` macro. This macro generates the necessary types and functions for managing the map.

```c
#define DEFINE_MAP(key_type, val_type, name, compare_func)
```

- **key_type:** The type of the key.
- **val_type:** The type of the value.
- **name:** The prefix for the generated types and functions.
- **compare_func:** A comparison function for the key type, which should return an integer (`< 0` if the first key is less than the second, `> 0` if greater, and `0` if equal).

### Example

Here is an example of defining and using a map that stores integers as keys and strings as values:

```c
#include "map.h"

int int_compare(int a, int b) {
    return a - b;
}

DEFINE_MAP(int, char*, IntStringMap, int_compare)

int main() {
    IntStringMap* map = IntStringMapInit(10);
    
    IntStringMapInsert(map, 1, "One");
    IntStringMapInsert(map, 2, "Two");
    IntStringMapInsert(map, 3, "Three");
    
    char** val = IntStringMapGet(map, 2);
    if (val) {
        printf("Key 2 has value: %s\n", *val);
    } else {
        printf("Key 2 not found.\n");
    }

    IntStringMapFree(map);
    return 0;
}
```

### Functions

The following functions are automatically generated when you use `DEFINE_MAP`:

- **`name* name##Init(size_t initial_capacity)`**  
  Initializes a new map with the specified initial capacity.

- **`void name##Free(name *map)`**  
  Frees the memory allocated for the map.

- **`void name##Insert(name *map, key_type key, val_type val)`**  
  Inserts a key-value pair into the map. If the key already exists, its value is updated.

- **`val_type* name##Get(name *map, key_type key)`**  
  Retrieves the value associated with the given key. Returns `NULL` if the key is not found.

### Important Notes

- **Memory Management:** Ensure that dynamically allocated memory for keys or values is managed properly (e.g., freeing strings).
- **Comparison Function:** The comparison function must correctly compare two keys and return the appropriate integer value for the binary search to work correctly.

## Conclusion

This `Map` implementation provides an easy way to create and manage sorted key-value pairs in C. By defining custom maps with `DEFINE_MAP`, you can quickly adapt this implementation to a wide variety of use cases.
