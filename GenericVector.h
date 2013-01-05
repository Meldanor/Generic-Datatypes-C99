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
    /* Resize the vector with double size */ \
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
    /* Add element to vector */ \
    vector->elements[vector->size] = e; \
    vector->size = vector->size + 1; \
    return EXIT_SUCCESS; \
} \
\
static type* \
type##Vector_get(type##Vector *vector, int index) { \
    if (vector == NULL) { \
        perror("vector is null!"); \
        return NULL; \
    } \
    if (index < 0 || index >= vector->size) { \
        fprintf(stderr , "Index %d outside of vector (size = %d)\n", index, vector->size); \
        return NULL; \
    } \
    return &(vector->elements[index]); \
}
