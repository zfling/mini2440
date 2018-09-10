/*****************************************************************************
*                                                                            *
*  Copyright (C) 2018 zfling  460342522@qq.com.                              *
*                                                                            *
*  @file   : led.h
*  @brief  : led相关操作
*                                                                            *
*  @author : zhongfulin
*  @email  : 460342522@qq.com
*  @version: 1.0.0
*  @date   : 2018-9-9
*  Details : 
*                                                                            *
*****************************************************************************/
#ifndef __LED_H_
#define __LED_H_

#include "config.h"

enum enLedStatus {
	LED_ON = 0,
	LED_OFF,
	LED_ERROR
};

#define LEDCON (*(volatile unsigned long *)GPFCON)
#define LEDDAT (*(volatile unsigned long *)GPFDAT)

enum enBitLED {
	BITLED1 = 5,
	BITLED2,
	BITLED3,
	BITLED4,
	BIT_ERROR
};

void led_init(void);
void led1_status(enLedStatus);
void led2_status(enLedStatus);
void led3_status(enLedStatus);
void led4_status(enLedStatus);
void led_status(enLedStatus);

#endif


