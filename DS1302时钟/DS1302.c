#include <REGX52.H>
sbit DS1302_SCLK=P3^2;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;
void DS1302_WRITE(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}
void DS1302_Init()
{
	DS1302_CE=0;
	DS1302_SCLK=0;
}

//void DS1302_WRITE(unsigned char Command,Data)
//{
//	unsigned char i;
//	DS1302_CE=1;
//	for(i=0;i<8;i++)
//	{
//	DS1302_IO=Command &(0x01<<i);
//	DS1302_SCLK=1;
//	DS1302_SCLK=0;		
//	}
//	for(i=0;i<8;i++)
//	{
//	DS1302_IO=Data &(0x01<<i);
//	DS1302_SCLK=1;
//	DS1302_SCLK=0;		
//	}
//	DS1302_CE=0;
//	
//}

//unsigned char DS1302_READ(unsigned char Command)
//{
//	unsigned char i;
//	unsigned char re=0x00;
//	DS1302_CE=1;
//	for(i=0;i<8;i++)
//	{
//		DS1302_IO=Command &(0x01<<i);
//		DS1302_SCLK=0;
//		DS1302_SCLK=1;

//	}

//	for(i=0;i<8;i++)
//	{
//		DS1302_SCLK=1;
//		DS1302_SCLK=0;
//		if(DS1302_IO)
//		{
//			re |=(0x01<<i);
//		}
//		DS1302_CE=0;
//		DS1302_IO=0;
//		return re;
//	}
//	
//	
//	
//}
unsigned char DS1302_READ(unsigned char Command)
{
	unsigned char i,Data=0x00;
	Command|=0x01;	//将指令转换为读指令
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	}
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}
	}
	DS1302_CE=0;
	DS1302_IO=0;	//读取后将IO设置为0，否则读出的数据会出错
	return Data;
}






