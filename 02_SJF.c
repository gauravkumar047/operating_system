#include <stdio.h>	
int main(){
    int process;
    float average_wt=0;
    printf("Enter number of processes : ");
    scanf("%d",&process);
    int arrival_time[47], burst_time[47], completion_time[47], turn_around_time[47], waiting_time[47], process_id[47];
    printf("Enter arrival time and burst time  of the processes :\n ");
    for(int i=0; i<process; i++){
        printf("process %d Arrival Time : ",i+1);
        scanf("%d",&arrival_time[i]);
        printf("process %d Burst Time : ",i+1);
        scanf("%d",&burst_time[i]);
        process_id[i]=i+1;
    }
    for(int i=0; i<process-1; i++){
        for(int j=0; j<process-1-i; j++){
            if(arrival_time[j]>arrival_time[j+1]){
                int temp=0, temp1=0, temp2;
                temp=arrival_time[j];
                arrival_time[j]=arrival_time[j+1];
                arrival_time[j+1]=temp;
                temp1=burst_time[j];
                burst_time[j]=burst_time[j+1];
                burst_time[j+1]=temp1;
                temp2=process_id[j];
                process_id[j]=process_id[j+1];
                process_id[j+1]=temp2;
            }
        }
    }
    int completed=0, time=0, is_completed[process], min_index;
    for(int i=0; i<process; i++){
        is_completed[i]=0;
    }
    printf("\nProcess_no. | Arrival Time | Burst Time | Completion Time | TAT | Waiting Time\n");
    while(completed<process){
        min_index=-1;
        int  min_burst=1000;
        for(int i=0; i<process; i++){
            if(arrival_time[i]<=time && is_completed[i]==0){
                if(burst_time[i]<min_burst){
                    min_burst=burst_time[i];
                    min_index=i;
                }
            }
        }
        if(min_burst==-1){
            time++;
        }else{
            completion_time[min_index]=time+burst_time[min_index];
            time=completion_time[min_index];
            turn_around_time[min_index]=completion_time[min_index]-arrival_time[min_index];
            waiting_time[min_index]=turn_around_time[min_index]-burst_time[min_index];
            average_wt=average_wt+waiting_time[min_index];
            is_completed[min_index]=1;
            completed++;
            time=completion_time[min_index];
            printf("P%d\t\t%d\t\t%d\t\t%d\t    %d\t    %d\n", process_id[min_index], arrival_time[min_index], burst_time[min_index], completion_time[min_index], turn_around_time[min_index], waiting_time[min_index]);

        }
    }
    printf("\nAverage Waiting Time = %f\n",average_wt/process);
    return 0;
}