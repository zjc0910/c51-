#ifndef __I2C_H__
#define __I2C_H__
void I2C_start();
void I2C_stop();
void I2C_SendByte(unsigned char Byte);
unsigned char I2C_reByte(void);
void Sa1_0(unsigned char n);
unsigned char Ra1_0(void);
#endif