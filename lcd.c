#include<lpc214x.h>
void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void lcd_write_string(unsigned char *str);
void delay(int time);
void lcd_data(unsigned char data);
int main()
{
	unsigned char var1[]="WELCOME";
	unsigned char var2[]="TO PICT";

	PINSEL1=0X00000000;			//configure p0.16-p0.31 as io pins
	PINSEL2=0X00000000;			//configure p1.16-p1.31 as io pins
	IODIR0=0X00FF0000;
	IODIR1=0X00070000;

	lcd_init();	
	lcd_cmd(0x80);
	delay(100);				//initialise lcd
	lcd_write_string(var1);     //send "welcome" to lcd screen
	lcd_cmd(0x0C0);
	lcd_write_string(var2);		//send "to pict" to lcd

	//lcd_cmd(0x1C);
	//delay(600);

	return 0;
}
void lcd_init(void)
{
	lcd_cmd(0x38);
	delay(100);
	lcd_cmd(0x01);
	delay(100);
	lcd_cmd(0x0E);
	delay(100);
	lcd_cmd(0x06);
	delay(100);
	
	
}
void lcd_cmd(unsigned char cmd)
{
	IOCLR0=0XFF<<16;
	IOCLR1=0X03<<16;
	IOSET0=cmd<<16;
	IOSET1=1<<18;
	delay(100);
	IOCLR1=1<<18;
}
void lcd_data(unsigned char data)
{
	IOCLR0=0XFF<<16;
	IOSET1=0X01<<16;
	IOCLR1=0X01<<17;
	IOSET0=data<<16;
	IOSET1=1<<18;
	delay(100);
	IOCLR1=1<<18;
	lcd_cmd(0X18);
}
void lcd_write_string(unsigned char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		lcd_data(str[i]);
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
