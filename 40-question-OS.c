#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int abs_diff(int a, int b) {
    return abs(a - b);
}

int main() {
    int n, head;
    
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    
    int tracks[n];
    
    printf("Enter the track positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    int totalHeadMovement = 0;
    
    // Sort the track positions in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }
    
    // Find the index where head is located
    int i;
    for (i = 0; i < n; i++) {
        if (tracks[i] >= head) {
            break;
        }
    }
    
    // Move towards the right end
    for (int j = i; j < n; j++) {
        totalHeadMovement += abs_diff(head, tracks[j]);
        head = tracks[j];
    }
    
    // Move to the left end
    totalHeadMovement += abs_diff(head, tracks[0]);
    head = tracks[0];
    
    // Move towards the right end again
    for (int j = 1; j < i; j++) {
        totalHeadMovement += abs_diff(head, tracks[j]);
        head = tracks[j];
    }
    
    printf("\nAverage head movement: %.2f\n", (float) totalHeadMovement / n);
    
    return 0;
}
