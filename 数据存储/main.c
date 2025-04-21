#include <REGX52.H>
#include "lcd1602.h"
#include "key.h"
#include "at24c02.h"
#include "delay.h"



void main()
{
	unsigned char Keynum,num,re;
	LCD_Init();

	while (1)
	{
			Keynum=Key();
		if(Keynum==1)
		{
			num++;
			LCD_ShowNum(1,1,num,5);
		}
		if(Keynum==2)
		{
			num--;
			LCD_ShowNum(1,1,num,5);
		}
		if(Keynum==3)
		{
		AT24C02_write(0,num);
		LCD_ShowString(1,8,"write");
			Delay(5000);
		LCD_ShowString(1,8,"     ");
		}
		if(Keynum==4)
		{
		re=AT24C02_read(0);
		LCD_ShowString(1,8,"read");
			Delay(5000);
		LCD_ShowString(1,8,"    ");	
		LCD_ShowNum(2,1,re,5);
			
		}
	}
}