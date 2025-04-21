#include <REGX52.H>
#include "i2c.h"
/**
  * @brief   将数据写入到at24c02
  * @param  ADDRESS 数据存放的地址
	* @param  Data 写入的数据
  * @retval 无
  */
void 	AT24C02_write(unsigned char ADDRESS,unsigned char Data)
{
	I2C_start();
	I2C_SendByte(0xa0);
	Ra1_0();
	I2C_SendByte(ADDRESS);
	Ra1_0();
	I2C_SendByte(Data);
	Ra1_0();
	I2C_stop();
}
	


/**
  * @brief   读出at24c02中的数据
  * @param  数据地址
  * @retval 数据DATA
  */
unsigned char AT24C02_read(unsigned char ADDRESS)
{
	unsigned char Data;
	I2C_start();
	I2C_SendByte(0xa0);
	Ra1_0();
	I2C_SendByte(ADDRESS);
	Ra1_0();
	I2C_start();
	I2C_SendByte(0xa1);
	Ra1_0();
	Data=I2C_reByte();
	Sa1_0(1);
	I2C_stop();
	return Data;
	
	
}
