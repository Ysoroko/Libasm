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
	xor		r8, r8						;r8 = 0
	xor		r9, r9						;r9 = 0
	cmp		rdi, 0						;if (!str_a)
	je		_return_zero				;return (0);
	cmp		rsi, 0						;if (!str_b)
	je		_return_zero				;return (0);
	xor		r10, r10					;r10 = 0 (we use it as 'i' index here)
	jmp		_compare					;jump to compare function

_compare:
	mov		r8b, [rdi + r10]			;store the value of str_a[i] in r8d
	mov		r9b, [rsi + r10]			;store the value of str_b[i] in r9d
	cmp		r8b, 0						;if (!str_a[i])
	je		_compare_chars				;compare_chars()
	cmp		r9b, 0						;if (!str_b[i])
	je		_compare_chars				;compare_chars()
	cmp		r8, r9
	jne		_compare_chars						;if (str_a[i] != str_b[i])
	inc		r10							;i++
	jmp		_compare					;jump back to the start of _count

_return_zero:
	ret									;returns rax (which is currently equal to 0)

_compare_chars:
	sub		r8, r9
	mov		rax, r8						;if (str_a[i] == str_b[i]) { return (0); }
	ret									;if (str_a[i] > str_b[i]) { return (1); }
										;if (str_a[i] < str_b[i]) { return (-1); }
	
_return_one:
	inc		rax							;rax++
	ret									;return rax

_return_minus_one:
	dec		rax							;rax--
	ret									;return rax
