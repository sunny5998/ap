#include <lpc214x.h>
unsigned char val,x;
unsigned char rxbyte(void);
void txbyte(unsigned char var);
void UART_INIT();
int main()
{
PINSEL0=0X00000005;
UART_INIT();
while(1)
{
x=rxbyte();
txbyte(x);
}
}
void UART_INIT()
{
U0LCR=0X9F;
U0DLL=0X61;
U0DLM=0X00;
U0LCR=0X1F;
}
unsigned char rxbyte(void)
{
while(!( U0LSR & 0X01));
val=U0RBR;
return(val);
}

void txbyte(unsigned char var)
{
while(!( U0LSR & 0X40 ));
U0THR=var;
}
