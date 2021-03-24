;ssize_t write(int fd, const void *str, size_t n);
;rdi	=	1st argument registry (fd)
;rsi	=	2nd argument registry (str)
;rdx	=	3rd argument (size)
extern	___error					;allows us to call external function error()
SYS_READ equ 0x2000003				;#define SYS_READ 0x2000003

global	_ft_read

_ft_read:
	mov		rax, SYS_READ			;rax = 0x2000003, needed for syscall
	syscall							;calls write function using syscall (rax becomes the error number or return value after syscall)
	jc		_return_error			;checks the carry flag, if it's active, there has been an error (and it's stocked in rax on macOS)
	ret								;returns rax if no error(return value of read syscall)

_return_error:
	push	rax						;save rax on the stack
	call	___error				;call error function (which returns the pointer to the variable holding errno)
	pop		qword[rax]				;retrieve the rax value on the stack and use it to set errno. qword specifies the size(8 bytes)
	mov		rax, -1					;rax = -1
	ret								;return rax