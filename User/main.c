#include "ADC.h"
#include "Public.h"
#include "Uart.h"
//#include "GUI.h"
#include "ST7789V.h"
#include "Time.h"

void IoInit();

void main()
{
	
	IoInit();//IO初始化
	UartStructInit(&uart1,1,baud115200);//串口1初始化
	//TimeInit();
	UartStructInit(&uart4,4,57600);//串口2初始化
	TimeInit();//定时器初始化
	Lcd_Power.BACK(0);
	Lcd_Power.POWER(0);
	while(1)
	{ 
		if(uart1._readFlag)
		{
			uart1._readFlag = 0;
			timesindex = uart1._uartRead[0];
			uart1.UartWriteChar(&uart1,timesindex);
			//uart1.UartWriteBuffe(&uart4,&uart1);
			uart1._uartSign = 0;
		}
		 if(uart4._readFlag)
		{
			uart4._readFlag = 0;
			//uart1.UartWriteBuffe(&uart1,&uart4);
			uart4._uartSign = 0;
		} 
	}
}

void IoInit()
{
	P0M0 = 0x00;
	P0M1 = 0x00;
	P2M0 = 0x00;
	P2M1 = 0x00;
	P3M0 = 0x00;
	P3M1 = 0x00;
	P1M0 = 0x00;
	P1M1 = 0x00;
	P5M0 = 0x00;
	P5M1 = 0x00;
}