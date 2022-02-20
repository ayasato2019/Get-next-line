# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 23:02:32 by aysato            #+#    #+#              #
#    Updated: 2022/01/30 10:35:18 by aysato           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_split.c \

BONUS = ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstdelone.c \


OBJS = ${SRCS:.c=.o}
OBJS_B = ${BONUS:.c=.o}
CC		= cc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJS += $(OBJS_B)
endif

all:	${NAME}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus:
		make WITH_BONUS=1
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		${RM} ${OBJS} ${OBJS_B}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re .c.o bonus
