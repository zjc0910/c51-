#include <REGX52.H>
#include "delay.h"
sbit SCL=P2^1;
sbit SDA=P2^0;
	
unsigned char i;

/**
  * @brief   开始
  * @param  无
  * @retval 无
  */
void I2C_start()
{
	SCL=1;
	SDA=1;
	SDA=0;
	SCL=0;
	
}

/**
  * @brief   结束
  * @param  无
  * @retval 无
  */
void I2C_stop()
{
	SDA=0;
	SCL=1;
	SDA=1;
	
}


/**
  * @brief   发送数据
  * @param  Byte写入字节
  * @retval 无
  */
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
	SDA=Byte&(0x80>>i);
	SCL=1;
	SCL=0;
	}
}


/**
  * @brief   读出数据
  * @param  无
  * @retval Byte
  */
unsigned char I2C_reByte(void)
{
	unsigned char i,Byte=0x00;
	SDA=1;
	for(i=0;i<8;i++)
	{
		SCL=1;
	if(SDA){Byte|=0x80>>i;}
	SCL=0;
	}
	return Byte;
	
}


/**
  * @brief   发送应答
  * @param  1或0，1表示应答停止，0表示应答继续
  * @retval 无
  */
void Sa1_0(unsigned char n)
{
	SDA=n;
	SCL=1;
	SCL=0;
}


/**
  * @brief   接受应答
  * @param  无
  * @retval 1表示接受停止，0表示接受继续
  */
unsigned char Ra1_0(void)
{
	unsigned char n;
	SDA=1;
	SCL=1;
	if(SDA){n=SDA;}
	SCL=0;
	return n;
}
	

