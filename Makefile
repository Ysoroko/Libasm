# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 16:15:11 by ysoroko           #+#    #+#              #
#    Updated: 2021/03/17 17:48:19 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	hello.s

OBJS		=	hello.o

NAME		=	libasm.a

LINK		=	ar rcs

NASM_LINK	=	ld -macosx_version_min 10.12 -lSYstem

EXECUTABLE	=	a.out

all: $(NAME)

compile:
		@nasm -f macho64 $(SRC)

$(NAME): compile
		$(LINK) $(NAME) $(OBJS)

run:	compile
		@$(NASM_LINK) $(OBJS) && ./a.out

clean:
		@rm -rf $(OBJS)

fclean:	clean
		@rm -rf $(NAME)
		@rm -rf $(EXECUTABLE)

re:		fclean all

.PHONY: all clean fclean re run