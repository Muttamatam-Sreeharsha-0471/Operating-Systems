#include <stdio.h>

#define MAX_PROCESSES 10

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

int num_processes = 4;
struct process processes[MAX_PROCESSES];

int main() {
    // Initialize processes
    processes[0].id = 1;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 5;
    processes[0].remaining_time = processes[0].burst_time;

    processes[1].id = 2;
    processes[1].arrival_time = 1;
    processes[1].burst_time = 3;
    processes[1].remaining_time = processes[1].burst_time;

    processes[2].id = 3;
    processes[2].arrival_time = 2;
    processes[2].burst_time = 3;
    processes[2].remaining_time = processes[2].burst_time;

    processes[3].id = 4;
    processes[3].arrival_time = 4;
    processes[3].burst_time = 1;
    processes[3].remaining_time = processes[3].burst_time;

    int t = 0; // current time
    int completed = 0; // number of completed processes
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (completed < num_processes) {
        int shortest = -1; // index of process with shortest remaining time
        int shortest_time = 10000; // shortest remaining time
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= t && processes[i].remaining_time < shortest_time && processes[i].remaining_time > 0) {
                shortest = i;
                shortest_time = processes[i].remaining_time;
            }
        }
        if (shortest == -1) {
            t++;
            continue;
        }
        processes[shortest].remaining_time--;
        if (processes[shortest].remaining_time == 0) {
            completed++;
            int turnaround_time = t - processes[shortest].arrival_time + 1;
            int waiting_time = turnaround_time - processes[shortest].burst_time;
            total_turnaround_time += turnaround_time;
            total_waiting_time += waiting_time;
        }
        t++;
    }

    float avg_waiting_time = (float)total_waiting_time / num_processes;
    float avg_turnaround_time = (float)total_turnaround_time / num_processes;

    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}