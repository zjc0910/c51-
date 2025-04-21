#ifndef __ONE_WIRE_H__
#define __ONE_WIRE_H__
	unsigned char One_wire_Init();
	void One_wire_sendByte(unsigned char Bit);
	unsigned char One_Wire_receiveBit();
	void One_wire_sendByte(unsigned char Byte);
	unsigned char One_wire_reciveByte();
#endif