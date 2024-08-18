#include "./map.h"

#include <stdio.h>
#include <string.h>


int compare_ints(int a, int b) {
    return (a > b) - (a < b); // 1 if a > b, -1 if a < b, 0 if equal
}

DEFINE_MAP(int, const char*, int_string_map, compare_ints)

int main() {
    int_string_map* map = int_string_mapInit(10);

    int_string_mapInsert(map, 3, "Three");
    int_string_mapInsert(map, 1, "One");
    int_string_mapInsert(map, 2, "Two");

    const char** val = int_string_mapGet(map, 2);
    if (val) {
			printf("map: %d->%s", 2, *val);
    }

    int_string_mapFree(map);
    return 0;
}

