;Prototype in C: [char	*ft_strcpy(char *dst, const char *src)]
; returns dst

;rax	=	return value registry
;rdi	=	first argument registry
;rsi	=	second argument registry

;rcx	=	store value here
;rdx	=	store value here

;[rdi]	=	same as *rdi in C

global _ft_strcpy

_ft_strcpy:
	xor	r8, r8					;i index
	xor	r9, r9					;j index
	xor	r10, r10
	mov	rax, rdi				;store *dest in rax
	cmp	rdi, 0
	je	_return
	cmp	rsi, 0
	je	_return
	jmp	_copy

_copy:
	cmp	[rsi + r9], byte 0		;!if(src[j])
	je	_return
	mov	r10, [rsi + r9]
	mov	[rdi + r8], r10
	inc	r8
	inc	r9
	jmp	_copy



_return:
	ret