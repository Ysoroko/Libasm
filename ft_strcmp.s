;Prototype in C: [int	ft_strcmp(char *a, char *b)]
; returns -1 / 0 / 1 if a < b / a = b / a > b

;rax	=	return value registry
;rdi	=	first argument registry
;rsi	=	second argument registry

;[rdi]	=	same as *rdi in C

global	_ft_strcmp

_ft_strcmp:
	xor		rax, rax					;rax = 0
	cmp		rdi, 0						;compare 1st argument to a NULL pointer
	je		_null_string				;if 1st argument is a NULL pointer, jump to null_string function
	cmp		rsi, 0						;compare 2nd argument to a NULL pointer
	je		_null_string				;if 2nd argument is a NULL pointer, jump to null_string function
	call	_count						;call count function

_count:
	cmp		[rdi + rax], byte 0			;if (!rdi[i])
	jne		_different_chars			;different_chars()
	cmp		[rsi + rax], byte 0			;if (!rsi[i])
	jne		_different_chars			;different_chars()
	cmp		[rdi + rax], [rsi + rax]	;if (a[i] != b[i])
	jne		_different_chars			;if (!str[i]) {return (i);}
	inc		rax							;rax++
	jmp		_count						;jump back to the start of _count

_null_string:
	ret			;returns rax (which is currently equal to 0)

_different_chars:
	ret			;returns rax (which is currently equal to strlen)