#include <reg51.h> 


/*注意信号线接1-0，1-1，1-2，1-3*/
sbit int1=P1^4;	 
sbit int2=P1^5;
sbit int3=P1^6;
sbit int4=P1^7;

char i;

void stop()//停止
{
	int1=0;	   
	int2=0;
	int3=0;
	int4=0; 
}
void back()//后退
{
	int1=1;	   
	int2=0;
	int3=1;
	int4=0;
}

void forward()//前进
{
	int1=0;	   
	int2=1;
	int3=0;
	int4=1;    
}

void right() //右转  
{
	int1=0;	   
	int2=1;
	int3=1;
	int4=0;
}

void left()//左转
{
	int1=1;	   
	int2=0;
	int3=0;
	int4=1;
}

void main()
{
TMOD = 0x20;
TH1 = 0x02;
TL1 = 0x2A;
SCON = 0x50;
PCON = 0x00;
TR1 = 1;
ES = 1;
EA = 1;                            //开串口中断
 	while(1)
 	{
		 i=SBUF;//SBUF为单片机接收到的数据，单片机接收到的数据都存放在SBUF里；
         RI=0;
         switch(i)
         {
		    case '1':       
			    forward();
		        break;
		    case '2':       
			    back();
			    break;
		    case '3':       
		        left();
			    break;
			case '4':       
		        right();
			    break;
		    case '5':       
		    	stop();
		    	break;
		}
	}
}
