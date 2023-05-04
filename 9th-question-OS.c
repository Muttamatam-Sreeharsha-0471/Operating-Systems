#include <stdio.h>

#define MAX_PROCESSES 100

struct Process {
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    struct Process processes[MAX_PROCESSES];
    int num_processes;

    // Read the number of processes and their arrival times and burst times
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the arrival times and burst times of the processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    // Compute the waiting time and turnaround time for each process
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        // Compute the waiting time for the current process
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
        }

        // Compute the turnaround time for the current process
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        // Update the current time to account for the current process
        current_time += processes[i].burst_time;
    }

    // Compute the average waiting time and average turnaround time
    double total_waiting_time = 0.0;
    double total_turnaround_time = 0.0;
    for (int i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    double avg_waiting_time = total_waiting_time / (double) num_processes;
    double avg_turnaround_time = total_turnaround_time / (double) num_processes;

    // Print the results
    printf("Average waiting time: %.2lf\n", avg_waiting_time);
    printf("Average turnaround time: %.2lf\n", avg_turnaround_time);

    return 0;
}