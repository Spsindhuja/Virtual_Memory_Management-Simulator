# Virtual_Memory_Management_Simulator
A Linux-based Virtual Memory Management Simulator implemented in C that demonstrates core Operating Systems concepts including page replacement algorithms, page fault handling, and memory frame allocation.

# Features
- FIFO Page Replacement
- LRU Page Replacement
- Optimal Page Replacement
- Real-time frame visualization
- Page hit and page fault analysis
- Hit ratio and fault ratio calculation
- Interactive user input
- Modular C architecture
- Linux terminal execution

# Algorithms Implemented

## FIFO (First In First Out)
Replaces the oldest page in memory first.

## LRU (Least Recently Used)
Replaces the page that has not been used for the longest time.

## Optimal Page Replacement
Replaces the page that will not be used for the longest duration in the future.

# Project Structure
text
Virtual_Memory_Management_Simulator/
│
├── main.c
├── memory.c
├── memory.h
├── algorithms.c
├── algorithms.h
├── Makefile
└── README.md

# Tech Stack
- C Programming
- GCC Compiler
- Linux
- Makefile


# Compilation
```bash
make
```
# Run
```bash
make run
```

# Sample Input
```text
Enter number of pages: 10

Enter reference string:
7 0 1 2 0 3 0 4 2 3

Enter number of frames: 3
```

# Sample Output
========== FIFO ==========
Page Faults : 9
Page Hits   : 1

========== LRU ==========
Page Faults : 6
Page Hits   : 4

========== Optimal ==========
Page Faults : 6
Page Hits   : 4


# Concepts Demonstrated
- Virtual Memory
- Paging
- Page Replacement Policies
- Memory Management
- Cache Optimization
- Operating Systems Internals
- Linux Systems Programming

# Future Improvements
- LFU Page Replacement
- Clock Algorithm
- GUI Visualization
- Performance Graphs
- Multi-level Paging Simulation
- Colored Terminal Output

# Author
S P Sindhuja
