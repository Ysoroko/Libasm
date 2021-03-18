;int	ft_strlen(char *str)

;rax	=	return value
;rdi	=	first argument

global	_ft_strlen

;rax ; return value
;rdi ; 1st argument

_ft_strlen:
	xor	rax, rax	;initialize rax at 0
	cmp	rdi, 0		;compare the argument to a NULL pointer
	je	_null_string	;if the argument is a NULL pointer, jump to null_string function
	

_null_string:
	return			;returns rax (which is currently equals to 0)