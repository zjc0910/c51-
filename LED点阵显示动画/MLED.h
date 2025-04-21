#ifndef __MLED_H__
#define __MLED_H__
void _74HC595_writeByte(unsigned char Byte);
void MLED_Show(unsigned char Column,Data);
void LED_Init();
#endif