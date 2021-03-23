;ssize_t write(int fd, const void *str, size_t n);
;rdi	=	1st argument registry (fd)
;rsi	=	2nd argument registry (str)
;rdx	=	3rd argument (size)
extern	___error
SYS_WRITE equ 0x2000004 	;#define SYS_WRITE 0x2000004

global	_ft_write

_ft_write:
	mov		rax, SYS_WRITE			;rax = 0x2000004, for syscall
	syscall							;calls write function using syscall
	;jc		_return_error
	ret								;returns rax(return value of write syscall)


_return_minus_one:
	xor		rax,rax
	dec		rax
	ret

_return_error:
	mov		r8, rax
	mov		[rax], r8
	call	___error
	mov		rax, -1
	ret
