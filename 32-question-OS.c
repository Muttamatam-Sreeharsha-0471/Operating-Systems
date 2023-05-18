#include <stdio.h>
#include <stdlib.h>

#define TRACKS 9

// Function to sort the track positions in ascending order
void sortTracks(int tracks[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (tracks[j] > tracks[j+1]) {
                temp = tracks[j];
                tracks[j] = tracks[j+1];
                tracks[j+1] = temp;
            }
        }
    }
}

// Function to calculate the total head movement using SCAN algorithm
int scan(int tracks[], int n, int head, int direction) {
    int totalMovement = 0;

    sortTracks(tracks, n);

    int currentTrack = 0;
    int i;

    if (direction == 1) {
        // Move towards higher track numbers
        for (i = 0; i < n; i++) {
            if (tracks[i] >= head) {
                currentTrack = i;
                break;
            }
        }

        // Move to the highest track
        totalMovement += abs(tracks[currentTrack] - head);

        // Move to the higher tracks
        for (i = currentTrack; i < n-1; i++) {
            totalMovement += abs(tracks[i+1] - tracks[i]);
        }

        // Move to the lowest track
        totalMovement += abs(tracks[n-1] - tracks[currentTrack]);
    }
    else {
        // Move towards lower track numbers
        for (i = n-1; i >= 0; i--) {
            if (tracks[i] <= head) {
                currentTrack = i;
                break;
            }
        }

        // Move to the lowest track
        totalMovement += abs(tracks[currentTrack] - head);

        // Move to the lower tracks
        for (i = currentTrack; i > 0; i--) {
            totalMovement += abs(tracks[i] - tracks[i-1]);
        }

        // Move to the highest track
        totalMovement += abs(tracks[0] - tracks[currentTrack]);
    }

    return totalMovement;
}

int main() {
    int tracks[TRACKS] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int head = 50; // Starting head position
    int direction = 1; // 1 for higher track numbers, 0 for lower track numbers

    int totalMovement = scan(tracks, TRACKS, head, direction);
    float averageMovement = (float)totalMovement / TRACKS;

    printf("Average head movement: %.2f\n", averageMovement);

    return 0;
}
