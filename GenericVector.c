#include <stdlib.h> 

#define DefVector(type) \
typedef struct T_##type##Vector { \
    type *elements; \
    int size, capacity; \
} type##Vector; \
\
static type##Vector* \
type##Vector_construct(int capacity){ \
    type##Vector *s = malloc(sizeof(type##Vector)); \
    if (s == NULL) \
        return NULL; \
    s->elements = malloc(sizeof(type) * capacity); \
    if (s->elements == NULL) { \
        free(s); \
        return NULL; } \
    s->size=0; \
    s->capacity = capacity; \
    return s; \
} \
\
\
static int \
type##Vector_resize(type##Vector *vector, int newSize) { \
    if (vector == NULL) { \
        perror("vector is null!"); \
        return EXIT_FAILURE; \
    } \
    type *ptr = realloc(vector->elements, sizeof(type) * newSize); \
    if (ptr == NULL) { \
        perror("Insufficent memory!"); \
        return EXIT_FAILURE; \
    } \
    vector->elements = ptr; \
    vector->capacity = newSize; \
    return EXIT_SUCCESS; \
} \
\
static int \
type##Vector_add(type##Vector *vector, type e) { \
    if (vector == NULL) { \
        perror("vector is null!"); \
        return EXIT_FAILURE; \
    } \
    /* Vector is full */ \
    if (vector->size == vector->capacity) { \
        if (type##Vector_resize(vector, vector->capacity * 2) == EXIT_FAILURE) { \
            return EXIT_FAILURE; \
        } \
    } \
    \
    vector->elements[vector->size] = e; \
    vector->size = vector->size + 1; \
    return EXIT_SUCCESS; \
} 
// TEST METHODE!
DefVector(int)

#include <stdio.h>
int main(void) {
    // TEST CONSTRUCT
    intVector *a = intVector_construct(1);
    int *elements = a->elements;
    int i = 0;
    // Vector contains numbers from 1 to inclusive 10
    for (i = 0; i < 10; ++i) {
        intVector_add(a, i + 1);
    }
    int sum = 0;
    for (i = 0; i < 10; ++i) {
        sum += elements[i];
    }
    printf("Sum from 1 to 10 (must be 55): %d is %s\n", sum, (sum == 55) ? "True" : "False"  );
}
