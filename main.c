/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:47:59 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/18 14:52:16 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

/*
** CALL CONVENTIONS:
**
** rax ; return value
**
** rdi ; 1st argument
** rsi ; 2nd argument
** rdx ; 3rd
** rcx ; 4th
** r8  ; 5th
*/

/*
** add/sub/mul/imul/div/idiv ; aritmetic (IMUL = signed, MUL = signed)
** inc/dec ; increment/decrement
** push ; write a value to the stack
** pop ; restore whatever is on the top of the stack into a register
** xchg ; exchange values of two variables
*/

int main(void)
{
	int	ans;

	
	ans = add(8, 3);
	printf("ANS: [%d]\n", ans);
	return (1);
}