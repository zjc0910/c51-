#include <REGX52.H>
#include "key.h"
#include "timer0.h"
#include "Nixie.h"
sbit moto=P1^0;
unsigned char count,compare;
unsigned char Keynum,NixieNum;
void main()
{
	Timer0Init();
	while (1)
	{
		Keynum=Key();
		if(Keynum)
		{
			if(Keynum==1)
			{
				NixieNum++;
			}
			if(Keynum==2)
			{
				NixieNum--;
			}
			if(Keynum==3)
			{
				NixieNum=0;
			}
			if(Keynum==4)
			{
				NixieNum=3;
			}
		}
		if(NixieNum==0){compare=0;}
		if(NixieNum==1){compare=50;}
		if(NixieNum==2){compare=75;}
		if(NixieNum==3){compare=100;}
		if(NixieNum>=4){NixieNum=0;}
		research(1,NixieNum);
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x9c;		//设置定时初值
	TH0 = 0xFF;	
	count++;
	if(count>=100){count=0;}
	if(count<compare){moto=1;}
	else{moto=0;}
	
}