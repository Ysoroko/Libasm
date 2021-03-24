;ssize_t write(int fd, const void *str, size_t n);
;rdi	=	1st argument registry (fd)
;rsi	=	2nd argument registry (str)
;rdx	=	3rd argument (size)
extern	___error					;allows us to call external function error()
SYS_WRITE equ 0x2000004				;#define SYS_WRITE 0x2000004

global	_ft_write

_ft_write:
	mov		rax, SYS_WRITE			;rax = 0x2000004, for syscall
	syscall							;calls write function using syscall (rax is now the error number)
	jc		_return_error			;checks the carry flag, if it's active, there has been an error (and it's stocked in rax on macOS)
	ret								;returns rax if no error(return value of write syscall)

_return_error:
	push	rax						;save rax on the stack
	call	___error				;call error function (which returns the pointer to the variable holding errno)
	pop		qword[rax]				;retrieve the rax value on the stack and use it to set errno (qword simply specifies the size 8 bytes)
	mov		rax, -1					;rax = -1
	ret								;return rax