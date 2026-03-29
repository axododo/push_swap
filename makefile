NAME = push_swap

CC = cc
# FIX: ajout de -I. pour que tous les .c puissent utiliser #include "push.h"
CFLAGS = -Wall -Wextra -Werror -g -I.

SRCS = main.c parse.c pars2.c ft_split.c \
       move/push.c move/rotate.c move/swap.c move/rev_rot.c \
       algo/mini.c algo/k_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
