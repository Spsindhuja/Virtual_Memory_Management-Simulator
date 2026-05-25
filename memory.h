#ifndef MEMORY_H
#define MEMORY_H

#define MAX_FRAMES 100
#define MAX_REFERENCE 1000

typedef struct {
    int frames[MAX_FRAMES];
    int frame_count;
    int page_faults;
    int page_hits;
} Memory;

void initialize_memory(Memory *mem, int frame_count);
void display_frames(Memory *mem);

#endif