OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")  /*指定输出可执行文件是elf格式,32位ARM指令,小端*/
OUTPUT_ARCH(arm)  /*指定输出可执行文件的平台为ARM*/
ENTRY(_start)     /*指定输出可执行文件的起始代码段为_start*/
SECTIONS
{
	/*指定可执行image文件的全局入口点，通常这个地址都放在ROM(flash)0x0位置。必须使编译器知道这个地址，通常都是修改此处来完成*/
	. = 0x00000000;
	
	. = ALIGN(4);	
	.text :
	{
		start.o (.text)  /*代码的第一个代码部分*/  
		*(.text)         /*下面依次为各个text段函数*/
	}
	
	. = ALIGN(4);        /*代码以4字节对齐*/
	.rodata : { *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.rodata*))) }   /*指定只读数据段*/
	
	. = ALIGN(4);
	.data : {
		*(.data*)        /*指定数据段*/
	}

	. = ALIGN(4);
	__bss_start = .;     /*把__bss_start赋值为当前位置,即bss段的开始位置*/
	.bss : { *(.bss) . = ALIGN(4); }  /*指定bss段,告诉加载器不要加载这个段*/
	__bss_end = .;       /*把_end赋值为当前位置,即bss段的结束位置*/
}