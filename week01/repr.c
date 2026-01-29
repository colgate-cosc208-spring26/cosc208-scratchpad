#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return -1;
    }

    int value = atoi(argv[1]);
    printf("Input value (decimal) = %d\n", value);



    return 0;
}
