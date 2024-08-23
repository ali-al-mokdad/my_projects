# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:14:53 by aal-mokd          #+#    #+#              #
#    Updated: 2024/08/23 17:03:58 by aal-mokd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIB = lib/ft_printf/libftprintf.a

SRCS  = src/pipex_main.c src/pipex_utils.c

pipex_BONUS = 

OBJS = ${SRCS:.c=.o}
BONUS_OBJ = $(pipex_BONUS:.c=.o)


CC					= gcc
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror

all: $(NAME) 

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB)  -o checker


$(NAME):	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

$(LIB):
			@make -C ./lib/ft_printf

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:	
		@make clean -C ./lib/ft_printf
		${RM} ${OBJS}
		${RM} $(BONUS_OBJ)

fclean: clean
		${RM} ${LIB}
		${RM} ${NAME}
		rm -rf checker

re: fclean all

.PHONY: all bonus clean fclean re
