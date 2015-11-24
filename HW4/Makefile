



kernel:			kernel.o main.o boot_asm.o
			ld -m elf_i386 -static -Tboot.ld -nostdlib --nmagic *.o -o kernel

main.o:			main.c kernel.h 
			gcc -c -g -Os -ffreestanding -m32 main.c

kernel.o:		kernel.c kernel.h keyboard_map.h
			gcc -c -g -Os -ffreestanding -m32 -Wall -Werror  kernel.c


boot_asm.o:		boot.asm
			nasm -f elf32 -g -F stabs boot.asm 

