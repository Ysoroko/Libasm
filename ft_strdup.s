extern	_ft_strlen
extern	_ft_strcpy
extern	_malloc

;Prototype in C: [char	*ft_strdup(const char *src)]
;Mallocs a new string, copies *src to its address and returns this address

;rax	=	return value registry
;rdi	=	first argument registry

;r8, r9, 10	=	scratch registers, used to store temporary data

;[rdi]	=	same as *rdi in C

global	_ft_strdup

_ft_strdup:
	cmp		rdi, 0					;if(!src)
	je		_return_null			;return(NULL)
	push	rdi						;save rdi (argument) value on the stack to retrieve it later
	jmp		_find_length			;jump to _find_length function

_find_length:
	call	_ft_strlen				;calls ft_strlen(rdi); after the call [rax] becomes the length of the string
	inc		rax						;rax++
	mov		rdi, rax				;rdi = the length of the string + 1 (= setup for calling malloc below)
	jmp		_allocate_memory		;jump to _allocate_memory function

_allocate_memory:
	call	_malloc					;calls malloc(strlen(src) + 1). After the call [rax] becomes the new pointer
	cmp		rax, 0					;if (!(malloc(strlen(src) + 1)))
	je		_return_null			;return (NULL)
	mov		rdi, rax				;rdi = the pointer the newly allocated string (setup for strcpy)
	jmp		_copy

;char	*ft_strcpy(char *dst, const char *src)
;rdi must be set up to point to the newly allocated string
;rsi must be retrieved on the stack (see "push" command above)
_copy:
	pop		rsi						;retrieve initial rdi value on the stack (rdi = strdup argument)
	call	_ft_strcpy				;strcpy((malloc pointer), (strdup argument))
	ret								;return rax (the return value of strcpy)

_return_null:
	xor		rax, rax				;rax = 0
	ret								;return rax