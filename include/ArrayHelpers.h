#ifndef arrayhelpers_h
#define arrayhelpers_h

#include <stdlib.h>
#include "RobotPosition.h"

typedef struct {
    Position *array;
    std::size_t used;
    std::size_t size;
} Array;


void initArray(Array *a, size_t initialSize) {
    a->array = (Position*)malloc(initialSize * sizeof(Position));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (Position *)realloc(a->array, a->size * sizeof(Position));
    }
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}


#endif