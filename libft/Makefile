# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 19:43:41 by fecunha           #+#    #+#              #
#    Updated: 2023/07/21 19:43:42 by fecunha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c ft_tolower.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_calloc.c ft_atoi.c ft_split.c \
	   ft_strdup.c ft_substr.c ft_putnbr_fd.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_itoa.c \
	   ft_striteri.c ft_printf.c ft_put_char.c ft_put_string.c ft_put_pointer.c ft_put_number.c \
	   ft_put_unsigned_int.c ft_put_hexa.c \

OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror 
CC = cc
AR = ar rc
NAME = libft.a
RM = rm -rf
GNL = make -C gnl && cp gnl/get_next_line.a $(NAME)

.c.o: 
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)  

$(NAME): ${OBJS}  
	@$(GNL)
	@${AR} ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}
	@make -C gnl clean
fclean: clean
	@${RM} ${NAME}
	@make -C gnl fclean
re:	fclean all


.PHONY: all clean fclean re gnl
