#include <REGX52.H>
#include "timer0.h"
#include "key.h"
#include <INTRINS.h>


unsigned char Keynum,LEDMode;
void main()
{
	Timer0Init();
	P2=0xfe;

	while (1)
	{
		Keynum=Key();
		if(Keynum)
		{
			if(Keynum==1)
			{
				LEDMode++;
				if(LEDMode>=2)LEDMode=0;
			}
		}

	}
}	



void Timer0_Routine() interrupt 1
{
	static unsigned int count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;	
	count++;
	if(count>=500)
	{
		count=0;
		
		if(LEDMode==1)
		{
			P2=_crol_(P2,1);
		}
		if(LEDMode==0)
		{
			P2=_cror_(P2,1);
		}
	}
}