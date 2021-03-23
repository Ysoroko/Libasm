;ssize_t write(int fd, const void *str, size_t n);
;rdi	=	1st argument registry (fd)
;rsi	=	2nd argument registry (str)
;rdx	=	3rd argument (size)
extern	___error
SYS_READ equ 0x2000003

global	_ft_read

_ft_read:
	mov		rax, SYS_READ			;rax = 0x2000003, needed for syscall
	syscall							;calls write function using syscall (rax is now error number or return value)
	jc		_return_error			;checks the carry flag, if it's active, there has been an error (and it's stocked in rax on macOS)
	ret								;returns rax if no error(return value of read syscall)

_return_error:
	push	rax
	call	___error
	pop		qword[rax]
	mov		rax, -1					;rax = -1
	ret			
