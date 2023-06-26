#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int processes[], int n, int burstTimes[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burstTimes[j] > burstTimes[j + 1]) {
                swap(&burstTimes[j], &burstTimes[j + 1]);
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void calculateTimes(int processes[], int n, int burstTimes[]) {
    int waitingTimes[n];
    int turnaroundTimes[n];
    
    waitingTimes[0] = 0;
    turnaroundTimes[0] = burstTimes[0];
    
    for (int i = 1; i < n; i++) {
        waitingTimes[i] = burstTimes[i - 1] + waitingTimes[i - 1];
        turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
    }
    
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }
    
    float averageWaitingTime = totalWaitingTime / n;
    float averageTurnaroundTime = totalTurnaroundTime / n;
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burstTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n];
    int burstTimes[n];
    
    printf("Enter the burst times for each process:\n");
    
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i);
        scanf("%d", &burstTimes[i]);
        processes[i] = i;
    }
    
    sort(processes, n, burstTimes);
    
    calculateTimes(processes, n, burstTimes);
    
    return 0;
}
