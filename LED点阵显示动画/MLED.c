#include <REGX52.H>
#include "Delay.h"
sbit RCK=P3^5;//RCLK上沿锁存
sbit SCK=P3^6;//SRCLK上沿移位
sbit SER=P3^4;

/**
  * @brief   74HC595写入一个字节
  * @param  输入一个字节
  * @retval 无
  */
void _74HC595_writeByte(unsigned char Byte)
{
	unsigned char i;
	for( i=0;i<8;i++)
	{
		SER=Byte &(0x80>>i);//非零记一
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
	

}
/**
  * @brief   LED显示图形
* @param  Column第几行，最高位为最左边，范围0~7
* @param  Data列显示的数据，最高位为上方，范围为0~7
  * @retval 无
  */
void MLED_Show(unsigned char Column,Data)
{
	_74HC595_writeByte(Data);
	P0=~0x80>>Column;
	Delay(1);
	P0=0xff;
	
}

/**
  * @brief   点阵初始化
  * @param  无
  * @retval 无
  */
void LED_Init()
{
	SCK=0;
	RCK=0;
}