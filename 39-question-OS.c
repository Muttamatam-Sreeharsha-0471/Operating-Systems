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
    
    int startIndex = 0;
    int endIndex = n - 1;
    
    // Find the index where head is located
    int i;
    for (i = 0; i < n; i++) {
        if (tracks[i] >= head) {
            break;
        }
    }
    
    int direction; // 0 for left, 1 for right
    
    if (i == 0) {
        direction = 1;
    } else if (i == n) {
        direction = 0;
    } else {
        // Determine the closest end to start the movement
        int leftDistance = abs_diff(head, tracks[i - 1]);
        int rightDistance = abs_diff(head, tracks[i]);
        direction = (leftDistance < rightDistance) ? 0 : 1;
    }
    
    if (direction == 0) {
        // Move towards the left end
        for (int j = i - 1; j >= 0; j--) {
            totalHeadMovement += abs_diff(head, tracks[j]);
            head = tracks[j];
        }
        
        // Move towards the right end
        for (int j = i; j < n; j++) {
            totalHeadMovement += abs_diff(head, tracks[j]);
            head = tracks[j];
        }
    } else {
        // Move towards the right end
        for (int j = i; j < n; j++) {
            totalHeadMovement += abs_diff(head, tracks[j]);
            head = tracks[j];
        }
        
        // Move towards the left end
        for (int j = i - 1; j >= 0; j--) {
            totalHeadMovement += abs_diff(head, tracks[j]);
            head = tracks[j];
        }
    }
    
    printf("\nAverage head movement: %.2f\n", (float) totalHeadMovement / n);
    
    return 0;
}
