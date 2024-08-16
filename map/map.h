#include <stdlib.h>
#include <stdio.h>

#ifndef MAP_H
#define MAP_H

#define DEFINE_MAP(key_type, val_type, name, compare_func)           \
    typedef struct {                                                 \
        key_type key;                                                \
        val_type val;                                                \
    } name##_item;                                                   \
                                                                     \
    typedef struct {                                                 \
        name##_item *data;                                           \
        size_t size;                                                 \
        size_t capacity;                                             \
    } name;                                                          \
                                                                     \
    name* name##Init(size_t initial_capacity) {                      \
        name *map = (name *)malloc(sizeof(name));                    \
        if (!map) {                                                  \
            fprintf(stderr, "Failed to allocate memory for map.\n"); \
            exit(EXIT_FAILURE);                                      \
        }                                                            \
        map->data = (name##_item *)malloc(initial_capacity * sizeof(name##_item)); \
        if (!map->data) {                                            \
            fprintf(stderr, "Failed to allocate memory for map data.\n"); \
            free(map);                                               \
            exit(EXIT_FAILURE);                                      \
        }                                                            \
        map->size = 0;                                               \
        map->capacity = initial_capacity;                            \
        return map;                                                  \
    }                                                                \
                                                                     \
    void name##Free(name *map) {                                     \
        free(map->data);                                             \
        free(map);                                                   \
    }                                                                \
                                                                     \
    int name##BinarySearch(name *map, key_type key) {                \
        int left = 0;                                                \
        int right = map->size - 1;                                   \
        while (left <= right) {                                      \
            int mid = (left + right) / 2;                            \
            int cmp = compare_func(key, map->data[mid].key);         \
            if (cmp == 0) {                                          \
                return mid;                                          \
            } else if (cmp < 0) {                                    \
                right = mid - 1;                                     \
            } else {                                                 \
                left = mid + 1;                                      \
            }                                                        \
        }                                                            \
        return -(left + 1);  /* Return the insertion point */        \
    }                                                                \
                                                                     \
    void name##Insert(name *map, key_type key, val_type val) {       \
        if (map->size >= map->capacity) {                            \
            map->capacity *= 2;                                      \
            name##_item *newData = (name##_item *)realloc(map->data, map->capacity * sizeof(name##_item)); \
            if (!newData) {                                          \
                fprintf(stderr, "Failed to reallocate memory for map data.\n"); \
                exit(EXIT_FAILURE);                                  \
            }                                                        \
            map->data = newData;                                     \
        }                                                            \
                                                                     \
        int idx = name##BinarySearch(map, key);                      \
        if (idx >= 0) {                                              \
            map->data[idx].val = val;                                \
        } else {                                                     \
            idx = -(idx + 1);  /* Convert to positive index */       \
            for (size_t i = map->size; i > idx; i--) {               \
                map->data[i] = map->data[i - 1];                     \
            }                                                        \
            map->data[idx].key = key;                                \
            map->data[idx].val = val;                                \
            map->size++;                                             \
        }                                                            \
    }                                                                \
                                                                     \
    val_type* name##Get(name *map, key_type key) {                   \
        int idx = name##BinarySearch(map, key);                      \
        if (idx >= 0) {                                              \
            return &map->data[idx].val;                              \
        }                                                            \
        return NULL;                                                 \
    }																																 \
																																		 \


#endif

