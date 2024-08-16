#include <stdio.h>
#include <stdlib.h>

#ifndef VECTOR_H
#define VECTOR_H

#define DEFINE_VECTOR_TYPE(type, name)                               \
typedef struct {                                                     \
    type *data;                                                      \
    size_t size;                                                     \
    size_t capacity;                                                 \
} name;                                                              \
                                                                     \
name *name##Init(size_t initial_capacity) {                          \
    name *vector = (name *)malloc(sizeof(name));                     \
    if (!vector) {                                                   \
        fprintf(stderr, "Failed to allocate memory for vector.\n");  \
        exit(EXIT_FAILURE);                                          \
    }                                                                \
    vector->data = (type *)malloc(initial_capacity * sizeof(type));  \
    if (!vector->data) {                                             \
        fprintf(stderr, "Failed to allocate memory for vector data.\n"); \
        free(vector);                                                \
        exit(EXIT_FAILURE);                                          \
    }                                                                \
    vector->size = 0;                                                \
    vector->capacity = initial_capacity;                             \
    return vector;                                                   \
}                                                                    \
                                                                     \
void name##Free(name *vector) {                                      \
    free(vector->data);                                              \
    free(vector);                                                     \
}                                                                    \
                                                                     \
void name##Add(name *vector, type value) {                           \
    if (vector->size >= vector->capacity) {                          \
        vector->capacity *= 2;                                       \
        type *newData = (type *)realloc(vector->data, vector->capacity * sizeof(type)); \
        if (!newData) {                                              \
            fprintf(stderr, "Failed to reallocate memory for vector data.\n"); \
            exit(EXIT_FAILURE);                                      \
        }                                                            \
        vector->data = newData;                                      \
    }                                                                \
    vector->data[vector->size++] = value;                            \
}                                                                    \
                                                                     \
type name##Get(name *vector, size_t index) {                         \
    if (index >= vector->size) {                                     \
        fprintf(stderr, "Index out of bounds.\n");                   \
        exit(EXIT_FAILURE);                                          \
    }                                                                \
    return vector->data[index];                                      \
}

#endif

