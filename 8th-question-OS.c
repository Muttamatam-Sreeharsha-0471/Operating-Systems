#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_REQUESTS 100

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}
double average_head_movement(int requests[], int num_requests, int start) {
    int current = start;
    int total_head_movement = 0;
    for (int i = 0; i < num_requests; i++) {
        total_head_movement += abs_diff(current, requests[i]);
        current = requests[i];
    }

    return (double) total_head_movement / (double) num_requests;
}

int main() {
    int requests[MAX_REQUESTS];
    int num_requests, start;
    printf("Enter the number of requests: ");
    scanf("%d", &num_requests);

    printf("Enter the starting position of the disk head: ");
    scanf("%d", &start);

    printf("Enter the requests:\n");
    for (int i = 0; i < num_requests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }
    double avg_head_movement = average_head_movement(requests, num_requests, start);
    printf("Average head movement: %.2lf\n", avg_head_movement);

    return 0;
}