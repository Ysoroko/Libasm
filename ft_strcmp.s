;Prototype in C: [int	ft_strcmp(char *a, char *b)]
; returns -1 / 0 / 1 if a < b / a = b / a > b

;rax	=	return value registry
;rdi	=	first argument registry
;rsi	=	second argument registry

;rcx	=	store value here
;rdx	=	store value here

;[rdi]	=	same as *rdi in C

global	_ft_strcmp

_ft_strcmp:
	xor		rax, rax					;rax = 0
	xor		rcx, rcx
	xor		rdx, rdx
	cmp		rdi, 0						;compare 1st argument to a NULL pointer
	je		_null_string				;if 1st argument is a NULL pointer, jump to null_string function
	cmp		rsi, 0						;compare 2nd argument to a NULL pointer
	je		_null_string				;if 2nd argument is a NULL pointer, jump to null_string function
	jmp		_compare					;jump to compare function

_compare:
	mov		rcx, [rdi + rax]			;store the value of rdi[r10] in r8
	mov		rdx, [rsi + rax]			;store the value of rsi[r10] in r9
	cmp		rcx, byte 0					;if (!r8[i])
	je		_compare_chars				;end_of_string()
	cmp		rdx, byte 0					;if (!r9[i])
	je		_compare_chars				;end_of_string()
	cmp		rcx, rdx					;if (r8[i] != r9[i])
	jne		_compare_chars				;end_of_string()
	inc		rax							;++
	jmp		_compare					;jump back to the start of _count

_null_string:
	ret									;returns rax (which is currently equal to 0)

_compare_chars:
	xor		rax, rax
	cmp		rcx, rdx
	je		_null_string
	jg		_return_one
	jl		_return_minus_one
	
_return_one:
	inc		rax
	ret

_return_minus_one:
	dec		rax
	ret
