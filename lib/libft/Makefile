# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 14:25:23 by mmeuric           #+#    #+#              #
#    Updated: 2025/05/14 00:25:53 by urlooved &&      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c \
		  ft_memccpy.c ft_memmove.c ft_memchr.c\
		  ft_memcmp.c ft_strlen.c ft_isalpha.c\
		  ft_isdigit.c ft_isalnum.c ft_isalnum.c\
		  ft_isascii.c ft_isprint.c ft_toupper.c\
		  ft_tolower.c ft_strchr.c ft_strrchr.c\
		  ft_strncmp.c ft_strlcpy.c ft_strlcat.c\
		  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
		  ft_itoa.c	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
		  ft_putendl_fd.c ft_putnbr_fd.c

BONUS			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			  		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
			  		ft_lstmap.c

OBJS			=	${SRCS:.c=.o}

OBJSBONUS		= 	${BONUS:.c=.o}

NAME			=	libft.a

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -I.

RM				=	rm -f



all:		${NAME}

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		@echo "compiling libft" 
		ar -rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJSBONUS}
		@echo "compiling libft bonus"
		ar -rcs ${NAME} ${OBJS} ${OBJSBONUS}

clean:
	@echo "cleaning libft"
	@${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean			
		@${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
