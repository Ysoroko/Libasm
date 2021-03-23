/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:47:59 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/23 17:59:20 by ysoroko          ###   ########.fr       */
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

/*
** FT_INITIALIZE
** This function is used to initialize 
*/

static void	ft_initialize(char **a, char **b, char **c, char **d)
{
	if (a)
		*a = 0;
	if (b)
		*b = 0;
	if (c)
		*c = 0;
	if (d)
		*d = 0;
}

/*
** FT_FREE
** This function is used to free several strings and exit if required
** It is usually called when an error occurs
*/

static void	ft_free(char *a, char *b, char *c, char *d, int ex)
{
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	if (d)
		free(d);
	if (ex)
		exit(EXIT_FAILURE);
}

/*
** FT_COMPARE_RESULTS
** This funcion compares ints or chars depending on the first argument
** Then it calls ft_print_result which prints green [OK] or red [KO] on screen
*/

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

	ft_initialize(&x, &y, 0, 0);
	if (!(x = strdup("strlen: ")) || !(y = strdup("ft_strlen: ")))
		ft_free(x, y, 0, 0, 1);
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

	ft_initialize(&x, &y, 0, 0);
	if (!(x = strdup("strcmp: ")) || !(y = strdup("ft_strcmp: ")))
		ft_free(x, y, 0, 0, 1);
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
	ft_free(x, y, 0, 0, 0);
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

	ft_initialize(&x, &y, &s, &f);
	if (!(s = malloc(10000)) || !(f = malloc(10000)) ||
		(!(x = strdup("strcpy: "))) || (!(y = strdup("ft_strcpy: "))))
		ft_free(s, f, x, y, 1);
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
	ft_free(s, f, x, y, 0);
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

	ft_initialize(&x, &y, &s, &f);
	if ((!(x = strdup("strdup: "))) || !(y = strdup("ft_strdup: "))
			|| !(s = strdup("")) || !((f = ft_strdup(""))))
		ft_free(x, y, s, f, 1);
	ft_print_function_start("FT_STRDUP");
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
** FT_WRITE_TESTS
** This function will call and print all the tests related to ft_write
*/
static void	ft_write_tests(char *l)
{
	int		s_fd;
	int		f_fd;
	char	*x;
	char	*y;
	size_t	s_ret;
	size_t	f_ret;

	ft_initialize(&x, &y, 0, 0);
	ft_print_function_start("FT_WRITE");
	if ((s_fd = open("write", O_CREAT | O_RDWR | O_TRUNC, 77777)) == -1)
		return ;
	if ((f_fd = open("ft_write", O_CREAT | O_RDWR | O_TRUNC, 77777)) == -1)
		return ;
	if (!(x = strdup("write: ")) || (!(y = strdup("ft_write: "))))
		ft_free(x, y, 0, 0, 1);
	s_ret = write(s_fd, l, strlen(l));
	f_ret = ft_write(f_fd, l, strlen(l));
	printf("%-15s %-9s [%5li] %-9s [%5li]", "[LONG][FD OK]:", x, s_ret, y, f_ret);
	ft_compare_results("int", 0, 0, s_ret, f_ret);
	s_ret = write(-3, "ok", 2);
	f_ret = ft_write(-3, "ok", 2);
	printf("%-15s %-9s [%5li] %-9s [%5li]", "[WRONG FD]:", x, s_ret, y, f_ret);
	ft_compare_results("int", 0, 0, s_ret, f_ret);
	s_ret = write(1, "H", 1);
	f_ret = ft_write(1, "I", 1);
	printf("%-13s %-9s [%5li] %-9s [%5li]", "[OUTPUT FD]:", x, s_ret, y, f_ret);
	ft_compare_results("int", 0, 0, s_ret, f_ret);
	s_ret = write(0, "H", 1);
	f_ret = ft_write(0, "I", 1);
	printf("%-13s %-9s [%5li] %-9s [%5li]", "[INPUT FD]:", x, s_ret, y, f_ret);
	ft_compare_results("int", 0, 0, s_ret, f_ret);
	ft_free(x, y, 0, 0, 0);
	close(s_fd);
	close(f_fd);
	ft_print_end_line();
}

/*
** FT_READ_TESTS
** This function will call and print all the tests related to ft_write
*/
static void	ft_read_tests(char *l)
{
	int		s_fd;
	int		f_fd;
	char	*x;
	char	*y;
	char	*s;
	char	*f;
	size_t	s_ret;
	size_t	f_ret;

	ft_initialize(&x, &y, &s, &f);
	ft_print_function_start("FT_WRITE");
	if ((s_fd = open("write", O_RDONLY)) == -1)
		return ;
	if ((f_fd = open("ft_write", O_RDONLY)) == -1)
		return ;
	if (!(s = malloc(1000)) || !(f = malloc(1000)) ||
		(!(x = strdup("read: "))) || (!(y = strdup("ft_read: "))))
		ft_free(x, y, s, f, 1);

	
	s_ret = read(s_fd, s, strlen(l));
	read(s_fd, s, strlen(l));
	s[strlen(l) + 1] = 0;
	f_ret = ft_read(f_fd, f, strlen(l));
	read(f_fd, f, strlen(l));
	f[strlen(l) + 1] = 0;
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[LONG][FD OK]:", x, s, y, f);
	ft_compare_results("string", s, f, 0, 0);
	printf("%-15s %-9s [%5li] %-9s [%5li]", "[LONG][FD OK]:", x, s_ret, y, f_ret);
	ft_compare_results("int", 0, 0, s_ret, f_ret);
	s_ret = read(-3, s, 2);
	f_ret = ft_read(-3, f, 2);
	printf("%-15s %-9s [%5li] %-9s [%5li]", "[WRONG FD]:", x, s_ret, y, f_ret);
	ft_compare_results("int", 0, 0, s_ret, f_ret);
	s_ret = read(1, s, 1);
	f_ret = ft_read(1, f, 1);
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[OUTPUT FD]:", x, s, y, f);
	ft_compare_results("string", s, f, 0, 0);
	printf("%-13s %-9s [%5li] %-9s [%5li]", "[OUTPUT FD]:", x, s_ret, y, f_ret);
	ft_compare_results("int", 0, 0, s_ret, f_ret);
	s_ret = read(0, s, 1);
	f_ret = read(0, f, 1);
	printf("%-15s %-9s [%5.5s] %-9s [%5.5s]", "[INPUT FD]:", x, s, y, f);
	ft_compare_results("string", s, f, 0, 0);
	printf("%-13s %-9s [%5li] %-9s [%5li]", "[INPUT FD]:", x, s_ret, y, f_ret);
	ft_compare_results("int", 0, 0, s_ret, f_ret);
	ft_free(s, f, x, y, 0);
	close(s_fd);
	close(f_fd);
	ft_print_end_line();
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
	ft_write_tests(l);
	ft_read_tests(l);
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