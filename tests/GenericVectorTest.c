#include <stdio.h>
#include "../GenericVector.h"

int equalsInt(int *a, int *b) {
    return (*a == *b ? 0 : -1);
}



DefVector(int)

void printIntVector(intVector *a) {
    puts("Print array");
    int i ;
    for (i = 0; i < a->size -1; ++i) {
        printf("%d , ", *(intVector_get(a, i)));
    }
    printf("%d\n", *(intVector_get(a, a->size -1)));
}
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
    puts("");

    printIntVector(a);
    puts("Remove value at index 5");
    int r;
    intVector_removeAt(a, 5, &r);
    printf("Removed value : %d\n", r);
    printIntVector(a);
    puts("");

    puts("Remove elements to resize the array");
    printf("Old: C:%d S:%d\n", a->capacity, a->size);
    for ( i = 0 ; i < 6 ; ++i) {
        intVector_removeAt(a, 1, &r);
    }
    printf("New: C:%d S:%d\n", a->capacity, a->size);
    printIntVector(a);

    puts("");
    r = 11;
    printf("Remove the %d: ",r);
    r = intVector_remove(a, &r, &equalsInt);
    printf("%s\n", (r == EXIT_SUCCESS) ? "True" : "False"  );
    printIntVector(a);
    
    puts("");
    r = 9;
    printf("Remove the %d: ",r);
    r = intVector_remove(a, &r, &equalsInt);
    printf("%s\n", (r == EXIT_SUCCESS) ? "True" : "False"  );
    printIntVector(a);
    
    puts("Add elements from 11 to 20 and test if 13 is contained");
    for (i = 10; i < 20; ++i) {
        intVector_add(a, i + 1);
    }
    printIntVector(a);
    r = 13;
    printf("Contains 13: %s\n", intVector_contains(a, &r, &equalsInt) == EXIT_SUCCESS ? "True" : "False"  );
}

int main(void) {
    puts("Tests with int");
    puts("-----");
    testIntVector();
    puts("-----");
}

