;Prototype in C: [int	ft_strcmp(char *a, char *b)]
;returns the difference between first two different chars in a & b

;rax	=	return value registry
;rdi	=	first argument registry
;rsi	=	second argument registry

;r8, r9, 10	=	scratch registers, used to store temporary data

;[rdi]	=	same as *rdi in C

global	_ft_strcmp

_ft_strcmp:
	xor		rax, rax					;rax = 0
	xor		r8, r8						;r8 = 0 (r8b (aka lower byte of r8) is used to store a char)
	xor		r9, r9						;r9 = 0 (r9b (aka lower byte of r9) is used to store a char)
	cmp		rdi, 0						;if (!str_a)
	je		_return_zero				;return (0);
	cmp		rsi, 0						;if (!str_b)
	je		_return_zero				;return (0);
	xor		r10, r10					;r10 = 0 (we use it as 'i' index here)
	jmp		_compare					;jump to compare function

_compare:
	mov		r8b, [rdi + r10]			;store the value of str_a[i] in r8b
	mov		r9b, [rsi + r10]			;store the value of str_b[i] in r9b
	cmp		r8b, 0						;if (!str_a[i])
	je		_compare_chars				;jump to compare_chars()
	cmp		r9b, 0						;if (!str_b[i])
	je		_compare_chars				;jump to compare_chars()
	cmp		r8, r9						;if (str_a[i] != str_b[i])
	jne		_compare_chars				;jump to compare_chars()
	inc		r10							;i++
	jmp		_compare					;jump back to the start of _count

_return_zero:
	ret									;returns rax (which is currently equal to 0)

_compare_chars:
	sub		r8, r9						;str_a[i] = str_a[i] - str_b[i];
	mov		rax, r8						;rax = str_a[i] (which is currently equal to str_a[i] - str_b[i])
	ret									;return rax
