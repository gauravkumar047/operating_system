#include <stdio.h>	
int main(){
    int process;
    float average_wt=0;
    printf("Enter number of processes : ");
    scanf("%d",&process);
    int arrival_time[47] = {0}, burst_time[47] = {0}, completion_time[47] = {0}, turn_around_time[47] = {0}, waiting_time[47] = {0}, process_id[47] = {0};
    printf("Enter arrival time and burst time  of the processes :\n ");
    
    int i, j; 
    for (i = 0; i < process; i++) {
        printf("process %d Arrival Time : ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("process %d Burst Time : ", i + 1);
        scanf("%d", &burst_time[i]);
        process_id[i] = i + 1;
    }

    int temp, temp1, temp2;

    for (i = 0; i < process - 1; i++) {
        for (j = 0; j < process - 1 - i; j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;

                temp1 = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp1;

                temp2 = process_id[j];
                process_id[j] = process_id[j + 1];
                process_id[j + 1] = temp2;
            }
        }
    }

    int completed = 0, time = 0, min_index; // Declare variables outside the loop
    int is_completed[47] = {0}; // Initialize the array to 0

    printf("\nProcess_no. | Arrival Time | Burst Time | Completion Time | TAT | Waiting Time\n");
    while (completed < process) {
        min_index = -1;
        int min_burst = 1000; // Declare and initialize min_burst outside the loop

        for (i = 0; i < process; i++) {
            if (arrival_time[i] <= time && is_completed[i] == 0) {
                if (burst_time[i] < min_burst) {
                    min_burst = burst_time[i];
                    min_index = i;
                }
            }
        }

        if (min_index == -1) {
            time++;
        } else {
            completion_time[min_index] = time + burst_time[min_index];
            time = completion_time[min_index];
            turn_around_time[min_index] = completion_time[min_index] - arrival_time[min_index];
            waiting_time[min_index] = turn_around_time[min_index] - burst_time[min_index];
            average_wt += waiting_time[min_index];
            is_completed[min_index] = 1;
            completed++;

            printf("P%d\t\t%d\t\t%d\t\t%d\t    %d\t    %d\n", process_id[min_index], arrival_time[min_index], burst_time[min_index], completion_time[min_index], turn_around_time[min_index], waiting_time[min_index]);
        }
    }
    printf("\nAverage Waiting Time = %f\n",average_wt/process);
    return 0;
}