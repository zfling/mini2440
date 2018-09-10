#include "led.h"

void led_init(void)
{
	//设置LED对应的GPIO引脚为输出功能
	LEDCON &= ~((0x3<<(2*BITLED1))|(0x3<<(2*BITLED2))|(0x3<<(2*BITLED3))|(0x3<<(2*BITLED4)));
	LEDCON |= (0x1<<(2*BITLED1))|(0x1<<(2*BITLED2))|(0x1<<(2*BITLED3))|(0x1<<(2*BITLED4));

	return;
}

static void led_set_data(enBitLED bitLed, enLedStatus status) 
{
	if (status >= LED_ERROR) {
		//输入状态有问题，只有ONheOFF两种状态
		return;
	}
	if ( bitLed >= BIT_ERROR)
	{
		//bit位有问题
	    return;
	}

	LEDDAT &= ~(0x1<<bitLed); //清除对应为，设置为0
	if ( LED_OFF == status )
	{
	    LEDDAT |= 0x1<<bitLed;
	}
	
	return;
}

void led1_status(enLedStatus status)
{
	
	led_set_data(BITLED1, status);
	return;
}

void led2_status(enLedStatus status)
{
	led_set_data(BITLED2, status);
	return;
}

void led3_status(enLedStatus status)
{
	led_set_data(BITLED3, status);
	return;
}

void led4_status(enLedStatus status)
{
	led_set_data(BITLED4, status);
	return;
}

void led_status(enLedStatus status)
{
	led_set_data(BITLED4, status);
	led_set_data(BITLED3, status);
	led_set_data(BITLED2, status);
	led_set_data(BITLED1, status);
	return;
}

