#include <REGX52.H>
#include "key.h"
#include "delay.h"
#include "nixie.h"

sbit Buzzer=P1^5;
unsigned char keynum;
unsigned int i;
void main()
{
	research(1,0);
	while (1)
	{
			keynum=Key();
			if(keynum)
			{
				for(i=0;i<500;i++)
				{
					Buzzer=!Buzzer;
					Delay(1);
				}
				research(1,keynum);
			}
	}
}