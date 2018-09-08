/**
 *@brief  :led打开的C主函数
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

#define GPFCON (*(volatile unsigned long *)0x56000010)
#define GPFDAT (*(volatile unsigned long *)0x56000014)

int main()
{
	//GPF7-GPF4 2bits
	GPFCON &= ~((3<<10)|(3<<12)|(3<<14)|(3<<16));
	GPFCON |= (1<<10)|(1<<12)|(1<<14)|(1<<16);
	//1bit
	GPFDAT &= ~(0xF<<5);
	GPFDAT |= (1<<5)|(1<<7);

	return 0;
}
