SRCS = fractol.c mandelbrot.c utils.c events.c color_image.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = fractol

LIB_FOLDER = minilibx
LIB_NAME = libmlx.a
LIB_COMPILE = mlx

CFLAGS = -Wall -Werror -Wextra -lm -lX11 -lXext

all: $(NAME)
bonus: $(NAME_BONUS)

$(LIB_FOLDER)/$(LIB_NAME):
	$(MAKE) -C $(LIB_FOLDER)

$(NAME): $(OBJS) $(LIB_FOLDER)/$(LIB_NAME)
	cc $(CFLAGS) $(OBJS) -L$(LIB_FOLDER) -l$(LIB_COMPILE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) clean -C $(LIB_FOLDER)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
