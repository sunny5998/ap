#include<LPC214x.h>

#define GLCD_CS1_SET IOSET1=1<<27
#define GLCD_CS2_SET IOSET1=1<<28
#define GLCD_RST_SET IOSET1=1<<29
#define GLCD_CS1_CLR IOCLR1=1<<27
#define GLCD_CS2_CLR IOCLR1=1<<28
#define RS_CMD IOCLR1=1<<24
#define RS_DATA IOSET1=1<<24
#define WRITE IOCLR1=1<<25
#define enable_high IOSET1=1<<26
#define enable_low IOCLR1=1<<26

void GLCD_init(void);
void GLCD_CMD(unsigned char CMD);
GLCD_DATA(unsigned char DATA);
void GLCD_CLR(void);
void PAGE_COL_SEL(unsigned char page,unsigned char col);
void delay(int time);


int main()
{
	int k=0;
	int i,j;
	PINSEL0=0X00000000;
	PINSEL1=0X00000000;
	PINSEL2=0X00000000;
	IODIR0=0X000000FF;
	IODIR1=0X3F000000;
//	unsigned char x[]={};   
	GLCD_init();
	GLCD_CLR();
	
	for(i=0;i<128;i++)
	{
		for(j=2;j<=3;j++)
		{
			PAGE_COL_SEL(j,i);
		    GLCD_DATA(0XFF);
		    k++;
		}
	}
}


void GLCD_init(void)
{
	GLCD_CS1_SET;
	GLCD_CS2_SET;
	GLCD_RST_SET;
	GLCD_CMD(0X3F);
	delay(10);
	GLCD_CMD(0XB8);
	delay(10);
	GLCD_CMD(0X40);
	delay(10);
	
}

void GLCD_CMD(unsigned char CMD)
{
	RS_CMD;
	WRITE;
	IOCLR0=0XFF;
	IOSET0=CMD;
	
	enable_high;
	delay(10);
	enable_low;
	
}

void GLCD_CLR(void)
{
	int i,j;
	for(i=0;i<128;i++)
	{
		for(j=0;j<8;j++)
		{
			PAGE_COL_SEL(j,i);
			GLCD_DATA(0x00);
			
		}
	}
}

GLCD_DATA(unsigned char DATA)
{
	RS_DATA;
	WRITE;
	IOCLR0=0XFF;
    IOSET0=DATA;
    enable_high;
    delay(10);
    enable_low;
    
	
}

void PAGE_COL_SEL(unsigned char page,unsigned char col)
{
	if(col<64)
	{
		GLCD_CS1_SET;
		GLCD_CS2_CLR;
		page=page|0XB8;
		col=col|0X40;
		GLCD_CMD(page);
		GLCD_CMD(col);
    }
    else
    {
    	GLCD_CS1_CLR;
    	GLCD_CS2_SET;
		page=page|0XB8;
		col=(col-64)|0X40;
    	GLCD_CMD(page);
    	GLCD_CMD(col);
    	
	}
}

void delay(int time)
{
int i,j;
for (i=0;i<time;i++)
{
for(j=0;j<10;j++);
}
}
