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
	unsigned char LEDN=8;
	P2=0xfe;//1111 1110
	
	while(1)
	{
		unsigned char LEDNUM;
		if(P3_1==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			LEDNUM++;
			if(LEDNUM>8)
				LEDNUM=0;
			P2=~(0x01<<LEDNUM);	
		
		}
		else if(P3_0==0)
		{
			Delay1ms(20);
			while(P3_0==0);
			Delay1ms(20);
			if(LEDNUM==0)
				LEDNUM=7;
			else 
				LEDNUM--;
			P2=~(0x01<<LEDNUM);				
		}
	
	
	
	
	}


}

