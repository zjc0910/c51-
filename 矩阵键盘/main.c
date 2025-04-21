#include <REGX52.H>
#include "delay.h"
#include "lcd1602.h"
#include "matrixkey"
void main()
{	
	unsigned keynum;
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey");
	LCD_ShowNum(2,1,0,2);
	while (1)
	{
		keynum=MatrixKey();
		if(keynum){
			LCD_ShowNum(2,1,keynum,2);
		}
	
	}

}
