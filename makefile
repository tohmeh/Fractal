CC = gcc
CFLAGS = -Ofast -flto -march=native -funroll-loops -fno-plt -fstrict-aliasing -Wall -Wextra -Werror -I./minilibx-linux -g
LDFLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm

NAME = fractol
SRCSDIR = src
OBJDIR = obj
LIBFT_DIR = LIBFT
LIBFT_LIB = $(LIBFT_DIR)/lib/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_DIR = minilibx-linux

SRCS = $(SRCSDIR)/fractol.c \
       $(SRCSDIR)/complex.c \
       $(SRCSDIR)/mandelbrot_set.c \
       $(SRCSDIR)/mnk_events.c \
       $(SRCSDIR)/mnk_events_utils.c \
       $(SRCSDIR)/julia_set.c \
       $(SRCSDIR)/mnk_events_utils2.c \
       $(SRCSDIR)/input_parsing.c \
       $(SRCSDIR)/initialise_fractal_struct.c \
       $(SRCSDIR)/draw.c \

OBJS = $(SRCS:$(SRCSDIR)/%.c=$(OBJDIR)/%.o)

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(OBJS) $(LIBFT_LIB) $(LDFLAGS) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
