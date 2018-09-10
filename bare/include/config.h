/*****************************************************************************
*                                                                            *
*  Copyright (C) 2018 zfling  460342522@qq.com.                              *
*                                                                            *
*  @file   : config.h
*  @brief  : 特殊功能寄存器地址
*                                                                            *
*  @author : zhongfulin
*  @email  : 460342522@qq.com
*  @version: 1.0.0
*  @date   : 2018-9-9
*  Details : 
*                                                                            *
*****************************************************************************/

#ifndef __CONFIG_FOR_SFR_
#define __CONFIG_FOR_SFR_

/** WATCHDOG. */
#define WTCON	0x53000000
#define WTDAT	0x53000004
#define WTCNT	0x53000008
/** GPIOB. */
#define GPFCON	0x56000010
#define GPFDAT	0x56000014

#endif