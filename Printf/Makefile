NAME = libftprintf.a
SRCS =	./src/ft_printf.c \
		./src/ft_check_base.c \
		./src/ft_check_c_s_d_i_u.c \
		./src/ft_check_ptr_pct_x_X.c \

OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
INCDIR	= ./includes

all:	${NAME}

$(NAME): ${OBJS}
		ar rcs $(NAME) $(OBJS)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		$(RM) $(OBJS)

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re .c.o
