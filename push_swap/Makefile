# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:14:53 by aal-mokd          #+#    #+#              #
#    Updated: 2024/08/15 18:20:55 by aal-mokd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = ft_printf/libftprintf.a

SRCS  = src/main.c src/push_algorithme.c src/push.c src/push_swap.c src/push_swap_next1.c src/push_swap_utils0_atoi.c src/push_swap_utils1_s_p.c src/push_swap_utils2_rotate.c src/push_swap_utils3_revers_rotate.c src/push_utils.c src/rotate.c src/sort_sa.c src/sort_sb.c

OBJS = ${SRCS:.c=.o}


CC					= gcc
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror

all: $(NAME) 

$(NAME):	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

$(LIB):
			@make -C ./ft_printf

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:	
		@make clean -C ./ft_printf
		${RM} ${OBJS}

fclean: clean
		${RM} ${LIB}
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
