//Round Robin schedulling
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i;
    printf("Enter number of processes:");
    scanf("%d",&n);
    printf("Enter arrival time and burst time of all the processes:\n");
    int arrival_time[n],burst_time[n],temp[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&arrival_time[i],&burst_time[i]);
        temp[i]=burst_time[i];
    }

    int quant=0;
    int wt[n],tat[n];

    printf("Enter time quantum:");
    scanf("%d",&quant);

   int sum=0,y=n,count=0;
   for(sum=0,i=0;y!=0;)
   {
       if(temp[i]<=quant&&temp[i]>0)
       {
        sum+=temp[i];
        temp[i]=0;
        count=1;
       }
       else if(temp[i]>0)
       {
        temp[i]-=quant;
        sum+=quant;
       }
       if(temp[i]==0&&count==1)
       {
        y--;
        wt[i]=sum-arrival_time[i]-burst_time[i];
        tat[i]=sum-arrival_time[i];
        printf("P%d---%d---%d\n",i+1,wt[i],tat[i]);
        count=0;
       }
       if(i==n-1)
       i=0;
       else if(arrival_time[i+1]<=sum)
       i++;
       else
       i=0;
   }

  //float avg_wt=0.0,avg_tat=0.0;
    float avgwait=0.0,avgturn=0.0;
    for(i=0;i<n;i++)
    {
        avgwait+=wt[i];
    }
    for(int i=0;i<n;i++)
    {
        avgturn+=tat[i];
    }
     printf("\nAvg Waiting time:%f",avgwait/n);
    printf("\nAvg TurnAround Time:%f\n",avgturn/n);
    return 0;

    
}