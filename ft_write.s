;ssize_t write(int fd, const void *str, size_t n);
;rdi	=	1st argument registry (fd)
;rsi	=	2nd argument registry (str)
;rdx	=	3rd argument (size)
SYS_WRITE equ 1	;define a macro for SYS_WRITE

global	_ft_write

_ft_write:
	call	_ft_check_for_errors	;calls ft_check_for_errors()
	cmp		rax, -1					;if (ft_check_for_errors() == -1)
	je		_return_minus_one		;call return_minus_one()
	mov		rax, SYS_WRITE			;rax = 1


_ft_check_for_errors:
	cmp		rdi, 0
	jl		_return_minus_one
	cmp		rsi, 0
	jl		_return_minus_one
	cmp		rdx, 0
	jl		_return_minus_one

_return_minus_one:
	xor		rax,rax
	dec		rax
	ret