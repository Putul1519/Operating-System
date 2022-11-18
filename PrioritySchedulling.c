//Priority non preemptive schedulling algorithm
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
    int n,i,j;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int burst_time[n];
    int priority[n];
    int process[n];

    printf("Enter Burst time and Priority of all the processes:\n");
    for(i=0;i<n;i++)
    {
        process[i]=i+1;
        scanf("%d %d",&burst_time[i],&priority[i]);
    }
    for(i=0;i<n;i++)
    {
        int a=priority[i],m=i;
        for(j=i;j<n;j++)
        {
            if(priority[j]<a)
            {
                a=priority[j];
                m=j;
            }
        }
        swap(&priority[i],&priority[m]);
        swap(&burst_time[i],&burst_time[m]);
        swap(&process[i],&process[m]);
    }
    int t=0;
    for(i=0;i<n;i++)
    {
        printf("%d---%d\n",process[i],t);
        t=t+burst_time[i];
    }
    int wait_time[n],turn_time[n];
    wait_time[0]=0;
    double avgwait=0.0,avgturn=0.0;
    for(i=1;i<n;i++)
    {
        wait_time[i]=burst_time[i-1]+wait_time[i-1];
        avgwait+=wait_time[i];
    }
    for(int i=0;i<n;i++)
    {
        turn_time[i]=burst_time[i]+wait_time[i];
        avgturn+=turn_time[i];
    }
    printf("\nAvg Waiting time:%f",avgwait/n);
    printf("\nAvg TurnAround Time:%f\n",avgturn/n);

    return 0;

}