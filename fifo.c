
//when u find the page then hit
//when there is no page avaialble in main memory then page fault
//find the page fault ratio and page hit ratio
//consider the 3 memory blocks
#include<stdio.h>
int search(int a, int * p, int l)
{
	int temp=0;
	while(temp<l)
	{
		if(a==*(p+temp))
		{
			return temp;
		}
	temp+=1;
	}
	
	return -1;
}

int main()
{
	int n;
	int temp=0;
	int temp1;
	int frame;
	float hit=0;
	float fault=0;

	//page init  and scan
	printf("Enter the number of pages ");
	scanf("%d",&n);
	int a[n];
	
	//frame init and scan
	printf("\nEnter the number of frames ");
	scanf("%d",&frame);
	int f[frame];
	for(int i=0;i<frame;i++)
	{
		f[i]=-1;		
	}
	
	//input pages
	printf("\nEnter the page values ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);		
	}
	
	//prints the frames
	printf("Page\t\t");
	for(int i=0;i<frame;i++)
	{
		printf("frame%d\t\t",i);
	}
	printf("HIT/FAULT\n");

	for (int i=0;i<n;i++)
	{
		
		//if the number is not present in the f array
		if(search(a[i],f,frame)==-1)
		{
			//get the last index of f
			temp1=temp%frame;		
			temp++;
			
			//update that f in the array
			f[temp1]=a[i];
			//update the page fault
			fault++;
			
			//print the updated frames
			printf("%d\t\t",a[i]);
			for(int i=0;i<frame;i++)
			{
				printf("%d\t\t",f[i]);
			}
			printf("FAULT\n");
		}
		else
		{
			// do nothing just increment the hit
			hit++;
			
			//print the updated frames
			printf("%d\t\t",a[i]);
			for(int i=0;i<frame;i++)
			{
				printf("%d\t\t",f[i]);
			}
			
			printf("HIT\n");
		}
	}
	printf("\nHit Ratio =%f\n",hit/n);
	printf("Page Fault Ratio = %f\n",fault/n);
	return 0;
}
