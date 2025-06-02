#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int frameSize) {
    int frames[frameSize];
    int pageFaults = 0;
    int index, i, j, found, oldestPageIndex;
    for (i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    printf("Page\tFrames\n");

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < frameSize; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (index < frameSize) {
                frames[index++] = pages[i];
            }
            else {
                for (j = 0; j < frameSize - 1; j++) {
                    frames[j] = frames[j + 1];
                }
                frames[frameSize - 1] = pages[i];
            }
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

    fifoPageReplacement(pages, n, frameSize);

    return 0;
}
