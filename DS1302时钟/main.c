#include <REGX52.H>
#include "lcd1602.h"
#include "ds1302.h"
#include "delay.h"
unsigned char Year,Month,Day,Hour,Min,Sec;
void main()
{
	LCD_Init();
	DS1302_Init();
	DS1302_WRITE(0x80,0x03);
	while (1)
	{
		Sec=DS1302_READ(0x81);
		LCD_ShowNum(2,1,Sec,3);
		Delay(20);
	}
}