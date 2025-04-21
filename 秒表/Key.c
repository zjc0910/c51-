#include <REGX52.H>
#include "delay.h"
unsigned char Key_num,Temp;

unsigned char Key()
{
	Temp=Key_num;
	Key_num=0;
	return Temp;
}

unsigned char Key_getstate()
{
	unsigned char Keynum=0;
	if(P3_1==0){Keynum=1;}
	if(P3_0==0){Keynum=2;}
	if(P3_2==0){Keynum=3;}
	if(P3_3==0){Keynum=4;}
	
	return Keynum;
}

void Key_Loop()
{
	unsigned char Nowstate,Laststate;
	Nowstate=Laststate;
	
	Nowstate=Key_getstate();
	if(Laststate==1&&Nowstate==0)
	{
		Key_num=1;
	}
	if(Laststate==2&&Nowstate==0)
	{
		Key_num=2;
	}
	if(Laststate==3&&Nowstate==0)
	{
		Key_num=3;
	}
	if(Laststate==4&&Nowstate==0)
	{
		Key_num=4;
	}	
}