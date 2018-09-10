/**
 *@brief  :进入到C程序的汇编代码
 *
 *@note   :
 *
 *@params :
 *
 *@return :
 *
 *@author : zhongfulin
 *@email  : 460342522@qq.com
 *@date   : 2018-9-8
 *
 */
#include "config.h"

.global _start
_start:
	ldr r0, =WTCON
	mov r1, #0x0
	str r1, [r0] @写入0，禁止WATCHDOG，否则CPU会不断重启

	ldr sp, =1024*4 @设置堆栈，注意：不能大于4KB，因为现在用的内存只有4KB
					@NAND FLASH中的代码会在复位后移动到内部ram（只有4KB）
	bl main
halt_loop:
	b halt_loop
	
	
