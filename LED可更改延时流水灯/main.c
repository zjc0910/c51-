#include <REGX52.H>
void Delay1ms(unsigned  int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
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
	while (1)
	{
		P2=0xfe;
		Delay1ms(500);
		P2=0xfd;   //1111 1101
		Delay1ms(500);
		P2=0xfb; //1111 1011
		Delay1ms(500);
		P2=0xf7;   //1111 0111
		Delay1ms(500);
		P2=0xef;  //1110 1111
		Delay1ms(500);
		P2=0xdf;  //1101 1111
		Delay1ms(500);
		P2=0xbf;  //1011 1111
		Delay1ms(500);
		P2=0x7f;   //0111 1111
		Delay1ms(500);
	
	}
}


