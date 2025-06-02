#include <stdio.h>
#define MAX 100

void input_processes(int n, int pid[], int at[], int bt[]) {
    int i;
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time for process P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Enter burst time for process P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }
}

void calculate_srtf(int n, int pid[], int at[], int bt[], int ct[], int tat[], int wt[], int rt[]) {
    int remaining_bt[MAX], is_completed[MAX] = {0};
    int completed = 0, time = 0, i;

    for (i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
        rt[i] = -1;
    }

    while (completed != n) {
        int min_index = -1;
        int min_bt = 1e9;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && !is_completed[i] && remaining_bt[i] > 0) {
                if (remaining_bt[i] < min_bt || (remaining_bt[i] == min_bt && at[i] < at[min_index])) {
                    min_bt = remaining_bt[i];
                    min_index = i;
                }
            }
        }

        if (min_index == -1) {
            time++;
        } else {
            if (rt[min_index] == -1) {
                rt[min_index] = time;
            }
            remaining_bt[min_index]--;
            time++;

            if (remaining_bt[min_index] == 0) {
                ct[min_index] = time;
                tat[min_index] = ct[min_index] - at[min_index];
                wt[min_index] = tat[min_index] - bt[min_index];
                is_completed[min_index] = 1;
                completed++;
            }
        }
    }
}

void display_table(int n, int pid[], int at[], int bt[], int ct[], int tat[], int wt[], int rt[]) {
    float total_tat = 0, total_wt = 0, total_rt = 0;
    int i;

    printf("\n| Process | AT | BT | CT | TAT | WT | RT |\n");
    printf("|---------|----|----|----|-----|----|----|\n");

    for (i = 0; i < n; i++) {
        printf("|   P%-3d  | %-2d | %-2d | %-2d | %-3d | %-2d | %-2d |\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
        total_rt += rt[i];
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Response Time: %.2f\n", total_rt / n);
}

int main() {
    int n, pid[MAX], at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX], rt[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    input_processes(n, pid, at, bt);
    calculate_srtf(n, pid, at, bt, ct, tat, wt, rt);
    display_table(n, pid, at, bt, ct, tat, wt, rt);

    return 0;
}