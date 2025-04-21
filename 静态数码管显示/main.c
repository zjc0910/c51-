#include <REGX52.H>
void LED1()
{
	P2_2=P2_3=P2_4=0;
}
void LED2()
{
	P2_2=1;
	P2_3=P2_4=0;
}
void LED3()
{
	P2_2=P2_4=0;
	P2_3=1;
}
void LED4()
{
	P2_2=P2_3=1;
	P2_4=0;
}
void LED5()
{
	P2_2=P2_3=0;
	P2_4=1;
}
void LED6 ()
{
	P2_2=P2_4=1;
	P2_3=0;
}
void LED7()
{
	P2_3=P2_4=1;
	P2_2=0;
}
void LED8()
{
	P2_2=P2_3=P2_4=1;
}
void display0()
{
	P0_6=P0_7=0;
	P0_0=P0_1=P0_2=P0_3=P0_4=P0_5=1;
}
void display1()
{
	P0_1=P0_2=1;
	P0_0=P0_3=P0_4=P0_5=P0_6=P0_7=0;

}
void display2()
{
	P0=0x5b;
}
void display3()
{
	P0=0x4f;
}
void display4()
{
	P0=0x66;
}
void display5()
{
	P0=0x6d;
}
void display6()
{
	P0=0x7d;
}
void display7()
{
	P0=0x07;
}
void display8()
{
	P0=0x7f;
}
void display9()
{
	P0=0x6f;
}
void main()
{
	while(1)
	{
	 	LED1();
		display7();
	}

}


