#include <REGX52.H>

void Uart_Init(void)		//4800bps@12.000MHz
{
	SCON = 0x50;
  PCON |=0x80;	//8位数据,可变波特率
	TMOD &= 0x0F;
	TMOD |=0x20;	//设定定时器1为16位自动重装方式
	TL1 = 0xF3;		//设定定时初值
	TH1 = 0xF3;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;	//启动定时器1
	EA=1;
	ES=1;
}


void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while (TI==0);
	TI=0;
}

//void UART_Routine() interrupt 4
//{
//	if(RI==1)
//	{
//		
//		
//		RI=0;
//	}
//}