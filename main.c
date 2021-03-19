/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:47:59 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/19 11:11:01 by ysoroko          ###   ########.fr       */
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

/*
** OTHER USEFUL STUFF
** call ; calls another function (unlike jump it continues 
**			where it left off after executing the function)
** [ebx] ;same as *ebx in C
*/

static void	ft_initialize_strings(char **l_str, char **str_a, char **str_b)
{
	*l_str = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
					Sed non risus. Suspendisse lectus tortor \
					,dignissim sit amet, adipiscing nec, ultricies sed, dolor \
					Cras elementum ultrices diam. \
					Maecenas ligula massa, varius a, \
					semper congue, euismod non, mi. \
					Proin porttitor, orci nec nonummy molestie, \
					enim est eleifend mi, \
					non fermentum diam nisl sit amet erat. Duis semper. \
					Duis arcu massa, scelerisque vitae, consequat in, \
					pretium a, enim. Pellentesque congue. \
					Ut in risus volutpat libero pharetra tempor. \
					Cras vestibulum bibendum augue. \
					Praesent egestas leo in pede. \
					Praesent blandit odio eu enim. \
					Pellentesque sed dui ut augue blandit sodales. \
					Vestibulum ante ipsum primis in faucibus orci \
					luctus et ultrices posuere cubilia Curae \
					Aliquam nibh. \
					Mauris ac mauris sed pede pellentesque fermentum. \
					Maecenas adipiscing ante non diam sodales hendrerit.");
	*str_a = strdup("!");
	*str_b = strdup("o_O");
}

static void	ft_str_tests(char *l, char *a, char *b)
{
	printf("\n\n\n");
	printf(BOLDCYAN);
	printf("--------------------------FT_STRLEN--------------------------\n\n");
	printf(COLOR_RESET);
	//printf("[EMPTY]: strlen: [%lu] ft_strlen[%lu]\n", strlen(""), ft_strlen(""));
	printf("[!]: strlen: [%lu] ft_strlen[%lu]\n", strlen(a), ft_strlen(a));
	printf("[o_O]: strlen: [%lu] ft_strlen[%lu]\n", strlen(b), ft_strlen(b));
	printf("[LONG]: strlen: [%lu] ft_strlen[%lu]\n", strlen(l), ft_strlen(l));
	printf(BOLDCYAN);
	printf("\n------------------------------------------------------------\n\n\n");
	printf("--------------------------FT_STRCMP--------------------------\n\n");
	printf(COLOR_RESET);
	printf("[EMPTY][EMPTY]: strcmp: [%d] ft_strcmp[%d]\n", strcmp("", ""),
														ft_strcmp("", ""));
	printf("[EMPTY][o_O]: strcmp: [%d] ft_strcmp[%d]\n", strcmp("", b),
														ft_strcmp("", b));
	printf("[!][EMPTY]: strcmp: [%d] ft_strcmp[%d]\n", strcmp(a, ""),
														ft_strcmp(a, ""));
	printf("[LONG][LONG]: strcmp: [%d] ft_strcmp[%d]\n", strcmp(l, l),
														ft_strcmp(l, l));
	printf("[!][o_O]: strcmp: [%d] ft_strcmp[%d]\n", strcmp(a, b),
														ft_strcmp(a, b));
	printf("[o_O][!]: strcmp: [%d] ft_strcmp[%d]\n", strcmp(b, a),
														ft_strcmp(b, a));
	printf(BOLDCYAN);
	printf("\n------------------------------------------------------------\n\n\n");
}

int main(void)
{
	char	*long_string;
	char	*str_a;
	char 	*str_b;

	ft_initialize_strings(&long_string, &str_a, &str_b);
	ft_str_tests(long_string, str_a, str_b);
	return (1);
}