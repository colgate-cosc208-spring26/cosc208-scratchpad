#include <stdio.h>
#include <stdlib.h>

int *one() {
    int *p = malloc(sizeof(int));
    *p = 13;
    return p;
}

int main() {
    int *q = one();
    printf("%d\n", *q);
}

