##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	=	./print/flags.c \
		./print/my_printers.c \
		./print/my_printf.c \
		./src/epur_str.c \
		./src/get_next_line.c \
		./src/list.c \
		./src/main.c \
		./src/parcing.c \
		./src/path.c \
		./src/searcher.c \
		./src/utility.c \
		./src/call_all.c \
		./src/builtins.c \
		./src/exec.c	\
		./src/utility_bis.c \
		./src/setenv.c	\
		./src/util_setenv.c \
		./src/unsetenv.c	\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
