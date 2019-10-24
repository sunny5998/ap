#include<stdio.h>
#include<unistd.h>
void main()
{
pid_t a;
a=fork();
if (a==0)
{
printf("value return by function fork for child process is %d\n",a);
printf("pid of child process is %d\n",getpid());
}
else
{
printf("value return by function fork for child process is %d\n",a);
printf("pid of parent process is %d\n",getpid());
}
while(1);
}
