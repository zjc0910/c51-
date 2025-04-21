#include <REGX52.H>
#include "matrixkey.h"
#include "lcd1602.h"
#include "delay.h"

void main()
{
	unsigned char keynum;
	unsigned int password,count;
	LCD_Init();
	LCD_ShowString(1,1,"Password");
	
	while (1)
	{
		keynum=MatrixKey();
		if(keynum)
		{
			if(keynum<=10 && count<4)
			{
				password*=10;
				password+=keynum%10;
				count++;
				LCD_ShowNum(2,1,password,4);
			}
			if(keynum==11)//s11为确认按键
			{
				if(password !=4567)
				{
					LCD_ShowString(1,12,"Flase");
					password=0;
					count=0;
					LCD_ShowNum(2,1,password,4);
				}else
				{
					LCD_ShowString(1,12,"True");
					password=0;
					count=0;
					LCD_ShowNum(2,1,password,4);
				}
			}
			if(keynum==12)//s12为取消按键，
			{
					password=0;
					count=0;
					LCD_ShowNum(2,1,password,4);
			}
		}
		
		
	}
}