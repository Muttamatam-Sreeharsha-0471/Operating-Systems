#include<stdio.h>
#include<conio.h>
struct process
{
    int pid,burst_time,arrival_time,waiting_time,turnaround_time;
};
int main()
{
    int n,i;
    float avg_waiting_time=0,avg_turnaround_time=0;
    struct process p[20];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("\nEnter the arrival time and burst time for process %d: ",p[i].pid);
        scanf("%d%d",&p[i].arrival_time,&p[i].burst_time);
        p[i].waiting_time=0;
        p[i].turnaround_time=0;
    }
    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        if(i==0)
            p[i].turnaround_time=p[i].burst_time;
        else
            p[i].turnaround_time=p[i-1].turnaround_time+p[i].burst_time;
        p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
        avg_waiting_time+=p[i].waiting_time;
        avg_turnaround_time+=p[i].turnaround_time;
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    }
    avg_waiting_time/=n;
    avg_turnaround_time/=n;
    printf("\n\nAverage waiting time: %.2f",avg_waiting_time);
    printf("\nAverage turnaround time: %.2f",avg_turnaround_time);
    return 0;
}
