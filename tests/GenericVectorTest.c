#include <stdio.h>
#include "../GenericVector.h"

DefVector(int)

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
