; nasm print array;

section .data
	arr dd 1,2,3,4,5
	len equ $ - arr

section .text

	global _main:

_main:
    mov	rdx, len
    mov rcx, arr
    add rcx, 48
    mov rbx, 1
    mov rax, 0x2000004
    syscall
    mov rax, 0x2000001
    syscall

