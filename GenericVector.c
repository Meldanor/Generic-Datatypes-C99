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
}   

// TEST METHODE!
DefVector(int)

#include <stdio.h>
int main(void) {
    // TEST CONSTRUCT
    intVector *a = intVector_construct(10);
    int *elements = a->elements;
    int i = 0;
    // Vector contains numbers from 1 to inclusive 10
    for (i = 0; i < 10; ++i) {
        elements[i] = i + 1;
    }
    int sum = 0;
    for (i = 0; i < 10; ++i) {
        sum += elements[i];
    }
    printf("Sum from 1 to 10 (must be 55): %d is %s\n", sum, (sum == 55) ? "True" : "False"  );
}
