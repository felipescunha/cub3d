SRCS = get_next_line.c \
	   get_next_line_utils.c 
	  # get_next_line_bonus.c \
	  # get_next_line_utils_bonus.c \

OBJS = ${SRCS:.c=.o}

#HEADER_GNL_BONUS = ./get_next_line_bonus.h
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rc
NAME = get_next_line.a
RM = rm -rf

.c.o: 
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@${AR} ${NAME} ${OBJS}

all: $(NAME)

clean:
	@${RM} ${OBJS}
	
fclean: clean
	@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re 
