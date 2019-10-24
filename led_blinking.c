#include<lpc214x.h>
void delay(int time);
int main()
{
PINSEL1=0X00000000;
IODIR0=0X00FF00;
while(1)
{
IOSET0=0X00FF0000;
delay(1000);
IOCLR0=0X00FF0000;
delay(1000);

}
return 0;
}
void delay(int time)
{
int i,j;
for (i=0;i<time;i++)
{
for(j=0;j<1000;j++);
}
}