;Prototype in C: [int	ft_strlen(char *str)]
;Returns the length of the string argument (doesn't count '\0')

;rax	=	return value registry
;rdi	=	first argument registry

;[rdi]	=	same as *rdi in C

global	_ft_strlen

_ft_strlen:
	xor		rax, rax				;rax = 0
	cmp		rdi, 0					;compare the argument to a NULL pointer
	je		_null_string			;if the argument is a NULL pointer, jump to null_string function
	jmp		_count					;call count function

_count:
	cmp		[rdi + rax], byte 0		;compare str[i] to '\0'
	je		_reached_the_end		;if (!str[i]) {return (i);}
	inc		rax						;rax++
	jmp		_count					;jump back to the start of _count

_null_string:
	ret								;returns rax (which is currently equal to 0)

_reached_the_end:
	ret								;returns rax (which is currently equal to strlen)
