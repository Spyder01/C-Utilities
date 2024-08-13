# Vector Library

This library provides a dynamic array (vector) implementation in C, allowing you to create and manipulate vectors of various types with dynamic resizing capabilities.

## Overview

The `vector.h` header file uses a macro to define a vector type for a given data type. It provides functions to initialize a vector, add elements, access elements, and free the vector's resources.

## Macro Definition

### `DEFINE_VECTOR_TYPE(type, name)`

This macro defines a vector type for the specified data type `type` and name `name`. It generates the following functions:

- `name *name##Init(size_t initial_capacity)`: Initializes a vector with an initial capacity.
- `void name##Free(name *vector)`: Frees the memory allocated for the vector.
- `void name##Add(name *vector, type value)`: Adds an element to the vector, resizing it if necessary.
- `type name##Get(name *vector, size_t index)`: Retrieves an element at the specified index.

## Usage

### 1. Include the Header

Include `vector.h` in your source file:

```c
#include "vector.h"
```

### 2. Define a Vector Type

Use the `DEFINE_VECTOR_TYPE` macro to create a vector type for your desired data type. For example, to create a vector for `int`:

```c
DEFINE_VECTOR_TYPE(int, IntVector);
```

### 3. Initialize the Vector

Create an instance of the vector using the `Init` function:

```c
IntVector *vector = IntVectorInit(4); // Initial capacity of 4
```

### 4. Add Elements

Add elements to the vector using the `Add` function:

```c
IntVectorAdd(vector, 10);
IntVectorAdd(vector, 20);
IntVectorAdd(vector, 30);
```

### 5. Access Elements

Retrieve elements from the vector using the `Get` function:

```c
int value = IntVectorGet(vector, 0);
printf("Element at index 0: %d\n", value);
```

### 6. Free the Vector

Free the allocated memory when done:

```c
IntVectorFree(vector);
```

## Example

Here's a complete example demonstrating the use of the vector library:

```c
#include "vector.h"
#include <stdio.h>

int main() {
    // Define a vector of integers
    DEFINE_VECTOR_TYPE(int, IntVector);

    // Initialize the vector
    IntVector *vector = IntVectorInit(4);

    // Add elements to the vector
    IntVectorAdd(vector, 10);
    IntVectorAdd(vector, 20);
    IntVectorAdd(vector, 30);

    // Access and print elements
    printf("Element at index 0: %d\n", IntVectorGet(vector, 0));
    printf("Element at index 1: %d\n", IntVectorGet(vector, 1));
    printf("Element at index 2: %d\n", IntVectorGet(vector, 2));

    // Free the vector
    IntVectorFree(vector);

    return 0;
}
```

## License

This library is provided under the MIT License. See the LICENSE file for more details.

