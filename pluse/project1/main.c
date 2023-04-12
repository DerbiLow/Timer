#include <8051.h> 
void msec (int x)  
{
	while(x-->0) 
{
	TH0 = (-10000)>>8;  
	TL0=-10000; 
	TR0=1;  
	TF0=0; 
	TR0=0;  
}
}
void main() 
{
	int i;
	unsigned char array[9];
	TMOD=0x1; 
	array[0]=0x0;  
	array[1] = 0x1; 
	array[2]=0x2;
	array[3] = 0x4;
	array[4]=0x8;
	array[5]=0x10;
	array[6]=0x20;
	array[7]=0x40;
	array[8]=0x80;

P1=array[0]; 
msec(60);
do
for(i=0;i<4;i++)
{
		if (i==0)
		{
			P1=array[1]+array[4]+array[7];
			msec(240);
		}
		else if (i==1)
		{
			P1=array[8];
			msec(150);
		}
		else if (i==2)
		{
			P1=array[2];
			msec(90);
		}
		if (i==3)
		{
			P1=array[3]+array[5]+array[6];
			msec(560);
		}
}
		
	while(1);

}