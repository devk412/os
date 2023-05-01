#include<stdio.h>
int main(){
    int n,i;
    float total_turnaround_time=0,total_waiting_time=0,avg_turnaround_time,avg_waiting_time;
    printf("Enter no of processes: ");
    scanf("%d",&n);
    int burst_time[n],turnaround_time[n],waiting_time[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter burst time of process %d: ",i+1);
        scanf("%d",&burst_time[i]);
    }
    waiting_time[0]=0;
    for(int i=1;i<n;i++)
    {
        waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
    }
    for(int i=0;i<n;i++){
        turnaround_time[i]=waiting_time[i]+burst_time[i];
    }
    for(int i=0;i<n;i++)
    {
        total_waiting_time+=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
    }
    for(int i=0;i<n;i++){
        avg_waiting_time=total_waiting_time/n;
        avg_turnaround_time=total_turnaround_time/n;
    }
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",i+1,burst_time[i],waiting_time[i],turnaround_time[i]);
    }
    printf("The average waiting time = %.2f",avg_waiting_time);
    printf("The average turnaround time = %.2f",avg_turnaround_time);
}