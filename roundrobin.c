#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

void round_robin(Process p[], int n, int quantum) {
    int time = 0, i;
    int all_done = 0;
    
    while (!all_done) {
        all_done = 1;
        for (i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                all_done = 0; // There's at least one process not done
                if (p[i].remaining_time > quantum) {
                    time += quantum;
                    p[i].remaining_time -= quantum;
                } else {
                    time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    printf("Process %d finishes at time %d\n", p[i].pid, time);
                }
            }
        }
    }
}

int main() {
    Process processes[] = {{1, 0, 10}, {2, 1, 5}, {3, 2, 8}};
    int n = 3;
    int quantum = 3;

    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    round_robin(processes, n, quantum);

    return 0;
}
