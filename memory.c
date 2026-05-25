#include <stdio.h>
#include "memory.h"

void initialize_memory(Memory *mem, int frame_count) {
    mem->frame_count = frame_count;
    mem->page_faults = 0;
    mem->page_hits = 0;

    for (int i = 0; i < frame_count; i++) {
        mem->frames[i] = -1;
    }
}

void display_frames(Memory *mem) {
    printf("Frames: ");

    for (int i = 0; i < mem->frame_count; i++) {
        if (mem->frames[i] == -1)
            printf("- ");
        else
            printf("%d ", mem->frames[i]);
    }

    printf("\n");
}