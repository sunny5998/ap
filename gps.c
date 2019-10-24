#include<lpc214x.h>
void LCD_init(void);
void LCD_cmd(unsigned char cmd);
void LCD_write_string(unsigned char *str);
void delay(int time);
void LCD_data(unsigned char data);
unsigned char UART1_RxByte();
void UART1_init();

unsigned char val,x,flag;

int main()
{
unsigned int i;
unsigned char string[5]="GPGGA";
unsigned char cmd_data[13],time_stamp[13],lattitude[13],longitude[13];

PINSEL0=0X00050000;
IODIR0=0XFF<<16;
IODIR1=0X07<<16;
LCD_init();
UART1_init();
LCD_write_string("GPS DATA:");
delay(10);
while(1)
{
if(UART1_RxByte()=='$')
{
for(i=0;i<5;i++)
{
flag=0;
cmd_data[i]=UART1_RxByte();
if(cmd_data[i]!=string[i])
{
flag=1;
break;
}
}
if(flag==0)
{
for(i=0;i<12;i++)
{
time_stamp[i]=UART1_RxByte();
}
time_stamp[12]='\0';
for(i=0;i<12;i++)
{
lattitude[i]=UART1_RxByte();
}
lattitude[12]='\0';
for(i=0;i<12;i++)
{
longitude[i]=UART1_RxByte();
}
longitude[12]='\0';
LCD_cmd(0x01);



LCD_write_string("TIME STAMP");
LCD_cmd(0x0C0);
LCD_write_string(time_stamp);
LCD_cmd(0x01);
LCD_cmd(0x80);
LCD_write_string("LATTITUDE");
LCD_cmd(0x0C0);
LCD_write_string(lattitude);
LCD_cmd(0x01);
LCD_cmd(0x80);
LCD_write_string("LONGITUDE");
LCD_cmd(0x0C0);
LCD_write_string(longitude);
}
}
}
}

void LCD_init(void)
{
	LCD_cmd(0x38);
	delay(100);
	LCD_cmd(0x01);
	delay(100);
	LCD_cmd(0x0E);
	delay(100);
	LCD_cmd(0x06);
	delay(100);
	
	
}
void LCD_cmd(unsigned char cmd)
{
	IOCLR0=0XFF<<16;
	IOCLR1=0X03<<16;
	IOSET0=cmd<<16;
	IOSET1=1<<18;
	delay(100);
	IOCLR1=1<<18;
}
void LCD_data(unsigned char data)
{
	IOCLR0=0XFF<<16;
	IOSET1=0X01<<16;
	IOCLR1=0X01<<17;
	IOSET0=data<<16;
	IOSET1=1<<18;
	delay(100);
	IOCLR1=1<<18;
	LCD_cmd(0X18);
}
void LCD_write_string(unsigned char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		LCD_data(str[i]);
		delay(100);
	
		i++;
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

void UART1_init()
{
U0LCR=0X9F;
U0DLL=0X61;
U0DLM=0X00;
U0LCR=0X1F;
}
unsigned char UART1_RxByte(void)
{
while(!( U0LSR & 0X01));
val=U0RBR;
return(val);
}












