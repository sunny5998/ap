#include<stdio.h>
int main()
{
	int i,j,n,d,c,k=0,p=0,g,e,l,m,o=0;
	float h,f,hit=0,fault=0,sum;
	printf("Enter frames and pages:\n");
	scanf("%d%d",&d,&n);
	int a[n],b[d];
	printf("Enter the pages:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Page\t");
	for(i=0;i<d;i++)
	{
		printf("Frame%d\t",i+1);
	}
	printf("\n");
	for(i=0;i<d;i++)
	{
		printf("%d\t",a[i]);
		b[i]=a[i];
		fault++;		
		for(j=0;j<d;j++)
		{
			if(j<=i)
				printf("%d\t",b[j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	for(i=d;i<n;i++)
	{
		c=0;
		o=0;
		for(j=0;j<d;j++)
		{
			if(a[i]==b[j])
				c=1;	
		}
		if(c==1)
		{
			hit++;
		}
		else
		{
			//b[k]=a[i];
			//fault++;
			//k++;
			p=0;
			for(j=0;j<i;j++)
			{
				g=p;
				while(1)
				{
					if(a[g]==a[j])
						e++;
					g++;
					if(g==i)
						break;
				}
				for(l=0;l<d;l++)
				{
					if(a[j]==b[l])
						m++;
					
					if((e==1)&&(m==1))
					{
						b[l]=a[i];
						//printf("p\n");
						o++;
						fault++;
						break;
					}
				}
				//printf("%d%d\n",m,e);				
				p++;
				m=0;
				e=0;
				if(o>0)
					break;		
			}
		}
		printf("%d\t",a[i]);
		for(j=0;j<d;j++)
		{
			printf("%d\t",b[j]);
		}
		printf("\n");			
	}
	sum=hit+fault;
	h=(hit/sum);
	f=(fault/sum);
	printf("fault ratio is %.2f\nhit ratio is %.2f\n",f,h);
}
