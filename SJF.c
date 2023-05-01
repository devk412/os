#include<stdio.h>
struct process{
    int id;
    int burst;
    int waiting;
    int turnaround;
};
int main(){
    int n;
    float total_wait_time=0,total_turnaround_time=0,avg_wait_time,avg_turnaround_time;
    
    printf("Enter no of processes: ");
    scanf("%d",&n);
    struct process p[n];
    
    for(int i=0;i<n;i++){
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&p[i].burst);
        p[i].id=i+1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].burst>p[j].burst){
                struct process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
    if(i==0)
    {
        p[i].waiting=0;
        p[i].turnaround=p[i].burst;
    }
    else{
        p[i].waiting=p[i-1].waiting+p[i-1].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;
    }
    total_turnaround_time+=p[i].turnaround;
    total_wait_time+=p[i].waiting;
    }
    avg_wait_time=total_wait_time/n;
    avg_turnaround_time=total_turnaround_time/n;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n",p[i].id,p[i].burst,p[i].waiting,p[i].turnaround);
    }
    
    printf("Average waiting time = %.2f\N",avg_wait_time);
    printf("Average turnaroud time = %.2f",avg_turnaround_time);
    
    
    
}
