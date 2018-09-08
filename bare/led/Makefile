led_on.bin : crt0.S led_on.c
	arm-linux-gcc -g -c -o crt0.o crt0.S
	arm-linux-gcc -g -c -o led_on.o led_on.c
	arm-linux-ld -Ttext 0x00000000 -g crt0.o led_on.o -o led_on_elf
	arm-linux-objcopy -O binary -S led_on_elf led_on.bin
	arm-linux-objdump -D -m arm led_on_elf > led_on.dis
clean:
	rm -f led_on.dis led_on.bin led_on_elf *.o 