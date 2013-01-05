#include <stdio.h>
#include "../GenericVector.h"


DefVector(int)
void testIntVector(void) {
    intVector *a = intVector_construct(1);
    int *elements = a->elements;
    int i = 0;
    // Vector contains numbers from 1 to inclusive 10
    for (i = 0; i < 10; ++i) {
        intVector_add(a, i + 1);
    }
    int sum = 0;
    for (i = 0; i < 10; ++i) {
        sum += *(intVector_get(a, i));
    }
    printf("Sum from 1 to 10 (must be 55): %d is %s\n", sum, (sum == 55) ? "True" : "False"  );
    
    puts("Tests for get which generate errors");
    intVector_get(a, -4);
    intVector_get(a, a->size);
    
    puts("Remote at index 5");
    int r;
    intVector_removeAt(a, 5, &r);
    printf("Removed value : %d\n", r);
    puts("Print array");
    for (i = 0; i < a->size -1; ++i) {
        printf("%d , ", *(intVector_get(a, i)));
    }
    printf("%d\n", *(intVector_get(a, a->size -1)));
    
    // Remove enough elements to resize the array
    for ( i = 0 ; i < 6 ; ++i) {
        intVector_removeAt(a, 1, &r);
    }
    
    for (i = 0; i < a->size -1; ++i) {
        printf("%d , ", *(intVector_get(a, i)));
    }
    printf("%d\n", *(intVector_get(a, a->size -1)));
    printf("C:%d S:%d\n", a->capacity, a->size);
}

int main(void) {
    puts("Tests with int");
    puts("-----");
    testIntVector();
    puts("-----");
}

