#include <REGX52.H>
#include "one_wire.h"

void DS18B20_ConvertT()
{
	One_wire_Init();
	One_wire_sendByte(0xcc);
	One_wire_sendByte(0x44);
}


float DS18B20_ReadT()
{
	unsigned char TLSB,TMSB;
	int Temp;
	float T;
	One_wire_Init();
	One_wire_sendByte(0xcc);
	One_wire_sendByte(0xbe);
	TLSB=One_wire_reciveByte();
	TMSB=One_wire_reciveByte();
	Temp=(TMSB<<8)|TLSB;
	T=Temp/16.0;
	
	return T;
}