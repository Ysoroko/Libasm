/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:24:50 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/19 14:40:43 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
int		ft_strcmp(char *a, char *b);
char	*ft_strcpy(char *dest, char *src);

/*
** COLORS
*/

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#endif


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

/*
** OTHER USEFUL STUFF
** call ; calls another function (unlike jump it continues 
**			where it left off after executing the function)
** [ebx] ;same as *ebx in C
*/
