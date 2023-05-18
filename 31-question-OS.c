#include <stdio.h>
#include <stdlib.h>

#define TRACKS 5

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

// Function to find the index of the track that is just greater than the head position
int findNextTrack(int tracks[], int n, int head) {
    for (int i = 0; i < n; i++) {
        if (tracks[i] > head)
            return i;
    }
    return 0; // If no greater track is found, return the first track
}

// Function to calculate the total head movement using CSCAN algorithm
int cscan(int tracks[], int n, int head) {
    int totalMovement = 0;

    sortTracks(tracks, n);

    int nextTrack = findNextTrack(tracks, n, head);
    if (nextTrack == 0) {
        totalMovement += abs(tracks[n-1] - head); // Move to the last track
        totalMovement += abs(tracks[0] - tracks[n-1]); // Move to the first track
    }
    else {
        totalMovement += abs(tracks[nextTrack] - head); // Move to the next track
        totalMovement += abs(tracks[nextTrack-1] - tracks[0]); // Move to the first track
    }

    return totalMovement;
}

int main() {
    int tracks[TRACKS] = {55, 58, 60, 70, 18};
    int head = 50; // Starting head position

    int totalMovement = cscan(tracks, TRACKS, head);
    float averageMovement = (float)totalMovement / TRACKS;

    printf("Average head movement: %.2f\n", averageMovement);

    return 0;
}
