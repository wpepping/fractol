SRCS = fractol.c mandelbrot.c utils.c events.c crimage.c complex.c julia.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = fractol

CFLAGS = -Wall -Werror -Wextra
INCLUDES = -L$(LIB_FOLDER) -l$(LIB_COMPILE) -lm -lX11 -lXext -lmlx

all: $(NAME)
bonus: $(NAME_BONUS)


$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
