#include <stdio.h>
#include <stdbool.h>
#include "memory.h"
#include "algorithms.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

bool page_exists(Memory *mem, int page) {
    for (int i = 0; i < mem->frame_count; i++) {
        if (mem->frames[i] == page)
            return true;
    }
    return false;
}

void print_results(char *name, Memory *mem, int total_pages) {
    printf(BLUE "\n========== FIFO ==========\n" RESET);
    printf("Page Faults : %d\n", mem->page_faults);
    printf("Page Hits   : %d\n", mem->page_hits);

    float hit_ratio = (float)mem->page_hits / total_pages;
    float fault_ratio = (float)mem->page_faults / total_pages;

    printf("Hit Ratio   : %.2f\n", hit_ratio);
    printf("Fault Ratio : %.2f\n", fault_ratio);
}

void fifo(int pages[], int n, int frame_count) {
    Memory mem;
    initialize_memory(&mem, frame_count);

    int index = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        printf("\nRequest Page: %d\n", page);

        if (page_exists(&mem, page)) {
            mem.page_hits++;
            printf("Page Hit!\n");
        } else {
            mem.page_faults++;
            mem.frames[index] = page;
            index = (index + 1) % frame_count;

            printf("Page Fault!\n");
        }

        display_frames(&mem);
    }

    print_results("FIFO", &mem, n);
}

void lru(int pages[], int n, int frame_count) {
    Memory mem;
    initialize_memory(&mem, frame_count);

    int recent[MAX_FRAMES];

    for (int i = 0; i < frame_count; i++)
        recent[i] = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        printf("\nRequest Page: %d\n", page);

        bool hit = false;

        for (int j = 0; j < frame_count; j++) {
            if (mem.frames[j] == page) {
                mem.page_hits++;
                recent[j] = i;
                hit = true;

                printf(GREEN "Page Hit!\n" RESET);
                break;
            }
        }

        if (!hit) {
            mem.page_faults++;

            int replace_index = 0;

            for (int j = 1; j < frame_count; j++) {
                if (recent[j] < recent[replace_index]) {
                    replace_index = j;
                }
            }

            mem.frames[replace_index] = page;
            recent[replace_index] = i;

            printf(RED "Page Fault!\n" RESET);
        }

        display_frames(&mem);
    }

    print_results("LRU", &mem, n);
}

int find_optimal(int pages[], int frames[], int n, int current, int frame_count) {
    int farthest = current;
    int index = -1;

    for (int i = 0; i < frame_count; i++) {
        int j;

        for (j = current; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }

        if (j == n)
            return i;
    }

    if (index == -1)
        return 0;
    else
        return index;
}

void optimal(int pages[], int n, int frame_count) {
    Memory mem;
    initialize_memory(&mem, frame_count);

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        printf("\nRequest Page: %d\n", page);

        if (page_exists(&mem, page)) {
            mem.page_hits++;
            printf("Page Hit!\n");
        } else {
            mem.page_faults++;

            int empty = -1;

            for (int j = 0; j < frame_count; j++) {
                if (mem.frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if (empty != -1) {
                mem.frames[empty] = page;
            } else {
                int replace_index = find_optimal(
                    pages,
                    mem.frames,
                    n,
                    i + 1,
                    frame_count
                );

                mem.frames[replace_index] = page;
            }

            printf("Page Fault!\n");
        }

        display_frames(&mem);
    }

    print_results("Optimal", &mem, n);
}