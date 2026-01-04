#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

static unsigned long long count = 0;  // global variable

void *thread_hello(void *arg) {
    int myid, i;
    myid = *((int *)arg);

    printf("hello I'm thread %d\n", myid);

    for(i = 0; i < 1000000; i++) {
        count += i;
    }

    printf("goodbye I'm thread %d\n", myid);
    return (void *)0;  // recast 0 to return type (void *)
}


int main(int argc, char **argv) {
    pthread_t *tids;   	// thread ids
    int ntids, i, *tid_args;  //arguments passed to thread funcs.

    if (argc < 2) {
        printf("usage %s <numthreads>\n", argv[0]);
        return 0;
    }

    ntids = atoi(argv[1]);
    tids = (pthread_t *) malloc( sizeof(pthread_t) * ntids);
    tid_args = (int *) malloc( sizeof(int) * ntids);

    for (i=0; i < ntids; i++) { //loop through num. threads
        tid_args[i] = i; 	 //input argument for each thread.
        pthread_create(&tids[i], 0, thread_hello, &tid_args[i]);
    }   //create the thread, with tid, func ptr, and input args. 
   
    for (i=0; i < ntids; i++) {
        pthread_join(tids[i], 0);
    }
    return 0;
}


