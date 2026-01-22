#include <stdio.h>

int cells(int rounds) {
    int total = 1;
    for (int i = 0; i < rounds; i++){
        total *= 2;
    }
    return total;
}

int main() {
    printf("rounds=2 cells=%d\n", cells(2));
    printf("rounds=10 cells=%d\n", cells(10));
    return 0;
}
