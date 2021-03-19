;Prototype in C: [int	ft_strcmp(char *a, char *b)]
; returns -1 / 0 / 1 if a < b / a = b / a > b

;rax	=	return value registry
;rdi	=	first argument registry
;rsi	=	second argument registry

;[rdi]	=	same as *rdi in C

global	_ft_strcmp

_ft_strcmp:
	xor		rax, rax					;rax = 0
	xor		r10, r10					;r10 = 0
	cmp		rdi, 0						;compare 1st argument to a NULL pointer
	je		_null_string				;if 1st argument is a NULL pointer, jump to null_string function
	cmp		rsi, 0						;compare 2nd argument to a NULL pointer
	je		_null_string				;if 2nd argument is a NULL pointer, jump to null_string function
	jmp		_compare					;jump to compare function

_compare:
	mov		r8, [rdi + r10]				;store the value of rdi[rax] in r8
	mov		r9, [rsi + r10]				;store the value of rsi[rax] in r9
	cmp		r8, byte 0					;if (!rdi[i])
	je		_compare_chars				;end_of_string()
	cmp		r9, byte 0					;if (!rsi[i])
	je		_compare_chars				;end_of_string()
	cmp		r8, r9						;if (a[i] != b[i])
	jne		_compare_chars				;end_of_string()
	inc		r10							;r10++
	jmp		_compare					;jump back to the start of _count

_null_string:
	ret									;returns rax (which is currently equal to 0)

_compare_chars:
	cmp		r8, r9
	je		_null_string
	cmp		r8, r9
	jg		_return_one
	cmp		r8, r9
	jl		_return_minus_one
	
_return_one:
	inc		rax
	ret

_return_minus_one:
	dec		rax
	ret
