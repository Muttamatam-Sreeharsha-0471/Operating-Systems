#include <stdio.h>

#define MAX_PROCESSES 4
#define MAX_RESOURCES 3

int main() {
    int claim[MAX_PROCESSES][MAX_RESOURCES] = {{3, 2, 2},{6, 1, 3},{3, 1, 4},{4, 2, 2}};
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{1, 0, 0},{6, 1, 2},{2, 1, 1},{0, 0, 2}};
    
    int resourceVector[MAX_RESOURCES] = {9, 3, 6};
    
    int available[MAX_RESOURCES] = {0};
    int maxClaim[MAX_PROCESSES][MAX_RESOURCES] = {0};
    int need[MAX_PROCESSES][MAX_RESOURCES] = {0};
    int safeSequence[MAX_PROCESSES] = {0};
    
    int i, j, k;
    int completed = 0;
    // Initialize available resources
    for (i = 0; i < MAX_RESOURCES; i++) {
        for (j = 0; j < MAX_PROCESSES; j++) {
            available[i] += allocation[j][i];
        }
        available[i] = resourceVector[i] - available[i];
    }
    // Calculate the maximum claim and need matrices
    for (i = 0; i < MAX_PROCESSES; i++) {
        for (j = 0; j < MAX_RESOURCES; j++) {
            maxClaim[i][j] = claim[i][j] + allocation[i][j];
            need[i][j] = claim[i][j] - allocation[i][j];
        }
    }
    // Check for a safe sequence
    while (completed < MAX_PROCESSES) {
        int safe = 0;
        
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (!safeSequence[i]) {
                int resourceAvailable = 1;
                
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > available[j]) {
                        resourceAvailable = 0;
                        break;
                    }
                }
                if (resourceAvailable) {
                    safe = 1;
                    safeSequence[completed] = i;
                    completed++;
                    for (k = 0; k < MAX_RESOURCES; k++) {
                        available[k] += allocation[i][k];
                    }   
                    break;
                }
            }
        }   
        if (!safe) {
            printf("System is in an unsafe state.\n");
            return 0;
        }
    }
    printf("System is in a safe state. Safe sequence: ");
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
    
}
