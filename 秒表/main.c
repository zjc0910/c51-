#include <REGX52.H>
#include "key.h"
#include "nixie.h"
#include "timer0.h"

unsigned char Keynum,Temp1;

void main()
{
	Timer0Init();
	while (1)
	{
		Keynum=Key();
		if(Keynum){
		Temp1=Keynum;
			
		}
		research(1,Temp1);
	}
}

void Timer0_Routine() interrupt 1
{
	unsigned int count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;	
	count++;
	if(count>=20)
	{
		count=0;
		Key_Loop();

	}
}