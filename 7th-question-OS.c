#include <stdio.h>
#include <stdbool.h>

#define NUM_FRAMES 3

int main() {
    int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int num_pages = sizeof(pages) / sizeof(int);

    int frames[NUM_FRAMES];
    int num_faults = 0;
    int i, j, k;

    for (i = 0; i < NUM_FRAMES; i++) {
        frames[i] = -1;
    }
    for (i = 0; i < num_pages; i++) {
        bool page_found = false;

        for (j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                page_found = true;

                for (k = j; k > 0; k--) {
                    frames[k] = frames[k-1];
                }
                frames[0] = pages[i];

                break;
            }
        }

        if (!page_found) {
            num_faults++;

            for (j = NUM_FRAMES - 1; j > 0; j--) {
                frames[j] = frames[j-1];
            }

            frames[0] = pages[i];
        }

        printf("%d: ", pages[i]);
        for (j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", num_faults);

    return 0;
}