 #include <LPC214X.h>

 void UART0_INIT();
 unsigned char rxbyte(void);
 void txbyte(unsigned char val);
 
 void TxString( unsigned char *str);

 unsigned char val,X;
 unsigned char string[];

 int main()
 { 
  int i;
  PINSEL0=0X00000005;
  UART0_INIT();
   

 for(i=0;i<10;i++)
 {
  string[i] =rxbyte();
 }

 string[10]='\0';

 TxString(string);
 }

 void UART0_INIT()
 {
  U0LCR=0X9F;
  U0DLL=0X61;
  U0DLM=0X00;
  U0LCR=0X1F;
 }

 unsigned char rxbyte(void)
 {
  while(!(U0LSR&0X01));
  val=U0RBR;
  return(val);
 }

 void txbyte(unsigned char var)
 {
  while(!(U0LSR&0X40));
  U0THR=var;
 }


 void TxString( unsigned char *str)
 {

 int i=0;

 while(str[i] != '\0')
 {
  txbyte(str[i]);
  i++;
 }

 }