#include <stdio.h>
#include <stdbool.h>

int findOptimalPage(int pages[], int n, int frames[], int m, int index) {
    int optimalPage = -1;
    int farthestIndex = -1;
    
    for (int i = 0; i < m; i++) {
        int j;
        for (j = index + 1; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthestIndex) {
                    farthestIndex = j;
                    optimalPage = i;
                }
                break;
            }
        }
        
        if (j == n) {
            return i;
        }
    }
    
    return (optimalPage == -1) ? 0 : optimalPage;
}

int main() {
    int n, m;
    
    printf("Enter the number of page frames: ");
    scanf("%d", &m);
    
    int frames[m];
    
    for (int i = 0; i < m; i++) {
        frames[i] = -1;
    }
    
    printf("Enter the page reference sequence (-1 to end input):\n");
    
    int pages[100];
    int page;
    int pageCount = 0;
    
    while (true) {
        scanf("%d", &page);
        if (page == -1) {
            break;
        }
        pages[pageCount++] = page;
    }
    
    n = pageCount;
    
    int pageFaults = 0;
    
    for (int i = 0; i < n; i++) {
        bool pageFault = true;
        
        for (int j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                pageFault = false;
                break;
            }
        }
        
        if (pageFault) {
            if (frames[m - 1] != -1) {
                int optimalPage = findOptimalPage(pages, n, frames, m, i);
                frames[optimalPage] = pages[i];
            } else {
                for (int j = 0; j < m; j++) {
                    if (frames[j] == -1) {
                        frames[j] = pages[i];
                        break;
                    }
                }
            }
            
            pageFaults++;
        }
        
        printf("Page reference: %d\n", pages[i]);
        printf("Current page frames: ");
        for (int j = 0; j < m; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n\n");
    }
    
    printf("Total number of page faults: %d\n", pageFaults);
    
    return 0;
}
