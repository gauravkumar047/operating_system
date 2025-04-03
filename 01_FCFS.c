#include <stdio.h>	
int main(){
    int process, completion=0;
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
    printf("Process_no. | Arrival Time | Burst Time | Completion Time | TAT | Waiting Time\n");
    for(int i=0; i<process; i++){
        if (completion<arrival_time[i]){
            completion=arrival_time[i];
        }
        completion=completion+burst_time[i];
        completion_time[i]=completion;
        turn_around_time[i]=completion_time[i]-arrival_time[i];
        waiting_time[i]=turn_around_time[i]-burst_time[i];
        average_wt=average_wt+waiting_time[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\t    %d\t    %d\n",process_id[i],arrival_time[i],burst_time[i],completion_time[i], turn_around_time[i], waiting_time[i]);
    }printf("\nAverage Waiting Time = %f\n",average_wt/process);
    return 0;
}