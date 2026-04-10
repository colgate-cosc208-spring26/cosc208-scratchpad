#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    pid_t parent = getpid();
    printf("Process %d started\n", (int)parent);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork:");
        return -1;
    } else if (pid == 0) {
        printf("This is the child process\n");
        sleep(30);
    } else { // pid > 0
        printf("This is the parent process; my kid's pid is %d\n", pid);
        wait(NULL);
    }
    return 0;
}

