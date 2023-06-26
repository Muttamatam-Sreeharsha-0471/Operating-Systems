#include <stdio.h>

#define MAX_PARTITIONS 4
#define MAX_PROCESSES 5

struct Partition {
    int size;
    int allocated;
};

struct Process {
    int size;
    int allocated_partition;
};

void worstFit(struct Partition partitions[], int num_partitions, struct Process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        int max_index = -1;
        for (int j = 0; j < num_partitions; j++) {
            if (partitions[j].allocated == 0 && partitions[j].size >= processes[i].size) {
                if (max_index == -1 || partitions[j].size > partitions[max_index].size) {
                    max_index = j;
                }
            }
        }
        if (max_index != -1) {
            partitions[max_index].allocated = 1;
            partitions[max_index].size -= processes[i].size;
            processes[i].allocated_partition = max_index;
        }
    }
}

void printMemoryMap(struct Partition partitions[], int num_partitions) {
    printf("Memory Map:\n");
    for (int i = 0; i < num_partitions; i++) {
        printf("Partition %d: %d KB", i, partitions[i].size);
        if (partitions[i].allocated == 1) {
            printf(" (Allocated)\n");
        } else {
            printf(" (Unallocated)\n");
        }
    }
    printf("\n");
}

int main() {
    struct Partition partitions[MAX_PARTITIONS] = {
        {40, 0},
        {10, 0},
        {30, 0},
        {60, 0}
    };

    struct Process processes[MAX_PROCESSES] = {
        {100, -1},
        {50, -1},
        {30, -1},
        {120, -1},
        {35, -1}
    };

    printf("Worst-Fit Algorithm:\n\n");
    printf("Initial Memory Map:\n");
    printMemoryMap(partitions, MAX_PARTITIONS);

    worstFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);

    printf("Memory Map after Allocation:\n");
    printMemoryMap(partitions, MAX_PARTITIONS);

    printf("Process Allocation:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d: ", i);
        if (processes[i].allocated_partition != -1) {
            printf("Allocated to Partition %d\n", processes[i].allocated_partition);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}