/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:24:50 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/23 11:45:17 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <mach/error.h>

/*
** PROTOTYPES
*/

size_t	ft_strlen(char *str);
int		ft_strcmp(char *a, char *b);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *src);
ssize_t	ft_write(int fd, const void *str, size_t n);

/*
** COLORS
*/

#define COLOR_RESET   "\x1b[0m"

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
