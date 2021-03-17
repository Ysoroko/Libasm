global	_main	; we are declaring a function "main"
section	.text	; indicates that the code starts here

_main:
	mov		rax,0x02000004	;system call for write
	mov		rdi,1			;moving 1 to rdi
	mov		rsi, message
	mov		rdx,14
	syscall
	mov		rax,0x02000001	;system call for exit
	xor		rdi,rdi
	syscall

section	.data	; 

message:	db	"Hello, World",10