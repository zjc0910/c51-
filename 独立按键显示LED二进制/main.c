#include <REGX52.H>
void Delay1ms(unsigned int xms)		//@12.000MHz
{
	while(xms--)
	{
		unsigned char i, j;

		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	unsigned char LEDNUM=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			LEDNUM++;
			P2=~LEDNUM;

		}
	
	
	}

}

