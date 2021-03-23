;ssize_t write(int fd, const void *str, size_t n);
;rdi	=	1st argument registry (fd)
;rsi	=	2nd argument registry (str)
;rdx	=	3rd argument (size)
extern	___error
SYS_WRITE equ 0x2000004

global	_ft_write

_ft_write:
	mov		rax, SYS_WRITE			;rax = 0x2000004, for syscall
	syscall							;calls write function using syscall (rax is now the error number)
	jc		_return_error			;checks the carry flag, if it's active, there has been an error (and it's stocked in rax on macOS)
	ret								;returns rax if no error(return value of write syscall)

_return_error:
	push	rax
	call	___error
	pop		qword[rax]
	mov		rax, -1					;rax = -1
	ret			
