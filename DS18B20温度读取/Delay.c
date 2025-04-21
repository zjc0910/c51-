#include <INTRINS.h>
void Delay(unsigned char xms)		//@12.000MHz
{
	while (xms--)
	{
	_nop_();

	}
}
