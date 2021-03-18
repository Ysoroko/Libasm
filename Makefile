# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 16:15:11 by ysoroko           #+#    #+#              #
#    Updated: 2021/03/18 15:15:29 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_strlen.s

OBJS		=	ft_strlen.o

NAME		=	libasm.a

FLAGS		=	-Wall -Wextra -Werror

LINK		=	ar rcs

ASM			=	-L. -lasm

INCLUDE		= include/

NASM_LINK	=	ld -macosx_version_min 10.12 -lSYstem

EXECUTABLE	=	a.out

COMPILE		=	nasm -f macho64

all: $(NAME)

compile:
		@$(COMPILE) $(SRC)

$(NAME): compile
		$(LINK) $(NAME) $(OBJS)

run:	compile
		@$(NASM_LINK) $(OBJS) && ./$(EXECUTABLE); \
		make fclean

test:	$(NAME)
		gcc $(ASM) $(FLAGS) $(NAME) main.c && ./$(EXECUTABLE); \
		make fclean


clean:
		@rm -rf $(OBJS)

fclean:	clean
		@rm -rf $(NAME)
		@rm -rf $(EXECUTABLE)

re:		fclean all

.PHONY: all clean fclean re run