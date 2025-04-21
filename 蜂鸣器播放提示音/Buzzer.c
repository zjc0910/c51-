#include <REGX52.H>
#include <INTRINS.h>

sbit Buzzer=P2^5;
unsigned int i;
void Buzzer_Time(unsigned int time)
{
				for(i=0;i<time;i++)
				{
					Buzzer=!Buzzer;
					_nop_();
				}
}
