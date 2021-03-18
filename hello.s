;CALL CONVENTIONS:
;rax ; return value
;rdi ; 1st argument
;rsi ; 2nd argument
;rdx ; 3rd
;rcx ; 4th
;r8  ; 5th


SECTION .data
	x:	.int	19
	y:	.int	2
	z:	.int	-1

SECTION .text
	global _add

_add:
	movabs	rax, x		;movabs moves a variable into a register rax
	mov		rax, rbx	;

	movabs	rax, y
	mov		rcx, rax
	
	movabs	rax, z
	mov		rax, rdx


	ret
