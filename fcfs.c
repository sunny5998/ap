

#include<stdio.h>
int main()
{
	int at[20],et[20],st[20],ft[20],tt[20],wt[20];
	int i,n;
	float sum;
	printf("Enter the no of process");
	scanf("%d",&n);
	
	printf("\nEnter the arrival time");
 	for(i=0;i<n;i++)
	{
		printf("Process %d",i);
		scanf("%d",&at[i]);
	}

	printf("\nEnter the excecuting time");
 	for(i=0;i<n;i++)
	{
		printf("Process %d",i);
		scanf("%d",&et[i]);
	}

	//The start time
	for(i=0;i<n;i++)
	{
		st[0]=at[0];
		st[i+1]=st[i]+et[i];
	}	

	//finish time
	for(i=0;i<n;i++)
	{
		ft[i]=st[i]+et[i];
	}

        //turnaround time
	for(i=0;i<n;i++)
	{
		tt[i]=ft[i]-at[i];
	}

	//waiting time
	for(i=0;i<n;i++)
	{
		wt[i]=tt[i]-et[i];
	}

	printf("\nThe table for FCFS is:");
	printf("\n\tArrival time Execution time Start time Finish time Turnaroundtime Waitingtime");

	for(i=0;i<n;i++)
	{
		printf("\nProcess %d",i);
		printf("\t%d\t%d\t\t%d\t\t%d\t%d\t%d",at[i],et[i],st[i],ft[i],tt[i],wt[i]);
	}

	for(i=0;i<n;i++)
	{
		sum=sum+wt[i];
	}
	printf("\navg waiting time is:%f",sum/n);

	sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+tt[i];
	}
	printf("\navg turnaround time is:%f",sum/n);
}




