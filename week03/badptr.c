#include <stdio.h>

int *one() {
    int x = 1;
    int *p = &x;
    return p;
}

int main() {
    int *q = one();
    printf("%d\n", *q);
}

