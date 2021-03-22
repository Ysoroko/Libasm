;Prototype in C: [char	*ft_strcpy(char *dst, const char *src)]
;Returns *dst argument

;rax	=	return value registry
;rdi	=	first argument registry
;rsi	=	second argument registry

;r8, r9, 10	=	scratch registers, used to store temporary data

;[rdi]	=	same as *rdi in C

global _ft_strcpy

_ft_strcpy:
	xor	r8, r8					;i index
	xor	r9, r9					;j index
	xor	r10, r10				;used for storing src[j]
	mov	rax, rdi				;store *dest in rax
	cmp	rdi, 0					;if(!dst)
	je	_return_dest			;return(NULL)
	cmp	rsi, 0					;if(!src)
	je	_return_dest			;return(dst)
	jmp	_copy					;jump to _copy function

_copy:
	cmp	[rsi + r9], byte 0		;!if(src[j])
	je	_finish					;copy ended, put a '\0' and return *dest
	mov	r10, [rsi + r9]			;else{ r10 = src[j]; }
	mov	[rdi + r8], r10			;dst[i] = r10
	inc	r8						;i++
	inc	r9						;j++
	jmp	_copy					;go back to the start of _copy function

_finish:
	mov	[rdi + r8], byte 0		;dst[j] = '\0'
	ret							;return (*dest)

_return_dest:
	ret							;return *dst