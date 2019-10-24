#include<lpc214x.h>
void init_timer0(void)
{
T0CTCR=0X00;
T0PR=15000-1;
T0TCR=0X02;
}
void timer_delay(unsigned int time)
{
T0TCR=0X02;
T0TCR=0X01;
while(T0TC<time);
T0TCR=0X02;
T0TCR=0X00;
}
int main()
{
PINSEL2=0X00000000;
init_timer0();
IODIR1=0XFF<<16;
IOCLR1=0X00FF0000;
while(1)
{
IOSET1=0X00FF0000;
timer_delay(1000);
IOCLR1=0x00FF0000;
timer_delay(1000);
}
}
