#include <stdio.h>

#define NUM_PROCESSES 3
#define NUM_RESOURCES 3

int max[NUM_PROCESSES][NUM_RESOURCES] = {
    {3, 6, 8},
    {4, 3, 3},
    {3, 4, 4}
};

int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {3, 3, 3},
    {2, 0, 3},
    {1, 2, 4}
};

int available[NUM_RESOURCES] = {1, 2, 0};

int marked[NUM_PROCESSES] = {0};

int main() {
    int need[NUM_PROCESSES][NUM_RESOURCES];
    int work[NUM_RESOURCES];
    int i, j, k;
    int count = 0;

    // Initialize need matrix
    for (i = 0; i < NUM_PROCESSES; i++) {
        for (j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize work vector
    for (i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    // Mark processes that can finish
    for (i = 0; i < NUM_PROCESSES; i++) {
        if (marked[i] == 0) {
            int can_finish = 1;
            for (j = 0; j < NUM_RESOURCES; j++) {
                if (need[i][j] > work[j]) {
                    can_finish = 0;
                    break;
                }
            }
            if (can_finish) {
                marked[i] = 1;
                count++;
                for (k = 0; k < NUM_RESOURCES; k++) {
                    work[k] += allocation[i][k];
                }
                i = -1; // start over
            }
        }
    }

    // Check for deadlock
    if (count < NUM_PROCESSES) {
        printf("Deadlock detected!\n");
        printf("Deadlocked processes: ");
        for (i = 0; i < NUM_PROCESSES; i++) {
            if (marked[i] == 0) {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    } else {
        printf("No deadlock detected.\n");
    }

    return 0;
}