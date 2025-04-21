#include <REGX52.H>

#include "delay.h"
#include "uart.h"

unsigned char Sec;

void main()
{
	Uart_Init();
	while (1)
	{
		UART_SendByte(Sec); 
		Sec++;
		Delay(1000);
	}
}