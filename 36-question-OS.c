#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int abs_diff(int a, int b) {
    return abs(a - b);
}

int findClosestTrack(int tracks[], int n, int head) {
    int minDiff = INT_MAX;
    int closestTrack;
    
    for (int i = 0; i < n; i++) {
        int diff = abs_diff(tracks[i], head);
        if (diff < minDiff) {
            minDiff = diff;
            closestTrack = tracks[i];
        }
    }
    
    return closestTrack;
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
    int currentTrack = head;
    
    printf("\nSequence of track accesses: ");
    
    for (int i = 0; i < n; i++) {
        int closestTrack = findClosestTrack(tracks, n, currentTrack);
        totalHeadMovement += abs_diff(currentTrack, closestTrack);
        
        printf("%d ", closestTrack);
        
        currentTrack = closestTrack;
        
        // Mark the track as visited by setting it to -1
        for (int j = 0; j < n; j++) {
            if (tracks[j] == closestTrack) {
                tracks[j] = -1;
                break;
            }
        }
    }
    
    printf("\n\nAverage head movement: %.2f\n", (float) totalHeadMovement / n);
    
    return 0;
}
