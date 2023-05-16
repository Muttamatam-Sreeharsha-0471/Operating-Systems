#include <stdio.h>

#define NUM_PARTITIONS 4
#define MAX_PROCESSES 5

int main() {
    int partitions[NUM_PARTITIONS] = {40, 10, 30, 60}; // Memory partitions in KB
    int processes[MAX_PROCESSES] = {100, 50, 30, 120, 35}; // Processes in KB
    int allocated[MAX_PROCESSES] = {0}; // Keep track of which processes have been allocated

    printf("Memory partitions:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("%d KB\n", partitions[i]);
    }
    printf("\n");

    for (int i = 0; i < MAX_PROCESSES; i++) {
        int j;
        for (j = 0; j < NUM_PARTITIONS; j++) {
            if (processes[i] <= partitions[j]) {
                printf("Process %d of size %d KB allocated to partition %d of size %d KB\n", i + 1, processes[i], j + 1, partitions[j]);
                partitions[j] -= processes[i];
                allocated[i] = 1;
                break;
            }
        }
        if (j == NUM_PARTITIONS) {
            printf("Process %d of size %d KB cannot be allocated\n", i + 1, processes[i]);
        }
    }

    printf("\nMemory partitions after allocation:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("%d KB\n", partitions[i]);
    }

    return 0;
}
