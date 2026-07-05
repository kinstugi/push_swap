CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c helper_funcs_1.c helper_funcs_2.c helper_funcs_3.c \
		dl_list_utils.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap

all: $(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all
debug: CFLAGS += -g
debug: re
$(NAME): all