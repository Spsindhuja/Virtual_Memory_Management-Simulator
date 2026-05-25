#include <stdio.h>
#include "algorithms.h"

int main() {
    int n;
    int frame_count;

    int pages[100];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frame_count);

    printf("\nReference String:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }

    printf("\n");

    fifo(pages, n, frame_count);

    printf("\n\n");

    lru(pages, n, frame_count);

    printf("\n\n");

    optimal(pages, n, frame_count);

    return 0;
}