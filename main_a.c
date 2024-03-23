#include <LPC21xx.H>
#include"head.h"
main()
{
  char p[10];
  char a[10];
  int page[]={0XA0,0XA2,0XA4,0XA6},c=0;
  int i=0,j=0;
  i2c_init();
  uart0_init(2400);
  uart0_tx_string("start\r\n");	
  uart0_rx_string(a,10); 
  for(i=0;a[i];i++)
   {
      i2c_bytes_write_frame(page[c],0x00+j,a[i]);
      delay_ms(5);
      if((i%255)==0)
       {
         j=0;
         c++;
       }
   j++;
  }
j=0;
c=0;
uart0_tx_string("half done\r\n");
  for(i=0;a[i];i++)
  {
	 p[i]=i2c_byte_read_frame(page[c],0x00+j);
	 if(i%255==0)
      {
        j=0;
        c++;
      }
	 j++;
 }
p[i]='\0';
uart0_tx_string(p);
uart0_tx_string("\r\ndone");
}
