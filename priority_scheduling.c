#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int priority;
    int burst_time;
} Process;

int compare(const void *a, const void *b) {
    Process *p1 = (Process*)a;
    Process *p2 = (Process*)b;
    
    if (p1->priority != p2->priority) return p1->priority - p2->priority;
    return p1->pid - p2->pid;  
}

void priority_scheduling(Process p[], int n) {
    int i;
    int time = 0;
    
    qsort(p, n, sizeof(Process), compare);
    // priories : 1,2,3
    
    for (i = 0; i < n; i++) {
        printf("Process %d starts at %d and finishes at %d\n", p[i].pid, time, time + p[i].burst_time);
        time += p[i].burst_time;
    }
}

int main() {
    Process processes[] = {{1, 2, 10}, {2, 1, 5}, {3, 3, 8}};
    int n = 3;

    priority_scheduling(processes, n);

    return 0;
}
