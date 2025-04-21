#include <REGX52.H>
#include "lcd1602.h"
#include "timer0.h"
#include "delay.h"
#include "key.h"

unsigned char sec;//设置变量秒，分，小时
unsigned char minutes;
unsigned char hour;
unsigned char Keynum;
void main()
{
	LCD_Init();
	Timer0Init();
	LCD_ShowString(1,1,"clock");
	while (1)
	{
		Keynum=Key();
		if(Keynum)
		{
			if(Keynum==1)
			{
				hour++;
			}
			if(Keynum==2)minutes++;
			if(Keynum==3)sec++;
		}
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowChar(2,3,':');
		LCD_ShowNum(2,4,minutes,2);
		LCD_ShowChar(2,6,':');
		LCD_ShowNum(2,7,sec,2);
	}
}

void Timer0_Routine() interrupt 1
{
	unsigned int count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;	
	count++;
	if(count>=1000)
	{
		count=0;
		sec++;
		if(sec==60)
		{
			sec=0;
			minutes++;
			if(minutes==0)
			{
				minutes=0;
				hour++;
			}
		}
	}

	
}