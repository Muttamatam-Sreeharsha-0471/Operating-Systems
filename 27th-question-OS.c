#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_INSTANCES 4

sem_t semaphore;

void *process(void *id) {
    int process_id = *(int *)id;
    printf("Process P%d is waiting on semaphore\n", process_id);

    sem_wait(&semaphore);
    printf("Process P%d has acquired the semaphore\n", process_id);

    // Simulate some work being done
    sleep(1);

    printf("Process P%d is releasing the semaphore\n", process_id);
    sem_post(&semaphore);

    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_INSTANCES];
    int process_ids[NUM_INSTANCES] = {1, 2, 3, 4};

    // Initialize semaphore with NUM_INSTANCES instances
    sem_init(&semaphore, 0, NUM_INSTANCES);

    // Create threads for each process
    for (i = 0; i < NUM_INSTANCES; i++) {
        pthread_create(&threads[i], NULL, process, &process_ids[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_INSTANCES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
}
