/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:47:59 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/22 15:32:32 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

/*
** FT_PRINT_HEADE
** Simply prints the "LIBASM TESTER" header
*/

static void	ft_print_header(const char *f)
{
	printf(BOLDMAGENTA);
	printf("\n\n\n\n\n\n\n\n\n-------------------------------");
	printf("------------------------------\n\n");
	printf(COLOR_RESET);
	printf(BOLDYELLOW);
	printf("\t\t  %s \n\n", f);
	printf(BOLDMAGENTA);
	printf("-------------------------------");
	printf("------------------------------");
	printf(COLOR_RESET);
}

/*
** FT_PRINT_FUNCTION_START
** This function will print the function name in a line full of '-' characters
** BOLDCYAN color is used
** This is used purely as a cosmetic separator
*/

static void	ft_print_function_start(const char *f)
{
	printf(BOLDCYAN);
	printf("\n\n\n\n\n--------------------------");
	printf(BOLDMAGENTA);
	printf(" %s ", f);
	printf(BOLDCYAN);
	printf("------------------------\n\n");
	printf(COLOR_RESET);
}

static void	ft_print_result(int n)
{
	if (n)
	{
		printf(BOLDGREEN);
		printf("\t%s\n", "[OK]");
		printf(COLOR_RESET);
	}
	else
	{
		printf(BOLDRED);
		printf("\t%s\n", "[KO]");
		printf(COLOR_RESET);
	}
}
/*
** FT_PRINT_END_LINE
** This function will print a line full of '-' characters
** This is used purely as a cosmetic separator
*/

static void	ft_print_end_line(void)
{
	printf(BOLDCYAN);
	printf("\n-------------------------------");
	printf("------------------------------");
	printf(COLOR_RESET);
}

static void	ft_compare_results(char *type, char *a, char *b, int c, int d)
{
	if (!strcmp(type, "string"))
	{
		if (!(strcmp(a, b)))
			ft_print_result(1);
		else
			ft_print_result(0);
	}
	else if (!(strcmp(type, "int")))
	{
		if (c == d)
			ft_print_result(1);
		else
			ft_print_result(0);
	}
}

/*
** FT_STRLEN_TESTS
** This function will call and print all the tests related to ft_strlen
*/

static void	ft_strlen_tests(char *l, char *a, char *b)
{
	size_t	s;
	size_t	f;
	char	*x;
	char	*y;

	if (!(x = strdup("strlen: ")) || !(y = strdup("ft_strlen: ")))
		exit(EXIT_FAILURE);
	ft_print_function_start("FT_STRLEN");
	s = strlen("");
	f = ft_strlen("");
	printf("%-15s %-9s [%5lu] %-9s [%5lu]", "[EMPTY]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strlen(a);
	f = ft_strlen(a);
	printf("%-15s %-9s [%5lu] %-9s [%5lu]", "[!]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strlen(b);
	f = ft_strlen(b);
	printf("%-15s %-9s [%5lu] %-9s [%5lu]", "[o_O]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strlen(l);
	f = ft_strlen(l);
	printf("%-15s %-9s [%5lu] %-9s [%5lu]", "[LONG]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	ft_print_end_line();
}

/*
** FT_STRCMP_TESTS
** This function will call and print all the tests related to ft_strcmp
*/

static void	ft_strcmp_tests(char *l, char *a, char *b)
{
	int		s;
	int		f;
	char	*x;
	char	*y;

	if (!(x = strdup("strcmp: ")) || !(y = strdup("ft_strcmp: ")))
		exit(EXIT_FAILURE);
	ft_print_function_start("FT_STRCMP");
	s = strcmp("", "");
	f = ft_strcmp("", "");
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[EMPTY][EMPTY]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp("", b);
	f = ft_strcmp("", b);
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[EMPTY][o_O]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp(b, "");
	f = ft_strcmp(b, "");
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[o_O][EMPTY]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp(a, "");
	f = ft_strcmp(a, "");
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[!][EMPTY]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp("", a);
	f = ft_strcmp("", a);
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[EMPTY][!]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp(l, l);
	f = ft_strcmp(l, l);
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[LONG][LONG]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp(l, "");
	f = ft_strcmp(l, "");
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[LONG][EMPTY]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp("", l);
	f = ft_strcmp("", l);
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[EMPTY][LONG]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp(a, b);
	f = ft_strcmp(a, b);
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[!][o_O]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	s = strcmp(b, a);
	f = ft_strcmp(b, a);
	printf("%-15s %-9s [%5d] %-9s [%5d]", "[o_O][!]:", x, s, y, f);
	ft_compare_results("int", 0, 0, s, f);
	ft_print_end_line();
	free(x);
	free(y);
}

/*
** FT_STRCPY_TESTS
** This function will call and print all the tests related to ft_strcpy
*/
static void	ft_strcpy_tests(char *l, char *a, char *b)
{
	char	*s;
	char	*f;
	char	*x;
	char	*y;

	if (!(s = malloc(10000)) || !(f = malloc(10000)) ||
		(!(x = strdup("strcpy: "))) || (!(y = strdup("ft_strcpy: "))))
		exit(EXIT_FAILURE);
	ft_print_function_start("FT_STRCPY");
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[EMPTY]:", x, strcpy(s, ""),
														y, ft_strcpy(f, ""));
	ft_compare_results("string", s, f, 0, 0);
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[o_O]:", x, strcpy(s, b),
														y, ft_strcpy(f, b));
	ft_compare_results("string", s, f, 0, 0);
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[!]:", x, strcpy(s, a),
														y, ft_strcpy(f, a));
	ft_compare_results("string", s, f, 0, 0);
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[LONG]:", x, strcpy(s, l),
														y, ft_strcpy(f, l));
	ft_compare_results("string", s, f, 0, 0);
	ft_print_end_line();
	free(s);
	free(f);
	free(x);
	free(y);
}

/*
** FT_STRDUP_TESTS
** This function will call and print all the tests related to ft_strdup
*/
static void	ft_strdup_tests(char *l, char *a, char *b)
{
	char	*s;
	char	*f;
	char	*x;
	char	*y;

	if ((!(x = strdup("strdup: "))) || (!(y = strdup("ft_strdup: "))))
		exit(EXIT_FAILURE);
	ft_print_function_start("FT_STRDUP");
	if (!(s = strdup("")) || !((f = ft_strdup(""))))
		return ;
	f = ft_strdup("");
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[EMPTY]:", x, s, y, f);
	ft_compare_results("string", s, f, 0, 0);
	free(s);
	free(f);
	if (!(s = strdup(b)) || !((f = ft_strdup(b))))
		return ;
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[o_O]:", x, s, y, f);
	ft_compare_results("string", s, f, 0, 0);
	free(s);
	free(f);
	if (!(s = strdup(a)) || !((f = ft_strdup(a))))
		return ;
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[!]:", x, s, y, f);
	ft_compare_results("string", s, f, 0, 0);
	free(s);
	free(f);
	if (!(s = strdup(l)) || !((f = ft_strdup(l))))
		return ;
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[LONG]:", x, s, y, f);
	ft_compare_results("string", s, f, 0, 0);
	ft_print_end_line();
	free(s);
	free(f);
	free(x);
	free(y);
}

/*
** FT_INITIALIZE_STRINGS
** This function returns a malloc'd duplicate
*/

static void	ft_initialize_strings(char **l_str, char **str_a, char **str_b)
{
	if (!(*l_str = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
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
					Maecenas adipiscing ante non diam sodales hendrerit.")) ||
		!(*str_a = strdup("!")) || !(*str_b = strdup("o_O")))
		{
			exit(EXIT_FAILURE);
		}
}

static void	ft_run_tests(char *l, char *a, char *b)
{
	ft_print_header("LIBASM TESTER BY YSOROKO");
	ft_strlen_tests(l, a, b);
	ft_strcmp_tests(l, a, b);
	ft_strcpy_tests(l, a, b);
	ft_strdup_tests(l, a, b);
}

int			main(void)
{
	char	*long_string;
	char	*str_a;
	char 	*str_b;

	ft_initialize_strings(&long_string, &str_a, &str_b);
	ft_run_tests(long_string, str_a, str_b);
	return (1);
}