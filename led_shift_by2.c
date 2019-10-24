#include<lpc214x.h>
void delay(int time);
int main()
{
unsigned int x,i,j;
PINSEL1=0X00000000;  //configure as GPIO
IODIR0=0X00FF0000;     //configure as o/p pins(23-16)
x=0x00008000;
for(i=0;i<4;i++)
{
x=x<<2;
IOSET0=x;
delay(500);
IOCLR0=x;
delay(500);

}	
for(j=0;j<4;j++)
{  
x=x>>2;
IOSET0=x;
delay(500);
IOCLR0=x;
delay(500);

} 
}	 



void delay(int time)
{
int i,j;
for (i=0;i<time;i++)
{
for(j=0;j<1000;j++);
}
}