#include <REGX52.H>

void main()
{

	while (1)
	{
		P2_0=1;
		if(P3_1==0)
		{
			P2_0=~P2_0;
		}
		 else
		 {
		  	P2_0=P2_0;
		 }
	}
}