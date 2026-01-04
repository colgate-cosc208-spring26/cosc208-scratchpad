#include <stdio.h>
#include <pthread.h>

void *hello(void *arg); //thread’s "main" function

int main() {
  pthread_t tid[2];//two thread ids
   
  pthread_create(&tid[0], NULL, hello, NULL);
  pthread_create(&tid[1], NULL, hello, NULL);
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  return 0;
}
void *hello(void *arg) {
  printf("Hello, world!\n"); 
  return NULL;
}
