#include <REGX52.H>
#include "Delay.h"

unsigned char num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,} ;
void research(unsigned char LEDNUM,unsigned char NUM)
{
  switch(LEDNUM)
  {
  	case 1:
		P2_2=P2_3=P2_4=0;
		break;
	case 2:
		P2_3=P2_4=0;
		P2_2=1;
		break;
	case 3:
		P2_2=P2_4=1;
		P2_3=0;
		break;
	case 4:
		P2_2=P2_3=1;
		P2_4=0;
		break;
	case 5:
		P2_4=1;
		P2_2=P2_3=0;
		break;
	case 6:
		P2_4=P2_2=1;
		P2_3=0;
		break;
	case 7:
		P2_4=P2_3=1;
		P2_2=0;
		break;
	case 8:
		P2_2=P2_3=P2_4=1;
		break;
  
  }
   P0=num[NUM];
   Delay(1);
   P0=0x00; 
}