#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2

int shared_data = 5;
sem_t semaphore;

void* double_thread(void* arg) {
  sem_wait(&semaphore);
  printf("Thread 1: Read %d from shared memory\n", shared_data);
  shared_data *= 2;
  printf("Thread 1: Doubled value is %d\n", shared_data);
  sem_post(&semaphore);
  pthread_exit(NULL);
}

void* five_thread(void* arg) {
  sem_wait(&semaphore);
  printf("Thread 2: Read %d from shared memory\n", shared_data);
  shared_data *= 5;
  printf("Thread 2: Five times value is %d\n", shared_data);
  sem_post(&semaphore);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;

  sem_init(&semaphore, 0, 1);

  rc = pthread_create(&threads[0], NULL, double_thread, NULL);
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
  }

  rc = pthread_create(&threads[1], NULL, five_thread, NULL);
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  sem_destroy(&semaphore);

  pthread_exit(NULL);
}
