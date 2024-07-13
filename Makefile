SRCS = fractol.c mandelbrot.c utils.c events.c crimage.c complex.c julia.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

LIB_FOLDER = minilibx
LIB_ARCHIVE = libmlx.a
LIB_INCLUDE = mlx

CFLAGS = -Wall -Werror -Wextra
INCLUDES = -L$(LIB_FOLDER) -l$(LIB_INCLUDE) -lm -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_FOLDER)
	cc $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) clean -C $(LIB_FOLDER)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
