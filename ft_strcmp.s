;Prototype in C: [int	ft_strcmp(char *a, char *b)]
; returns -1 / 0 / 1 if a < b / a = b / a > b

;rax	=	return value registry
;rdi	=	first argument registry
;rsi	=	second argument registry

;r8, r9, 10	=	scratch registers, used to store temporary data

;[rdi]	=	same as *rdi in C

global	_ft_strcmp

_ft_strcmp:
	xor		rax, rax					;rax = 0
	cmp		rdi, 0						;if (!str_a)
	je		_return_zero				;return (0);
	cmp		rsi, 0						;if (!str_b)
	je		_return_zero				;return (0);
	xor		r10, r10					;r10 = 0 (we use it as 'i' index here)
	jmp		_compare					;jump to compare function

_compare:
	mov		r8b, [rdi + r10]			;store the value of str_a[i] in r8
	mov		r9b, [rsi + r10]			;store the value of str_b[i] in r9
	cmp		r8b, byte 0					;if (!str_a[i])
	je		_compare_chars				;compare_chars()
	cmp		r9b, byte 0					;if (!str_b[i])
	je		_compare_chars				;compare_chars()
	cmp		r8b, r9b					;if (str_a[i] != str_b[i])
	jne		_compare_chars				;compare_chars()
	inc		r10							;i++
	jmp		_compare					;jump back to the start of _count

_return_zero:
	ret									;returns rax (which is currently equal to 0)

_compare_chars:
	je		_return_zero				;if (str_a[i] == str_b[i]) { return (0); }
	jg		_return_one					;if (str_a[i] > str_b[i]) { return (1); }
	jl		_return_minus_one			;if (str_a[i] < str_b[i]) { return (-1); }
	
_return_one:
	inc		rax							;rax++
	ret									;return rax

_return_minus_one:
	dec		rax							;rax--
	ret									;return rax
