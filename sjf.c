#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int burst_time;
} Process;

int compare(const void *a, const void *b) {
    Process *p1 = (Process*)a;
    Process *p2 = (Process*)b;
    return p1->burst_time - p2->burst_time;
}

void sjf(Process p[], int n) {
    int i;
    int time = 0;
    
    qsort(p, n, sizeof(Process), compare);
    
    for (i = 0; i < n; i++) {
        printf("Process %d starts at %d and finishes at %d\n", p[i].pid, time, time + p[i].burst_time);
        time += p[i].burst_time;
    }
}

int main() {
    Process processes[] = {{1, 10}, {2, 5}, {3, 8}};
    int n = 3;

    sjf(processes, n);

    return 0;
}
