#include <stdio.h>

#define MAX 10
void lruPageReplacement(int pages[], int n, int frameSize) {
    int frames[frameSize], counter[MAX];
    int pageFaults = 0, i, j, k, found, oldestPageIndex, minCounter;
    for (i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }
    for (i = 0; i < MAX; i++) {
        counter[i] = -1;
    }

    printf("Page\tFrames\n");
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < frameSize; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                counter[j] = i; 
                break;
            }
        }
        if (!found) {
            minCounter = i;
            oldestPageIndex = 0;

            for (k = 0; k < frameSize; k++) {
                if (counter[k] < minCounter) {
                    minCounter = counter[k];
                    oldestPageIndex = k;
                }
            }
            frames[oldestPageIndex] = pages[i];
            counter[oldestPageIndex] = i;
            pageFaults++;
            printf("%d\t", pages[i]);
            for (j = 0; j < frameSize; j++) {
                if (frames[j] != -1) {
                    printf("%d ", frames[j]);
                }
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[100], n, frameSize, i;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frameSize);

    lruPageReplacement(pages, n, frameSize);

    return 0;
}
