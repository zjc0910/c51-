#include <REGX52.H>
#include <INTRINS.h>
sbit IO=P3^7;
unsigned char One_wire_Init()
{
	unsigned char i,n;
	IO=1;
	IO=0;
	_nop_();
	i = 247;
	while (--i);
	IO=1;
	i = 32;
	while (--i);
	n=IO;
	i = 247;
	while (--i);
return n;	
	
	
}

void One_wire_sendBit(unsigned char Bit)
{	
	unsigned char i;
	
	IO=0;
	_nop_();
	i = 4;
	while (--i);//delay 10us
	IO=Bit;
	
	_nop_();
	i = 24;
	while (--i);//delay 50us
	IO=1;
}

unsigned char One_Wire_receiveBit()
{
	unsigned char i;
	unsigned char Bit;
	IO=0;
	i = 2;
	while (--i);//Delay 5us
	IO=1;
	i = 2;
	while (--i);//Delay 5us
	Bit=IO;
	i = 24;
	while (--i);//Delay 45us
	return Bit;
}

void One_wire_sendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		One_wire_sendBit(Byte &(0x01<<i));
	}

}

unsigned char One_wire_reciveByte()
{
	unsigned char i,re=0x00;
	for(i=0;i<8;i++)
	{
		if(One_Wire_receiveBit()){re |=(0x01<<i);}
		
	}
	return re;
	
}













