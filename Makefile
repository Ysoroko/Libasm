# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 16:15:11 by ysoroko           #+#    #+#              #
#    Updated: 2021/03/23 13:20:10 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_strlen.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_strdup.s \
				ft_write.s

OBJS		=	$(SRC:.s=.o)

NAME		=	libasm.a

FLAGS		=	-Wall -Wextra -Werror

LINK		=	ar rcs

ASM			=	-L. -lasm

EXECUTABLE	=	a.out

COMPILE		=	nasm -f macho64

# Rule to compile .s files into .o files
.s.o:
	@$(COMPILE) $<

all: $(NAME)

$(NAME): $(OBJS)
		@$(LINK) $(NAME) $(OBJS)

test:	$(NAME)
		@gcc $(ASM) $(FLAGS) $(NAME) main.c && ./$(EXECUTABLE) ; \
		make fclean

wtest: $(NAME)
		gcc $(ASM) $(NAME) main.c && ./$(EXECUTABLE); \
		make fclean

clean:
		@rm -rf $(OBJS)

fclean:	clean
		@rm -rf $(NAME) \
		@rm -rf $(EXECUTABLE) \

aclean: clean
		@rm -rf ft_write \
		@rm -rf write

re:		fclean all

.PHONY: all clean fclean re test