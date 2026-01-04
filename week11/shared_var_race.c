#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int shared = 40;

void *threadA(void *arg) {
    int loops = *((int*)arg);
    int a,b;
    for (int i = 0; i < loops; i++) {
        a = shared; // getShared
        b = 10;
        a = a + b;
        shared = a; // saveShared
    }
    
    return NULL;
}

void *threadB(void *arg) {
    int loops = *((int*)arg);
    int a,b;
    for (int i = 0; i < loops; i++) {
        a = shared; // getShared
        b = 20;
        a = a - b;
        shared = b; // saveShared
    }

    return NULL;
}

int main(int argc, char **argv) {
    int loops = 1;
    if (argc > 1) {
        loops = atoi(argv[1]);
    }

    pthread_t tid[2];//two thread ids

    printf("begin: shared=%d\n", shared);
    pthread_create(&tid[0], NULL, threadA, &loops);
    pthread_create(&tid[1], NULL, threadB, &loops);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    printf("end: shared=%d\n", shared);

    return 0;
}
