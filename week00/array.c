#include <stdio.h>

int main() {
    int i;
    int arr[5];  // an array of 5 integers
    double rates[40]; // an array of 40 doubles
    for (i=0; i < 5; i++) {
       arr[i] = i;
       rates[i] = arr[i]*2;
    }

    for (i=0; i < 40; i++) {
        printf("rates[%i] = %f\n", i, rates[i]);
    }
}
