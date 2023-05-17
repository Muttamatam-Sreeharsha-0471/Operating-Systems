#include <stdio.h>
#include <pthread.h>

void *printEven(void *args) {
    int i;
    for (i = 0; i <= 20; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

void *printOdd(void *args) {
    int i;
    for (i = 1; i <= 20; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t evenThread, oddThread;
    pthread_create(&evenThread, NULL, printEven, NULL);
    pthread_create(&oddThread, NULL, printOdd, NULL);
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);
    return 0;
}
