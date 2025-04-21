#include <REGX52.H>

#include "delay.h"
#include "uart.h"

unsigned char Sec;

void main()
{
	Uart_Init();
	while (1)
	{
		
	}
}

void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;
		UART_SendByte(SBUF);
		RI=0;
	}
}