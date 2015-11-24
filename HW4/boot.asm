bits 32
section .text
;; sets up the multiboot for GRUB
	align 4
        dd 0x1BADB002	
	dd 0x00		
	dd - (0x1BADB002 + 0x00)

global start
	
global keyboard_handler
global in_port
global out_port
global load_interupt_loc

extern main 	
extern keyboard_main

;; io ports access in assembler
in_port:
	mov edx, [esp + 4]
	in al, dx	
	ret

out_port:
	mov   edx, [esp + 4]
	mov   al, [esp + 4 + 4]
	out   dx, al
	ret
;; copies interrupts address
load_interupt_loc:
	mov edx, [esp + 4]
	lidt [edx]
	sti		
	ret

;; calls the keyboard main function
keyboard_handler:
	call    keyboard_main
	iretd

;; starts main
start:
	cli		
	mov esp, stack_space
	call main
	hlt		

section .bss
resb 8192
stack_space:	
