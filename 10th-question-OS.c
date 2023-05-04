#include <stdio.h>

#define P 5 
#define R 3 

int main() {
    int allocation[P][R] = { {1, 1, 2}, {2, 1, 2}, {3, 0, 1}, {0, 2, 0}, {1, 1, 2} };
    int max[P][R] = { {5, 4, 4}, {4, 3, 3}, {9, 1, 3}, {8, 6, 4}, {2, 2, 3} };
    int available[R] = {3, 2, 1};
    int need[P][R];

    for(int i = 0; i < P; i++) {
        for(int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("Need Matrix:\n");
    for(int i = 0; i < P; i++) {
        for(int j = 0; j < R; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}