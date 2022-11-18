//Priority Preemptive Schedulling
#include<stdio.h>
#include<stdlib.h>
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int n=0,i=0,j,quant=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int burst_time[n];
    int priority[n+1];
    int process[n];
    int arrival_time[n],temp[n];

    printf("Enter Arrival time,Burst time and Priority of all the processes:\n");
    for(i=0;i<n;i++)
    {
        process[i]=i+1;
        scanf("%d %d %d",&arrival_time[i],&burst_time[i],&priority[i]);
        temp[i]=burst_time[i];
    }
    priority[n+1]=9999;
    int count=0;
    int wait_time[n],turn_time[n];
    for(i=0;count!=n;i++)
    {
        int s=n+1;
    
        for(j=0;j<n;j++)
        {
            
            if(priority[s]>priority[j]&&arrival_time[j]<=i&&burst_time[j]>0)
            {
                s=j;
            }
        }
        burst_time[s]-=1;
        if(burst_time[s]==0)
        {
            count++;
            wait_time[s]=i+1-arrival_time[s]-temp[s];
            turn_time[s]=i+1-arrival_time[s];
        }
    }
    float avgwait=0.0,avgturn=0.0;
    for(i=0;i<n;i++)
    {
        avgwait+=wait_time[i];
    }
    for(int i=0;i<n;i++)
    {
        avgturn+=turn_time[i];
    }
    printf("Process---Wait Time---Turn Around Time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d---%d---%d\n",process[i],wait_time[i],turn_time[i]);
    }

    printf("\nAvg Waiting time:%f",avgwait/n);
    printf("\nAvg TurnAround Time:%f\n",avgturn/n);

    return 0;

}